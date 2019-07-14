#pragma once

#include "kvasir/sfr/action_traits.hpp"
#include "kvasir/sfr/exec.hpp"

#include "kvasir/mpl/mpl.hpp"

#include <type_traits>

namespace kvasir::sfr
{

namespace detail
{

    // in order to track the input actions after they have been re-ordered and
    // merged, we add an index to any operation that will require this tracking
    template <typename TAction, typename... TInputs>
    struct indexed_action
    {
        using action = TAction;
    };

    template <typename TAction, typename TIndex>
    struct make_indexed_action_impl;
    template <typename TAddress, typename TActionType, typename TIndex>
    struct make_indexed_action_impl<action<TAddress, TActionType>, TIndex>
    {
        using TAction = action<TAddress, TActionType>;
        using type = indexed_action<TAction>;
    };
    template <typename TAddress, uint32_t Mask, uint32_t Data, typename TIndex>
    struct make_indexed_action_impl<action<TAddress, write_action<Mask, Data>>, TIndex>
    {
        using TAction = action<TAddress, write_action<Mask, Data>>;
        using type = indexed_action<TAction, TIndex>;
    };
    template <typename TAction, typename TIndex>
    using make_indexed_action = typename make_indexed_action_impl<TAction, TIndex>::type;

    // each of the actions is sorted by the corresponding register address,
    // which serves as a precursor to merging and allows for more efficient
    // read/write with offset
    template <typename T, typename U>
    struct address_less_than;
    template <typename TAddr1, typename TActionType1, typename TAddr2, typename TActionType2>
    struct address_less_than<action<TAddr1, TActionType1>, action<TAddr2, TActionType2>>
        : mpl::bool_<(TAddr1::value < TAddr2::value)>
    {
    };
    template <typename TAction1, typename... TIndex1, typename TAction2, typename... TIndex2>
    struct address_less_than<indexed_action<TAction1, TIndex1...>,
                             indexed_action<TAction2, TIndex2...>>
        : address_less_than<TAction1, TAction2>
    {
    };

