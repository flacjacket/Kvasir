#pragma once

#include <cstdint>

namespace kvasir::sfr
{

// The types that specify the address and properties of a given register

struct normal_mode
{
};
struct pushable_mode
{
};
struct special_read_mode
{
};

template <uint32_t A, uint32_t WriteIgnoredIfZeroMask = 0, uint32_t WriteIgnoredIfOneMask = 0,
          typename TRegType = uint32_t, typename TMode = normal_mode>
struct address
{
    using type = address<A, WriteIgnoredIfZeroMask, WriteIgnoredIfOneMask, TRegType, TMode>;
    static constexpr uint32_t value = A;
    static constexpr uint32_t write_zero_ignored = WriteIgnoredIfZeroMask;
    static constexpr uint32_t write_one_ignored = WriteIgnoredIfOneMask;
};

// the ways the fields may be accessed and the modifications on access

enum class modified_write_value_type
{
    normal,
    oneToClear,
    oneToSet,
    oneToToggle,
    zeroToClear,
    zeroToSet,
    zeroToToggle,
    clear,
    set,
    modify,
};

enum class read_action_type
{
    normal,
    clear,
    set,
    modify,
    modify_external,
};

enum class access_type
{
    read_only,
    write_only,
    read_write,
    write_once,
    read_write_once,
};

template <access_type, read_action_type = read_action_type::normal,
          modified_write_value_type = modified_write_value_type::normal>
struct access
{
};

using read_write_access = access<access_type::read_write>;
using read_only_access = access<access_type::read_only>;
using write_only_access = access<access_type::write_only>;

// the locations of the given fields within a register

template <typename TAddress, uint32_t Mask, typename TAccess = read_write_access,
          typename TFieldType = uint32_t>
struct field_location
{
    using type = field_location<TAddress, Mask, TAccess, TFieldType>;
    using address = TAddress;
    using data_type = TFieldType;
    static constexpr uint32_t mask = Mask;
};

template <typename TFieldLocation, typename TFieldLocation::data_type Value>
struct field_value
{
};

// the actions that may be performed on a given register

template <typename TAddress, typename TActionType>
struct action : TActionType
{
    template <typename... Ts>
    constexpr explicit action(Ts... args) : TActionType{args...}
    {
    }
};

struct sequence_point_t
{
};
constexpr inline sequence_point_t sequence_point{};

// the various action types

template <uint32_t Mask, uint32_t Value>
struct write_literal_action
{
};

template <uint32_t Mask, uint32_t Value = 0>
struct write_action
{
    uint32_t value_;
};

struct read_action
{
};

template <uint32_t I>
struct xor_literal_action
{
    static constexpr uint32_t value = I;
};

struct xor_action
{
    uint32_t value_;
};

} // namespace kvasir::sfr
