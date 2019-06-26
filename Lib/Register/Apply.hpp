/**************************************************************************
 * This file contains the Kvasir Register Abstraction DSL (Domain Specific Language)
 * which provide an extra layer between Hardware SFRs
 * (Special Function Registers) and code accessing them.
 * Copyright 2015 Odin Holmes
 * Aditional contribution from Stephan Bökelmann

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
****************************************************************************/
#pragma once

#include "Common/Tags.hpp"
#include "Exec.hpp"
#include "Mpl/Algorithm.hpp"
#include "Mpl/Types.hpp"
#include "Mpl/Utility.hpp"
#include "Types.hpp"
#include "Utility.hpp"
#include <utility>

#include "kvasir/mpl/mpl.hpp"

namespace Kvasir::Register
{

namespace Detail
{
    namespace br = brigand;

    template <std::size_t I, typename O, typename A, typename L>
    struct MakeSeperatorsImpl
    {
        using type = O;
    };
    template <std::size_t I, typename... O, typename... A, typename... T>
    struct MakeSeperatorsImpl<I, kvasir::mpl::list<O...>, kvasir::mpl::list<A...>,
                              br::list<br::size_t<I>, T...>>
        : MakeSeperatorsImpl<(I + 1), kvasir::mpl::list<O..., kvasir::mpl::list<A...>>,
                             kvasir::mpl::list<>, br::list<T...>>
    {
    };

    template <std::size_t I, typename... O, typename... A, typename U, typename... T>
    struct MakeSeperatorsImpl<I, kvasir::mpl::list<O...>, kvasir::mpl::list<A...>,
                              br::list<U, T...>>
        : MakeSeperatorsImpl<I + 1, kvasir::mpl::list<O...>, kvasir::mpl::list<A..., unsigned>,
                             br::list<U, T...>>
    {
    };
    template <typename T>
    using MakeSeperators =
        MakeSeperatorsImpl<0, kvasir::mpl::list<>, kvasir::mpl::list<>, brigand::sort<T>>;

    // an index action consists of an action (possibly merged) and
    // the inputs including masks which it needs
    template <typename TAction, typename... TInputs>
    struct IndexedAction
    {
        using type = IndexedAction<TAction, TInputs...>;
    };

    template <typename T>
    struct GetActionImpl;
    template <typename A, typename... T>
    struct GetActionImpl<IndexedAction<A, T...>>
    {
        using f = A;
    };
    template <typename F, typename A>
    struct GetActionImpl<Action<F, A>>
    {
        using f = Action<F, A>;
    };
    template <typename T>
    using GetAction = typename GetActionImpl<T>::f;

    template <typename T>
    struct GetInputsImpl;
    template <typename A, typename... T>
    struct GetInputsImpl<IndexedAction<A, T...>>
    {
        using f = typename MakeSeperators<brigand::list<T...>>::type;
    };
    template <typename T>
    using GetInputs = typename GetInputsImpl<T>::f;

    // predicate returning result of left < right for RegisterOptions
    template <typename TLeft, typename TRight>
    struct IndexedActionLess;
    template <typename T1, typename U1, typename T2, typename U2, typename... TInputs1,
              typename... TInputs2>
    struct IndexedActionLess<IndexedAction<Action<T1, U1>, TInputs1...>,
                             IndexedAction<Action<T2, U2>, TInputs2...>>
        : Bool<(GetAddress<T1>::value < GetAddress<T2>::value)>
    {
    };
    template <typename T1, typename U1, typename T2, typename U2>
    struct IndexedActionLess<Action<T1, U1>, Action<T2, U2>>
        : Bool<(GetAddress<T1>::value < GetAddress<T2>::value)>
    {
    };

    template <typename TRegisters, typename TRet = kvasir::mpl::list<>> // default
    struct MergeRegisterActions;

    template <typename TNext, typename... Ts> // none processed yet
    struct MergeRegisterActions<brigand::list<TNext, Ts...>, kvasir::mpl::list<>>
        : MergeRegisterActions<brigand::list<Ts...>, kvasir::mpl::list<TNext>>
    {
    };

