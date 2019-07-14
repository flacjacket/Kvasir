#include "test_chip.hpp"
#include "write_fixture.hpp"

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_mixed_merge)
{
    constexpr auto w1 = write(kvasir::register1::field1, constant<1>{});
    constexpr auto w2 = write(kvasir::register1::field3, 2);

    const std::vector<recorded_action> expected_actions = {
        {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
    };

    check_permutations(expected_actions, w1, w2);
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_mixed_merge_with_sort)
{
    {
        constexpr auto w1 = write(kvasir::register1::field1, 1);
        constexpr auto w2 = write(kvasir::register1::field3, constant<2>{});
        constexpr auto w3 = write(kvasir::register2::field1, constant<1>{});

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write_literal},
        };

        check_permutations(expected_actions, w1, w2, w3);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, constant<1>{});
        constexpr auto w2 = write(kvasir::register1::field3, 2);
        constexpr auto w3 = write(kvasir::register2::field1, constant<1>{});

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write_literal},
        };

        check_permutations(expected_actions, w1, w2, w3);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, constant<1>{});
        constexpr auto w2 = write(kvasir::register1::field3, constant<2>{});
        constexpr auto w3 = write(kvasir::register2::field1, 1);

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write_literal},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
        };

        check_permutations(expected_actions, w1, w2, w3);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, constant<1>{});
        constexpr auto w2 = write(kvasir::register1::field3, 2);
        constexpr auto w3 = write(kvasir::register2::field1, 1);

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
        };

        check_permutations(expected_actions, w1, w2, w3);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, 1);
        constexpr auto w2 = write(kvasir::register1::field3, constant<2>{});
        constexpr auto w3 = write(kvasir::register2::field1, 1);

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
        };

        check_permutations(expected_actions, w1, w2, w3);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, 1);
        constexpr auto w2 = write(kvasir::register1::field3, 2);
        constexpr auto w3 = write(kvasir::register2::field1, constant<1>{});

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write_literal},
        };

        check_permutations(expected_actions, w1, w2, w3);
    }
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_mixed_merge_with_flatten)
{
    {
        auto w1 = write(kvasir::register1::field1, constant<1>{});
        auto w2 = write(kvasir::register1::field3, constant<2>{});
        auto w3 = write(kvasir::register2::field1, 1);

        auto l = kvasir::mpl::list<decltype(w1), decltype(w2)>{};

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write_literal},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
        };

        check_permutations(expected_actions, l, w3);
    }
    {
        auto w1 = write(kvasir::register1::field1, constant<1>{});
        auto w2 = write(kvasir::register1::field3, 2);
        auto w3 = write(kvasir::register2::field1, constant<1>{});

        auto l = kvasir::mpl::list<decltype(w1), decltype(w3)>{};

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write_literal},
        };

        check_permutations(expected_actions, l, w2);
    }
    {
        auto w1 = write(kvasir::register1::field1, 1);
        auto w2 = write(kvasir::register1::field3, constant<2>{});
        auto w3 = write(kvasir::register2::field1, constant<1>{});

        auto l = kvasir::mpl::list<decltype(w2), decltype(w3)>{};

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write_literal},
        };

        check_permutations(expected_actions, l, w1);
    }
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_mixed_no_merge_different_address)
{
    {
        constexpr auto w1 = write(kvasir::register1::field1, 2);
        constexpr auto w2 = write(kvasir::register2::field1, constant<1>{});

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x80000000U, 0xc0000000U, recorded_action::action_type::write},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write_literal},
        };

        check_permutations(expected_actions, w1, w2);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, constant<2>{});
        constexpr auto w2 = write(kvasir::register2::field1, 1);

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x80000000U, 0xc0000000U, recorded_action::action_type::write_literal},
            {0x40020004U, 0x00000800U, 0x0000f800U, recorded_action::action_type::write},
        };

        check_permutations(expected_actions, w1, w2);
    }
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_mixed_no_merge_sequenced)
{
    {
        constexpr auto w1 = write(kvasir::register1::field1, 1);
        constexpr auto w2 = write(kvasir::register1::field3, constant<2>{});

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000000U, 0xc0000000U, recorded_action::action_type::write},
            {0x40020000U, 0x00000008U, 0x0000000cU, recorded_action::action_type::write_literal},
        };

        apply(w1, kvasir::sfr::sequence_point, w2);
        check_expected_actions(expected_actions);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, constant<1>{});
        constexpr auto w2 = write(kvasir::register1::field3, 2);

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000000U, 0xc0000000U, recorded_action::action_type::write_literal},
            {0x40020000U, 0x00000008U, 0x0000000cU, recorded_action::action_type::write},
        };

        apply(w1, kvasir::sfr::sequence_point, w2);
        check_expected_actions(expected_actions);
    }
}

// NOLINTNEXTLINE
TEST_F(sfr_action_test, write_mixed_merge_unsequenced)
{
    {
        constexpr auto w1 = write(kvasir::register1::field1, 1);
        constexpr auto w2 = write(kvasir::register1::field3, constant<2>{});

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
        };

        apply(kvasir::sfr::sequence_point, w1, w2, kvasir::sfr::sequence_point);
        check_expected_actions(expected_actions);
    }
    {
        constexpr auto w1 = write(kvasir::register1::field1, constant<1>{});
        constexpr auto w2 = write(kvasir::register1::field3, 2);

        const std::vector<recorded_action> expected_actions = {
            {0x40020000U, 0x40000008U, 0xc000000cU, recorded_action::action_type::write},
        };

        apply(kvasir::sfr::sequence_point, w1, w2, kvasir::sfr::sequence_point);
        check_expected_actions(expected_actions);
    }
}