    // once the register accesses are sorted, merge them into composite actions
    // which perform the equivalent operations
    // default
    template <typename TRegisters, typename TRet = mpl::list<>>
    struct merge_actions_impl;
    // none processed
    template <typename TNext, typename... Ts>
    struct merge_actions_impl<mpl::list<TNext, Ts...>, mpl::list<>>
        : merge_actions_impl<mpl::list<Ts...>, mpl::list<TNext>>
    {
    };
    // merge non-indexed, compile-time writes
    template <typename TAddress, uint32_t Mask1, uint32_t Value1, uint32_t Mask2, uint32_t Value2,
              typename... Ts, typename... Us>
    struct merge_actions_impl<
        mpl::list<action<TAddress, write_literal_action<Mask1, Value1>>, Ts...>,
        mpl::list<action<TAddress, write_literal_action<Mask2, Value2>>, Us...>>
        : merge_actions_impl<
              mpl::list<Ts...>,
              mpl::list<action<TAddress, write_literal_action<Mask1 | Mask2, Value1 | Value2>>>>
    {
        static_assert((Mask1 & Mask2) == 0,
                      "un-sequenced writes cannot be performed to the same field");
    };
    // merge indexed, compile-time writes
    template <typename TAddress, uint32_t Mask1, uint32_t Value1, uint32_t Mask2, uint32_t Value2,
              typename... Ts, typename... Us>
    struct merge_actions_impl<
        mpl::list<indexed_action<action<TAddress, write_literal_action<Mask1, Value1>>>, Ts...>,
        mpl::list<indexed_action<action<TAddress, write_literal_action<Mask2, Value2>>>, Us...>>
        : merge_actions_impl<mpl::list<Ts...>,
                             mpl::list<indexed_action<action<
                                 TAddress, write_literal_action<Mask1 | Mask2, Value1 | Value2>>>>>
    {
        static_assert((Mask1 & Mask2) == 0,
                      "un-sequenced writes cannot be performed to the same field");
    };
    // merge indexed, run-time/compile-time writes
    template <typename TAddress, uint32_t Mask1, uint32_t Value1, typename... TIndex1,
              uint32_t Mask2, uint32_t Value2, typename... Ts, typename... Us>
    struct merge_actions_impl<
        mpl::list<indexed_action<action<TAddress, write_action<Mask1, Value1>>, TIndex1...>, Ts...>,
        mpl::list<indexed_action<action<TAddress, write_literal_action<Mask2, Value2>>>, Us...>>
        : merge_actions_impl<
              mpl::list<Ts...>,
              mpl::list<indexed_action<
                  action<TAddress, write_action<Mask1 | Mask2, Value1 | Value2>>, TIndex1...>>>
    {
        static_assert((Mask1 & Mask2) == 0,
                      "un-sequenced writes cannot be performed to the same field");
    };
    // merge indexed, compile-time/run-time writes
    template <typename TAddress, uint32_t Mask1, uint32_t Value1, uint32_t Mask2, uint32_t Value2,
              typename... TIndex2, typename... Ts, typename... Us>
    struct merge_actions_impl<
        mpl::list<indexed_action<action<TAddress, write_literal_action<Mask1, Value1>>>, Ts...>,
        mpl::list<indexed_action<action<TAddress, write_action<Mask2, Value2>>, TIndex2...>, Us...>>
        : merge_actions_impl<
              mpl::list<Ts...>,
              mpl::list<indexed_action<
                  action<TAddress, write_action<Mask1 | Mask2, Value1 | Value2>>, TIndex2...>>>
    {
        static_assert((Mask1 & Mask2) == 0,
                      "un-sequenced writes cannot be performed to the same field");
    };
    // merge indexed, run-time
    template <typename TAddress, uint32_t Mask1, uint32_t Value1, typename... TIndex1,
              uint32_t Mask2, uint32_t Value2, typename... TIndex2, typename... Ts, typename... Us>
    struct merge_actions_impl<
        mpl::list<indexed_action<action<TAddress, write_action<Mask1, Value1>>, TIndex1...>, Ts...>,
        mpl::list<indexed_action<action<TAddress, write_action<Mask2, Value2>>, TIndex2...>, Us...>>
        : merge_actions_impl<mpl::list<Ts...>,
                             mpl::list<indexed_action<
                                 action<TAddress, write_action<Mask1 | Mask2, Value1 | Value2>>,
                                 TIndex1..., TIndex2...>>>
    {
    };
    // non-mergable
    template <typename TNext, typename TLast, typename... Ts, typename... Us>
    struct merge_actions_impl<mpl::list<TNext, Ts...>, mpl::list<TLast, Us...>>
        : merge_actions_impl<mpl::list<Ts...>, mpl::list<TNext, TLast, Us...>>
    {
    };
    // done
    template <typename... Ts>
    struct merge_actions_impl<mpl::list<>, mpl::list<Ts...>>
    {
        using type = mpl::eager::reverse<mpl::list<Ts...>>;
    };

    template <typename T>
    using merge_actions = typename merge_actions_impl<T>::type;

    // once the actions have been optimized, we have to trace back the args to
    // the corresponding action. for each action, we want to create a list of
    // lists of args to ignore, that is, if an action has indices 2, 3, and 5,
    // we want to take the 3rd, 4th, and 6th args, so the inputs are:
    // list<list<T, T>, list<>, list<T, T>>
    // which translates to drop 2 args, take 1, drop 0 args, take 1, drop 2
    // args, take 1

    // compute the number of args between two indices
    template <typename T, typename U>
    using index_difference = mpl::uint_<T::value - U::value - 1>;
    // build a sequence of list<unsigned, unsigned, ...> of length T::value
    template <typename T>
    using to_unsigned = unsigned;
    template <typename T>
    struct build_index_sequence_impl
    {
        using index_sequence = mpl::eager::make_int_sequence<T>;
        using type = mpl::eager::transform<index_sequence, to_unsigned>;
    };
    template <typename T>
    using build_index_sequence = typename build_index_sequence_impl<T>::type;