    // indexed
    template <typename TAddress, unsigned Mask1, unsigned Mask2, typename TAccess1,
              typename TAccess2, typename TFieldType1, typename TFieldType2,
              template <unsigned> class TActionTemplate, unsigned Value1, unsigned Value2,
              typename... TInputs1, typename... TInputs2, typename... Ts,
              typename... Us> // next input and last merged are mergable
    struct MergeRegisterActions<
        brigand::list<IndexedAction<Action<FieldLocation<TAddress, Mask1, TAccess1, TFieldType1>,
                                           TActionTemplate<Value1>>,
                                    TInputs1...>,
                      Ts...>,
        kvasir::mpl::list<
            IndexedAction<Action<FieldLocation<TAddress, Mask2, TAccess2, TFieldType2>,
                                 TActionTemplate<Value2>>,
                          TInputs2...>,
            Us...>>
        : MergeRegisterActions<
              brigand::list<Ts...>,
              // merge masks care, plausibility check has already been done
              // merge values
              // concatenate inputs
              // pass through rest
              kvasir::mpl::list<
                  IndexedAction<Action<FieldLocation<TAddress, (Mask1 | Mask2), TAccess1>,
                                       TActionTemplate<(Value1 | Value2)>
                                       // TODO implement register type here
                                       >,
                                TInputs1..., TInputs2...>,
                  Us...>>
    {
    };

    // non indexed
    template <typename TAddress, unsigned Mask1, unsigned Mask2, typename TAccess1,
              typename TAccess2, typename TFieldType1, typename TFieldType2,
              template <unsigned> class TActionTemplate, unsigned Value1, unsigned Value2,
              typename... Ts, typename... Us> // next input and last merged are mergable
    struct MergeRegisterActions<
        brigand::list<
            Action<FieldLocation<TAddress, Mask1, TAccess1, TFieldType1>, TActionTemplate<Value1>>,
            Ts...>,
        kvasir::mpl::list<
            Action<FieldLocation<TAddress, Mask2, TAccess2, TFieldType2>, TActionTemplate<Value2>>,
            Us...>>
        : MergeRegisterActions<
              brigand::list<Ts...>,
              kvasir::mpl::list<Action<FieldLocation<TAddress,
                                                     (Mask1 | Mask2), // merge
                                                     TAccess1>, // dont care, plausibility check has
                                                                // already been done
                                       TActionTemplate<(Value1 | Value2)> // merge
                                       // TODO implement register type here
                                       >,
                                Us...> // pass through rest
              >
    {
    };

    template <typename TNext, typename TLast, typename... Ts,
              typename... Us> // next and last not mergable
    struct MergeRegisterActions<brigand::list<TNext, Ts...>, kvasir::mpl::list<TLast, Us...>>
        : MergeRegisterActions<brigand::list<Ts...>, kvasir::mpl::list<TNext, TLast, Us...>>
    {
    };

    template <typename... Ts> // done
    struct MergeRegisterActions<brigand::list<>, kvasir::mpl::list<Ts...>>
    {
        using type = kvasir::mpl::list<Ts...>;
    };

    template <typename T>
    using MergeRegisterActionsT = typename MergeRegisterActions<T>::type;

    template <typename TList>
    struct MergeActionSteps;
    template <typename... Ts>
    struct MergeActionSteps<brigand::list<Ts...>>
    {
        using type = kvasir::mpl::list<MergeRegisterActionsT<
            brigand::sort<brigand::flatten<Ts>, Detail::IndexedActionLess<brigand::_1, brigand::_2>>
            // SortT<brigand::flatten<Ts>,
            // MPL::Template<Detail::IndexedActionLess>>
            >...>;
    };

    template <typename T>
    using MergeActionStepsT = typename MergeActionSteps<T>::type;

    template <typename TAction, typename... TInputs>
    struct GetAddress<IndexedAction<TAction, TInputs...>> : GetAddress<TAction>
    {
    };

    template <bool TopLevel, typename TAction, typename Index>
    struct MakeIndexedActionImpl;
    // in default case there is no actual expected input
    template <bool TopLevel, typename TAddress, unsigned Mask, typename TAccess, typename TR,
              typename TAction, int Index>
    struct MakeIndexedActionImpl<
        TopLevel, Action<FieldLocation<TAddress, Mask, TAccess, TR>, TAction>, Int<Index>>
    {
        using type = IndexedAction<Action<FieldLocation<TAddress, Mask, TAccess, TR>, TAction>>;
    };

