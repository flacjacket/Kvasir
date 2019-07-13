#pragma once

#include "kvasir/sfr/types.hpp"

#include <cstdint>

namespace kvasir::sfr
{

namespace detail
{
    template <typename T>
    struct register_access;

    template <uint32_t A, uint32_t WIIZ, uint32_t WIIO, typename TRegType, typename TMode>
    struct register_access<address<A, WIIZ, WIIO, TRegType, TMode>>
    {
        static TRegType read()
        {
            volatile TRegType & reg = *reinterpret_cast<volatile TRegType *>(A);
            return reg;
        }

        static void write(TRegType i)
        {
            volatile TRegType & reg = *reinterpret_cast<volatile TRegType *>(A);
            reg = i;
        }
    };

    template <typename TAddress, uint32_t WriteMask, uint32_t WriteValue>
    struct read_mask_or_write
    {
        uint32_t operator()(uint32_t in = 0)
        {
            using accessor = register_access<TAddress>;
            constexpr auto bits_to_clear = WriteMask | TAddress::write_zero_ignored;
            constexpr auto bits_to_set = ~WriteMask & TAddress::write_one_ignored;
            constexpr auto bits_fixed = bits_to_clear | bits_to_set;

            decltype(accessor::read()) i = 0;
            if (bits_fixed != 0xffffffff)
            {
                i = accessor::read();
                i &= ~bits_to_clear;
            }
            i |= WriteValue | bits_to_set | in;
            accessor::write(i);
            return i;
        }
    };

    template <typename TAction>
    struct register_exec;

    template <typename TAddress, uint32_t Mask, uint32_t Data>
    struct register_exec<action<TAddress, write_literal_action<Mask, Data>>>
        : read_mask_or_write<TAddress, Mask, Data>
    {
    };

    template <typename TAddress, uint32_t Mask, uint32_t Data>
    struct register_exec<action<TAddress, write_action<Mask, Data>>>
        : read_mask_or_write<TAddress, Mask, Data>
    {
    };

} // namespace detail

struct user_tag
{
};

template <typename T, typename U>
struct execute_seam : detail::register_exec<T>
{
};

} // namespace kvasir::sfr
