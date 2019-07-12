#pragma once

#include <cstdint>

namespace kvasir::sfr
{

constexpr uint32_t mask_from_range(int high, int low)
{
    return (0xffffffffULL >> (31 - (high - low))) << low;
}

} // namespace kvasir::sfr