    template <typename T>
    struct build_inputs_impl;
    // action has to indices, ignore all args
    template <typename A>
    struct build_inputs_impl<indexed_action<A>>
    {
        using type = mpl::list<>;
    };
    template <typename A, typename... T>
    struct build_inputs_impl<indexed_action<A, T...>>
    {
        using sorted_indices = mpl::eager::sort<mpl::list<T...>>;
        // get number of elements between each index
        using index0 = mpl::eager::drop<sorted_indices, 1>;
        using index1 = mpl::eager::take<sorted_indices, sizeof...(T) - 1>;
        using index_delta =
            mpl::eager::push_front<mpl::eager::at<sorted_indices, 0>,
                                   mpl::eager::zip_with<index_difference, index0, index1>>;
        // create lists of `unsigned` elements with size given by delta
        using type = mpl::eager::transform<index_delta, build_index_sequence>;
    };
    template <typename T>
    using build_inputs = typename build_inputs_impl<T>::type;

    // pull action out of indexed actions
    template <typename T>
    using build_actions = typename T::action;

    // class that pulls the requested arguments out of the passed arguments
    template <typename... T>
    struct finder_impl;
    template <>
    struct finder_impl<>
    {
        template <typename... Ts>
        uint32_t operator()(Ts...)
        {
            return 0;
        }
    };
    template <typename... As>
    struct finder_impl<mpl::list<As...>>
    {
        template <typename... T>
        uint32_t operator()(As..., uint32_t a, T...)
        {
            return a;
        }
    };
    template <typename... As, typename... Bs>
    struct finder_impl<mpl::list<As...>, Bs...>
    {
        template <typename... T>
        uint32_t operator()(As..., uint32_t a, T... t)
        {
            auto find_rest = finder_impl<Bs...>{};
            return a | find_rest(t...);
        }
    };
    template <typename T>
    struct finder;
    template <typename... T>
    struct finder<mpl::list<T...>> : finder_impl<T...>
    {
    };

    // argument for runtime write is the contained run-time value
    template <typename T, typename = decltype(T::value_)>
    uint32_t arg_to_unsigned(T arg)
    {
        return arg.value_;
    }
    // argument for compile-time write is 0
    template <typename... Ts>
    inline uint32_t arg_to_unsigned(Ts...)
    {
        return 0;
    }

    // for writes with runtime defined values, execute the write passing in the
    // runtime args, return void
    template <typename TAction, typename TIndex>
    struct all_no_read_with_runtime_writes_apply;
    template <typename... TAction, typename... TIndex>
    struct all_no_read_with_runtime_writes_apply<mpl::list<TAction...>, mpl::list<TIndex...>>
    {
        template <typename... Ts>
        void operator()(Ts... args)
        {
            (execute_seam<TAction, user_tag>{}(finder<TIndex>{}(args...)), ...);
        }
    };

    // for compile-time writes, no args are needed, execute the write and
    // return void
    template <typename T>
    struct all_compile_time_writes_apply;
    template <typename... TAction>
    struct all_compile_time_writes_apply<mpl::list<TAction...>>
    {
        void operator()() { (execute_seam<TAction, user_tag>{}(), ...); }
    };

} // namespace detail

template <typename... Arg>
std::enable_if_t<all_no_read_with_runtime_writes_v<Arg...>> apply(Arg... args)
{
    using actions = mpl::list<Arg...>;
    using indexed_actions =
        mpl::eager::zip_with<detail::make_indexed_action, actions,
                             mpl::eager::make_int_sequence<mpl::eager::size<actions>>>;
    // sort and merge the actions
    using sorted_actions = mpl::eager::sort<indexed_actions, detail::address_less_than>;
    using merged_actions = detail::merge_actions<sorted_actions>;
    // pull out the actions and the corresponding inputs
    using input_actions = mpl::eager::transform<merged_actions, detail::build_actions>;
    using inputs = mpl::eager::transform<merged_actions, detail::build_inputs>;
    // apply the actions
    detail::all_no_read_with_runtime_writes_apply<input_actions, inputs> applicator{};
    applicator(detail::arg_to_unsigned(args)...);
}

template <typename... Arg>
std::enable_if_t<all_compile_time_writes_v<Arg...>> apply(Arg...)
{
    using actions = mpl::list<Arg...>;
    // sort and merge the actions
    using sorted_actions = mpl::eager::sort<actions, detail::address_less_than>;
    using merged_actions = detail::merge_actions<sorted_actions>;
    // apply the actions
    detail::all_compile_time_writes_apply<merged_actions>{}();
}

} // namespace kvasir::sfr
