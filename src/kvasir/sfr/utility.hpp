#pragma once

#include <cstdint>

namespace kvasir::sfr
{

constexpr uint32_t mask_from_range(uint32_t high, uint32_t low)
{
    return (0xffffffffU >> (31U - (high - low))) << low;
}

} // namespace kvasir::sfr
