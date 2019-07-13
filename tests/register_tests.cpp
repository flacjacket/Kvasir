#include "kvasir/sfr/chip/GPIOA.hpp"
#include "kvasir/sfr/seam.hpp"

#include "gtest/gtest.h"

namespace kvasir::sfr
{

template <typename T>
struct execute_seam<T, kvasir::sfr::user_tag> : action_recorder<T>
{
};

} // namespace kvasir::sfr

using recorded_action = kvasir::sfr::recorded_action;

class sfr_action_test : public ::testing::Test
{
protected:
    void SetUp() final { kvasir::sfr::recorded_actions.clear(); }

    void TearDown() final { kvasir::sfr::recorded_actions.clear(); }

    void check_expected_actions(const std::vector<recorded_action> & expected_actions)
    {
        ASSERT_EQ(expected_actions.size(), kvasir::sfr::recorded_actions.size());

        const auto action_count = expected_actions.size();

        for (size_t i = 0; i < action_count; ++i)
        {
            EXPECT_EQ(expected_actions.at(i), kvasir::sfr::recorded_actions.at(i));
        }

        kvasir::sfr::recorded_actions.clear();
    }
};

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_single_constant_value)
{
    constexpr auto v = kvasir::mpl::integral_constant<uint32_t, 2>{};
    constexpr auto w = write(kvasir::gpioa_moder::moder13, v);
    apply(w);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000, 0x8000000, 0xc000000, recorded_action::action_type::write_literal},
    };

    check_expected_actions(expected_actions);
}
