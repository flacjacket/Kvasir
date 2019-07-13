#include "kvasir/sfr/chip/GPIOA.hpp"
#include "kvasir/sfr/seam.hpp"

#include "gtest/gtest.h"

namespace kvasir::sfr
{

template <typename T>
struct execute_seam<T, kvasir::sfr::user_tag> : action_recorder<T>
{
};

// NOLINTNEXTLINE
TEST(write_constant_test, single_value)
{
    EXPECT_EQ(recorded_actions.size(), 0);
    constexpr auto v = kvasir::mpl::integral_constant<uint32_t, 2>{};
    constexpr auto w = write(kvasir::gpioa_moder::moder13, v);
    apply(w);
    EXPECT_EQ(recorded_actions.size(), 1);
}

} // namespace kvasir::sfr