    // special case where there actually is expected input
    template <bool TopLevel, typename TAddress, unsigned Mask, typename TAccess, typename TR,
              int Index>
    struct MakeIndexedActionImpl<
        TopLevel, Action<FieldLocation<TAddress, Mask, TAccess, TR>, WriteAction>, Int<Index>>
    {
        static_assert(
            TopLevel,
            "runtime values can only be executed in an apply, they cannot be stored in a list");
        using type = IndexedAction<Action<FieldLocation<TAddress, Mask, TAccess, TR>, WriteAction>,
                                   brigand::size_t<Index>>;
    };

    // special case where there actually is expected input
    template <bool TopLevel, typename TAddress, unsigned Mask, typename TAccess, typename TR,
              int Index>
    struct MakeIndexedActionImpl<
        TopLevel, Action<FieldLocation<TAddress, Mask, TAccess, TR>, XorAction>, Int<Index>>
    {
        static_assert(
            TopLevel,
            "runtime values can only be executed in an apply, they cannot be stored in a list");
        using type = IndexedAction<Action<FieldLocation<TAddress, Mask, TAccess, TR>, WriteAction>,
                                   brigand::size_t<Index>>;
    };

    // special case where a list of actions is passed
    template <bool TopLevel, typename... Ts, typename Index>
    struct MakeIndexedActionImpl<TopLevel, brigand::list<Ts...>, Index>
    {
        using type = brigand::list<typename MakeIndexedActionImpl<false, Ts, Index>::type...>;
    };
    // special case where a sequence point is passed
    template <bool TopLevel, typename Index>
    struct MakeIndexedActionImpl<TopLevel, SequencePoint, Index>
    {
        using type = SequencePoint;
    };

    template <typename TAction, typename Index>
    using MakeIndexedAction = typename MakeIndexedActionImpl<true, TAction, Index>::type;

    template <unsigned I>
    struct IsAddressPred
    {
        template <typename T>
        struct apply : kvasir::mpl::false_
        {
        };
        template <typename TAddress, unsigned Mask, typename TAccess, typename TFieldType,
                  typename Cmd>
        struct apply<Action<FieldLocation<TAddress, Mask, TAccess, TFieldType>, Cmd>>
            : kvasir::mpl::bool_<I == GetAddress<TAddress>::value>
        {
        };
    };

    // takes an args list or tree, flattens it and removes all actions which are not reads
    template <typename... TArgList>
    using GetReadsT =
        brigand::transform<brigand::remove_if<brigand::flatten<brigand::list<TArgList...>>,
                                              IsNotReadPred<brigand::_1>>,
                           GetFieldLocation<brigand::_1>>;

    template <typename T>
    using IsNotRuntimeWritePredF = IsNotRuntimeWritePred<T>;
    template <typename... T>
    constexpr bool noneRuntime()
    {
        return kvasir::mpl::eager::size<kvasir::mpl::eager::remove_if<
                   kvasir::mpl::list<T...>, IsNotRuntimeWritePredF>>::value == 0;
    }

    template <typename... T>
    struct AllCompileTime
    {
        static constexpr bool value =
            (brigand::size<Detail::GetReadsT<brigand::list<T...>>>::value == 0) &&
            noneRuntime<T...>();
    };
    template <typename... T>
    inline constexpr bool AllCompileTimeV = AllCompileTime<T...>::value;

    template <typename... T>
    struct NoReadsRuntimeWrites
    {
        static constexpr bool value =
            (brigand::size<Detail::GetReadsT<brigand::list<T...>>>::value == 0) &&
            !noneRuntime<T...>();
    };

    template <typename T>
    struct GetReadMask : Int<0>
    {
    };

    template <typename T>
    struct GetAddresses;
    template <typename TAddresses, typename TLocations>
    struct GetAddresses<FieldTuple<TAddresses, TLocations>> : TAddresses
    {
    };

    template <typename T, typename = decltype(T::value_)>
    DEBUG_OPTIMIZE unsigned argToUnsigned(T arg)
    {
        return arg.value_;
    }
    DEBUG_OPTIMIZE inline unsigned argToUnsigned(...) { return 0; }

    // finder takes a list of lists of unsigned, each list represents a
    // pack of arguments to be ignored. All non ignored arguments will
    // be ored together

