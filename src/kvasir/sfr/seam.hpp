#pragma once

#include <kvasir/sfr/types.hpp>

#include <cstdint>
#include <iomanip>
#include <ostream>
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
struct action_recorder<action<TAddress, write_action<Mask, Value>>>
{
    uint32_t operator()(uint32_t in = 0)
    {
        recorded_actions.push_back(recorded_action{TAddress::value, in | Value, Mask,
                                                   recorded_action::action_type::write});
        return 0;
    }
};
template <typename TAddress, uint32_t Mask, uint32_t Value>
struct action_recorder<action<TAddress, write_literal_action<Mask, Value>>>
{
    uint32_t operator()(uint32_t in = 0)
    {
        recorded_actions.push_back(recorded_action{TAddress::value, in | Value, Mask,
                                                   recorded_action::action_type::write_literal});
        return 0;
    }
};

inline bool operator==(const recorded_action & lhs, const recorded_action & rhs)
{
    return (lhs.address_ == rhs.address_) && (lhs.value_ == rhs.value_) &&
           (lhs.mask_ == rhs.mask_) && (lhs.action_type_ == rhs.action_type_);
}

inline std::ostream & operator<<(std::ostream & stream, const kvasir::sfr::recorded_action & action)
{
    stream << "recorded_action(";
    std::ios_base::fmtflags flags(stream.flags());
    stream << std::showbase << std::internal << std::setfill('0') << std::hex;
    stream << std::setw(10) << action.address_ << ", ";
    stream << std::setw(10) << action.value_ << ", ";
    stream << std::setw(10) << action.mask_ << ", ";
    stream.flags(flags);
    stream << static_cast<uint32_t>(action.action_type_) << ")";
    return stream;
}

} // namespace kvasir::sfr
