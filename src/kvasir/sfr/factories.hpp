#pragma once

#include "kvasir/sfr/types.hpp"

#include "kvasir/mpl/types/integral_constant.hpp"

#include <cstdint>
#include <type_traits>

namespace kvasir::sfr
{

namespace detail
{
    constexpr int position_of_first_set_bit(uint32_t in)
    {
        int pos = 0;
        while ((in & 1U) == 0)
        {
            ++pos;
            in >>= 1U;
        }

        return pos;
    }

    template <typename T>
    inline constexpr bool is_integral_constant_v = mpl::eager::is_integral<T>::value;

} // namespace detail

// run-time write
template <typename TFieldLocation>
constexpr auto write(TFieldLocation, typename TFieldLocation::data_type in)
{
    using TAddress = typename TFieldLocation::address;
    constexpr uint32_t shift = detail::position_of_first_set_bit(TFieldLocation::mask);
    return action<TAddress, write_action<TFieldLocation::mask>>{in << shift};
}

// compile-time known write
template <typename TFieldLocation, typename U,
          std::enable_if_t<detail::is_integral_constant_v<U>> * = nullptr>
constexpr auto write(TFieldLocation, U)
{
    using TAddress = typename TFieldLocation::address;
    constexpr uint32_t shift = detail::position_of_first_set_bit(TFieldLocation::mask);
    constexpr uint32_t value = U::value << shift;
    return action<TAddress, write_literal_action<TFieldLocation::mask, value>>{};
}

} // namespace kvasir::sfr