    template <typename T>
    struct Finder;
    template <>
    struct Finder<kvasir::mpl::list<>>
    {
        DEBUG_OPTIMIZE unsigned operator()(...) { return 0; }
    };
    template <typename... A>
    struct Finder<kvasir::mpl::list<kvasir::mpl::list<A...>>>
    {
        template <typename... T>
        DEBUG_OPTIMIZE unsigned operator()(A..., unsigned a, T...)
        {
            return a;
        }
    };
    template <typename... A, typename... B>
    struct Finder<kvasir::mpl::list<kvasir::mpl::list<A...>, kvasir::mpl::list<B...>>>
    {
        template <typename... T>
        DEBUG_OPTIMIZE unsigned operator()(A..., unsigned a, B..., unsigned b, T...)
        {
            return a | b;
        }
    };
    template <typename... A, typename... B, typename... Rest>
    struct Finder<kvasir::mpl::list<kvasir::mpl::list<A...>, kvasir::mpl::list<B...>, Rest...>>
    {
        template <typename... T>
        DEBUG_OPTIMIZE unsigned operator()(A..., unsigned a, B..., unsigned b, T... t)
        {
            auto r = Finder<kvasir::mpl::list<Rest...>>{};
            return a | b | r(t...);
        }
    };

    template <typename TActionList, typename TInputIndexList, typename TRetType>
    struct Apply;
    template <typename... TActions, typename... TInputIndexes, typename... TRetAddresses,
              typename TRetLocations>
    struct Apply<kvasir::mpl::list<TActions...>, kvasir::mpl::list<TInputIndexes...>,
                 FieldTuple<brigand::list<TRetAddresses...>, TRetLocations>>
    {
        using ReturnType = FieldTuple<brigand::list<TRetAddresses...>, TRetLocations>;
        template <unsigned A>
        DEBUG_OPTIMIZE typename std::enable_if<
            brigand::contains<brigand::set<TRetAddresses...>, brigand::uint32_t<A>>::value>::type
        filterReturns(ReturnType & ret, unsigned in)
        {
            ret.value_[sizeof...(TRetAddresses) -
                       brigand::size<brigand::find<
                           brigand::list<TRetAddresses...>,
                           std::is_same<brigand::uint32_t<A>, brigand::_1>>>::value] |= in;
        }
        template <unsigned A>
        DEBUG_OPTIMIZE void filterReturns(...)
        {
        }

        template <typename... T>
        DEBUG_OPTIMIZE ReturnType operator()(T... args)
        {
            ReturnType ret{{}}; // default constructed return
            const unsigned a[]{0U, (filterReturns<Detail::GetAddress<TActions>::value>(
                                        ret, ExecuteSeam<TActions, ::Kvasir::Tag::User>{}(
                                                 Finder<TInputIndexes>{}(args...))),
                                    0U)...};
            ignore(a);

            return ret;
        }
    };

    // no read apply
    template <typename TActionList, typename TInputIndexList>
    struct NoReadApply;
    template <typename... TActions, typename... TInputIndexes>
    struct NoReadApply<kvasir::mpl::list<TActions...>, kvasir::mpl::list<TInputIndexes...>>
    {
        template <typename... T>
        DEBUG_OPTIMIZE void operator()(T... args)
        {
            const unsigned a[]{
                0U, (ExecuteSeam<TActions, ::Kvasir::Tag::User>{}(Finder<TInputIndexes>{}(args...)),
                     0U)...};
            ignore(a);
        }
    };

    // no read no runtime write apply
    template <typename... TActions>
    DEBUG_OPTIMIZE void noReadNoRuntimeWriteApply(kvasir::mpl::list<TActions...> *)
    {
        const unsigned a[]{0U, ExecuteSeam<TActions, ::Kvasir::Tag::User>{}(0U)...};
        ignore(a);
    }

