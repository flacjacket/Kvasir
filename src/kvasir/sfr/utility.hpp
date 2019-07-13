#pragma once

#include <cstdint>

namespace kvasir::sfr
{

constexpr uint32_t mask_from_range(uint32_t high, uint32_t low)
{
    constexpr uint32_t full_mask = 0xffffffffU;
    constexpr uint32_t shift = 31U;
    return (full_mask >> (shift - (high - low))) << low;
}

} // namespace kvasir::sfr
