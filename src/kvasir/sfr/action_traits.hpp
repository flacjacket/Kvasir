#pragma once

#include "kvasir/sfr/types.hpp"

#include "kvasir/mpl/types/list.hpp"

#include <type_traits>

namespace kvasir::sfr
{

namespace detail
{

    template <typename T>
    struct is_read : std::false_type
    {
    };
    template <typename TFieldLocation>
    struct is_read<action<TFieldLocation, read_action>> : std::true_type
    {
    };
    template <typename T>
    inline constexpr bool is_read_v = is_read<T>::value;

    template <typename T>
    struct is_compile_time_action : std::false_type
    {
    };
    template <typename TFieldLocation, uint32_t M, uint32_t V>
    struct is_compile_time_action<action<TFieldLocation, write_literal_action<M, V>>>
        : std::true_type
    {
    };
    template <>
    struct is_compile_time_action<sequence_point_t> : std::true_type
    {
    };
    template <typename... Ts>
    struct is_compile_time_action<mpl::list<Ts...>>
    {
        static constexpr bool value = (is_compile_time_action<Ts>::value && ...);
    };
    template <typename T>
    inline constexpr bool is_compile_time_action_v = is_compile_time_action<T>::value;

} // namespace detail

template <typename T>
struct is_sequence_point : std::is_same<T, sequence_point_t>
{
};

template <typename... Ts>
struct all_compile_time_actions
{
    static constexpr bool value = (detail::is_compile_time_action_v<Ts> && ...);
};
template <typename... Ts>
inline constexpr bool all_compile_time_actions_v = all_compile_time_actions<Ts...>::value;

template <typename... Ts>
struct no_read_actions
{
    static constexpr bool value = (!detail::is_read_v<Ts> && ...);
};
template <typename... Ts>
inline constexpr bool no_read_actions_v = no_read_actions<Ts...>::value;

} // namespace kvasir::sfr
