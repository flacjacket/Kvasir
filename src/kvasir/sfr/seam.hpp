#pragma once

#include <vector>

namespace kvasir::sfr
{

struct recorded_action
{
    enum class action_type
    {
        read,
        write,
        write_literal,
    };

    uint32_t address_;
    uint32_t value_;
    uint32_t mask_;
    action_type action_type_;
};

inline std::vector<recorded_action> recorded_actions;

template <typename T>
struct action_recorder;
template <typename TAddress, uint32_t Mask, uint32_t Value>
struct action_recorder<action<TAddress, write_literal_action<Mask, Value>>>
{
    uint32_t operator()(uint32_t = 0)
    {
        recorded_actions.push_back(recorded_action{TAddress::value, Value, Mask, recorded_action::action_type::write_literal});
        return 0;
    }
};

} // kvasir::sfr
