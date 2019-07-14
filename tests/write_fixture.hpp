#pragma once

#include "kvasir/sfr/seam.hpp"

#include "kvasir/mpl/types/integral_constant.hpp"

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

template <uint32_t N>
using constant = kvasir::mpl::integral_constant<uint32_t, N>;

class sfr_action_test : public ::testing::Test
{
protected:
    void SetUp() final { kvasir::sfr::recorded_actions.clear(); }

    void TearDown() final { kvasir::sfr::recorded_actions.clear(); }

    template <typename T1, typename T2>
    void check_permutations(const std::vector<recorded_action> & expected_actions, T1 t1, T2 t2)
    {
        apply(t1, t2);
        check_expected_actions(expected_actions);

        apply(t2, t1);
        check_expected_actions(expected_actions);
    }

    template <typename T1, typename T2, typename T3>
    void check_permutations(const std::vector<recorded_action> & expected_actions, T1 t1, T2 t2,
                            T3 t3)
    {
        apply(t1, t2, t3);
        check_expected_actions(expected_actions);

        apply(t1, t3, t2);
        check_expected_actions(expected_actions);

        apply(t2, t1, t3);
        check_expected_actions(expected_actions);

        apply(t2, t3, t1);
        check_expected_actions(expected_actions);

        apply(t3, t1, t2);
        check_expected_actions(expected_actions);

        apply(t3, t2, t1);
        check_expected_actions(expected_actions);
    }

    void check_expected_actions(const std::vector<recorded_action> & expected_actions)
    {
        EXPECT_THAT(kvasir::sfr::recorded_actions, ::testing::ContainerEq(expected_actions));

        kvasir::sfr::recorded_actions.clear();
    }
};
