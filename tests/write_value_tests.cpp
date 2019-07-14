#include "test_chip.hpp"
#include "write_fixture.hpp"

struct write_value_test : sfr_action_test
{
};

// NOLINTNEXTLINE
TEST_F(write_value_test, constant_write)
{
    constexpr auto w = write(kvasir::register1::enum_field_c::val1);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x00000080U, 0x00000180U, recorded_action::action_type::write_literal},
    };

    apply(w);
    check_expected_actions(expected_actions);
}

// NOLINTNEXTLINE
TEST_F(write_value_test, runtime_write)
{
    constexpr auto w =
        write(kvasir::register1::enum_field, kvasir::register1::enum_field_val::val1);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x00000080U, 0x00000180U, recorded_action::action_type::write},
    };

    apply(w);
    check_expected_actions(expected_actions);
}
