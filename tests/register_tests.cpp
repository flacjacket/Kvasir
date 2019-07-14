#include "kvasir/sfr/chip/GPIOA.hpp"
#include "kvasir/sfr/seam.hpp"

#include "gmock/gmock.h"
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
        EXPECT_THAT(kvasir::sfr::recorded_actions, ::testing::ContainerEq(expected_actions));

        kvasir::sfr::recorded_actions.clear();
    }

    static constexpr auto const1 = kvasir::mpl::integral_constant<uint32_t, 1>{};
    static constexpr auto const2 = kvasir::mpl::integral_constant<uint32_t, 2>{};
};

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_constant_single)
{
    constexpr auto w = write(kvasir::gpioa_moder::moder13, const2);
    apply(w);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x08000000U, 0x0c000000U, recorded_action::action_type::write_literal},
    };

    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_single)
{
    constexpr auto w = write(kvasir::gpioa_moder::moder13, 2);
    apply(w);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x08000000U, 0x0c000000U, recorded_action::action_type::write},
    };

    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_constant_merge)
{
    constexpr auto w1 = write(kvasir::gpioa_moder::moder13, const1);
    constexpr auto w2 = write(kvasir::gpioa_moder::moder4, const2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x04000200U, 0x0c000300U, recorded_action::action_type::write_literal},
    };

    apply(w1, w2);
    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_merge)
{
    constexpr auto w1 = write(kvasir::gpioa_moder::moder13, 1);
    constexpr auto w2 = write(kvasir::gpioa_moder::moder4, 2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x04000200U, 0x0c000300U, recorded_action::action_type::write},
    };

    apply(w1, w2);
    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_constant_no_merge_different_address)
{
    constexpr auto w1 = write(kvasir::gpioa_moder::moder13, const2);
    constexpr auto w2 = write(kvasir::gpioa_otyper::ot2, const1);
    apply(w1, w2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x08000000U, 0x0c000000U, recorded_action::action_type::write_literal},
        {0x40020004U, 0x00000004U, 0x00000004U, recorded_action::action_type::write_literal},
    };

    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_no_merge_different_address)
{
    constexpr auto w1 = write(kvasir::gpioa_moder::moder13, 2);
    constexpr auto w2 = write(kvasir::gpioa_otyper::ot2, 1);
    apply(w1, w2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x08000000U, 0x0c000000U, recorded_action::action_type::write},
        {0x40020004U, 0x00000004U, 0x00000004U, recorded_action::action_type::write},
    };

    check_expected_actions(expected_actions);
}