    template <typename... Ts>
    using GetReturnType = FieldTuple<
        UniqueT<brigand::sort<brigand::transform<GetReadsT<Ts...>, brigand::quote<GetAddress>>>>,
        GetReadsT<Ts...>>;
    template <typename T>
    struct ArgToApplyIsPlausible : FalseType
    {
    };
    template <typename L, typename A>
    struct ArgToApplyIsPlausible<Action<L, A>> : TrueType
    {
    };
    template <>
    struct ArgToApplyIsPlausible<SequencePoint> : kvasir::mpl::true_
    {
    };
    template <typename T, typename... Ts>
    struct ArgsToApplyArePlausible
    {
        using l = brigand::flatten<brigand::list<T, Ts...>>;
        using type = kvasir::mpl::bool_<
            std::is_same_v<MPL::RepeatC<brigand::size<l>::value, MPL::TrueType>,
                           brigand::transform<l, brigand::quote<ArgToApplyIsPlausible>>>>;
        static constexpr int value = type::value;
    };
} // namespace Detail

// if apply contains reads return a FieldTuple
template <typename... Args>
DEBUG_OPTIMIZE inline
    typename std::enable_if<(brigand::size<Detail::GetReadsT<brigand::list<Args...>>>::value != 0),
                            Detail::GetReturnType<Args...>>::type
    apply(Args... args)
{
    static_assert(Detail::ArgsToApplyArePlausible<Args...>::value,
                  "one of the supplied arguments is not supported");
    using IndexedActions =
        brigand::transform<brigand::list<Args...>, MPL::BuildIndicesT<sizeof...(Args)>,
                           brigand::quote<Detail::MakeIndexedAction>>;
    using FlattenedActions = brigand::flatten<IndexedActions>;
    using Steps = brigand::split<FlattenedActions, SequencePoint>;
    using Merged = Detail::MergeActionStepsT<Steps>;
    using Actions = kvasir::mpl::eager::flatten<Merged>;
    using Functors = kvasir::mpl::eager::transform<Actions, Detail::GetAction>;
    using Inputs = kvasir::mpl::eager::transform<Actions, Detail::GetInputs>;
    Detail::Apply<Functors, Inputs, Detail::GetReturnType<Args...>> a{};
    return a(Detail::argToUnsigned(args)...);
}

// if apply does not contain reads return is void
template <typename... Args>
DEBUG_OPTIMIZE typename std::enable_if<Detail::NoReadsRuntimeWrites<Args...>::value>::type
apply(Args... args)
{
    static_assert(Detail::ArgsToApplyArePlausible<Args...>::value,
                  "one of the supplied arguments is not supported");
    using IndexedActions =
        brigand::transform<brigand::list<Args...>, MPL::BuildIndicesT<sizeof...(Args)>,
                           brigand::quote<Detail::MakeIndexedAction>>;
    using FlattenedActions = brigand::flatten<IndexedActions>;
    using Steps = brigand::split<FlattenedActions, SequencePoint>;
    using Merged = Detail::MergeActionStepsT<Steps>;
    using Actions = kvasir::mpl::eager::flatten<Merged>;
    using Functors = kvasir::mpl::eager::transform<Actions, Detail::GetAction>;
    using Inputs = kvasir::mpl::eager::transform<Actions, Detail::GetInputs>;
    Detail::NoReadApply<Functors, Inputs> a{};
    a(Detail::argToUnsigned(args)...);
}

// if apply does not contain reads or runtime writes we can speed things up
template <typename... Args>
DEBUG_OPTIMIZE typename std::enable_if_t<Detail::AllCompileTimeV<Args...>> apply(Args...)
{
    static_assert(Detail::ArgsToApplyArePlausible<Args...>::value,
                  "one of the supplied arguments is not supported");
    // using IndexedActions = brigand::transform<brigand::list<Args...>,
    // MPL::BuildIndicesT<sizeof...(Args)>, brigand::quote<Detail::MakeIndexedAction>>;
    using FlattenedActions = brigand::flatten<brigand::list<Args...>>;
    using Steps = brigand::split<FlattenedActions, SequencePoint>;
    using Merged = Detail::MergeActionStepsT<Steps>;
    using Actions = kvasir::mpl::eager::flatten<Merged>;
    Detail::noReadNoRuntimeWriteApply(static_cast<Actions *>(nullptr));
}

// no parameters is allowed because it could be used in machine generated code
// it does nothing
inline void apply() {}
inline void apply(brigand::list<>) {}

template <typename TField, typename TField::DataType Value>
DEBUG_OPTIMIZE inline bool fieldEquals(FieldValue<TField, Value>)
{
    return apply(Action<TField, ReadAction>{}) == Value;
}
} // namespace Kvasir::Register
