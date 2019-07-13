#pragma once

#include "kvasir/sfr/types.hpp"

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
    constexpr bool is_read_v = is_read<T>::value;

    template <typename T>
    struct is_compile_time_write : std::false_type
    {
    };
    template <typename TFieldLocation, uint32_t M, uint32_t V>
    struct is_compile_time_write<action<TFieldLocation, write_literal_action<M, V>>>
        : std::true_type
    {
    };
    template <typename T>
    constexpr bool is_compile_time_write_v = is_compile_time_write<T>::value;

} // namespace detail

template <typename... Ts>
struct all_compile_time_writes
{
    static constexpr bool value = (detail::is_compile_time_write_v<Ts> && ...);
};
template <typename... Ts>
constexpr bool all_compile_time_writes_v = all_compile_time_writes<Ts...>::value;

template <typename... Ts>
struct all_no_read_with_runtime_writes
{
    static constexpr bool value =
        (!detail::is_read_v<Ts> && ...) && (!detail::is_compile_time_write_v<Ts> || ...);
};
template <typename... Ts>
constexpr bool all_no_read_with_runtime_writes_v = all_no_read_with_runtime_writes<Ts...>::value;

} // namespace kvasir::sfr
