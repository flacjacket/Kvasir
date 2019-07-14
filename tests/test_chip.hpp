#pragma once

#include "kvasir/sfr/sfr.hpp"

namespace kvasir
{
namespace register1
{
    using addr = sfr::address<0x40020000, 0x00000000, 0x00000000, unsigned>;

    constexpr sfr::field_location<addr, sfr::mask_from_range(31, 30), sfr::read_write_access,
                                  unsigned>
        field1{};
    constexpr sfr::field_location<addr, sfr::mask_from_range(13, 12), sfr::read_write_access,
                                  unsigned>
        field2{};
    enum class enum_field_val
    {
        val0 = 0x0,
        val1 = 0x1,
        val2 = 0x2,
    };
    constexpr sfr::field_location<addr, sfr::mask_from_range(8, 7), sfr::read_write_access,
                                  enum_field_val>
        enum_field{};
    namespace enum_field_c
    {
        constexpr sfr::field_value<decltype(enum_field), enum_field_val::val0> val0{};
        constexpr sfr::field_value<decltype(enum_field), enum_field_val::val1> val1{};
        constexpr sfr::field_value<decltype(enum_field), enum_field_val::val2> val2{};
    } // namespace enum_field_c
    constexpr sfr::field_location<addr, sfr::mask_from_range(3, 2), sfr::read_write_access,
                                  unsigned>
        field3{};
} // namespace register1

namespace register2
{
    using addr = sfr::address<0x40020004, 0xffff0000, 0x00000000, unsigned>;

    constexpr sfr::field_location<addr, sfr::mask_from_range(15, 11), sfr::read_write_access,
                                  unsigned>
        field1{};
    constexpr sfr::field_location<addr, sfr::mask_from_range(6, 4), sfr::read_write_access,
                                  unsigned>
        field2{};
    constexpr sfr::field_location<addr, sfr::mask_from_range(0, 0), sfr::read_write_access,
                                  unsigned>
        field3{};
} // namespace register2
} // namespace kvasir
