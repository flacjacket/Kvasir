#include "test_chip.hpp"
#include "write_fixture.hpp"

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime)
{
    constexpr auto w = write(kvasir::register1::field1, 2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x80000000U, 0xc0000000U, recorded_action::action_type::write},
    };

    apply(w);
    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_merge)
{
    constexpr auto w1 = write(kvasir::register1::field1, 1);
    constexpr auto w2 = write(kvasir::register1::field3, 2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
    };

    check_permutations(expected_actions, w1, w2);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_merge_with_sort)
{
    constexpr auto w1 = write(kvasir::register1::field1, 1);
    constexpr auto w2 = write(kvasir::register1::field3, 2);
    constexpr auto w3 = write(kvasir::register2::field1, 1);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
        {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
    };

    check_permutations(expected_actions, w1, w2, w3);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_no_merge_different_address)
{
    constexpr auto w1 = write(kvasir::register1::field1, 2);
    constexpr auto w2 = write(kvasir::register2::field1, 1);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x80000000U, 0xc0000000U, recorded_action::action_type::write},
        {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
    };

    check_permutations(expected_actions, w1, w2);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_no_merge_sequenced)
{
    constexpr auto w1 = write(kvasir::register1::field1, 1);
    constexpr auto w2 = write(kvasir::register1::field3, 2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x40000000U, 0xc0000000U, recorded_action::action_type::write},
        {0x40020000U, 0x00000008U, 0x0000000cU, recorded_action::action_type::write},
    };

    apply(w1, kvasir::sfr::sequence_point, w2);
    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_runtime_merge_unsequenced)
{
    constexpr auto w1 = write(kvasir::register1::field1, 1);
    constexpr auto w2 = write(kvasir::register1::field3, 2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
    };

    apply(kvasir::sfr::sequence_point, w1, w2, kvasir::sfr::sequence_point);
    check_expected_actions(expected_actions);
}
