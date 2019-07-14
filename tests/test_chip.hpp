#pragma once

#include <kvasir/sfr/sfr.hpp>

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
