#pragma once

#include <kvasir/sfr/types.hpp>
#include <kvasir/sfr/utility.hpp>

//General-purpose I/Os
namespace kvasir {
    namespace gpioa_moder{    ///<GPIO port mode register
        using addr = sfr::address<0x40020000, 0x00000000, 0x00000000, unsigned>;

        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(31,30), sfr::read_write_access, unsigned> moder15{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(29,28), sfr::read_write_access, unsigned> moder14{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(27,26), sfr::read_write_access, unsigned> moder13{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(25,24), sfr::read_write_access, unsigned> moder12{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(23,22), sfr::read_write_access, unsigned> moder11{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(21,20), sfr::read_write_access, unsigned> moder10{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(19,18), sfr::read_write_access, unsigned> moder9{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(17,16), sfr::read_write_access, unsigned> moder8{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(15,14), sfr::read_write_access, unsigned> moder7{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(13,12), sfr::read_write_access, unsigned> moder6{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(11,10), sfr::read_write_access, unsigned> moder5{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(9,8), sfr::read_write_access, unsigned> moder4{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(7,6), sfr::read_write_access, unsigned> moder3{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(5,4), sfr::read_write_access, unsigned> moder2{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(3,2), sfr::read_write_access, unsigned> moder1{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(1,0), sfr::read_write_access, unsigned> moder0{};
    }

    namespace gpioa_otyper{    ///<GPIO port output type register
        using addr = sfr::address<0x40020004, 0xffff0000, 0x00000000, unsigned>;
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(15,15), sfr::read_write_access, unsigned> ot15{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(14,14), sfr::read_write_access, unsigned> ot14{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(13,13), sfr::read_write_access, unsigned> ot13{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(12,12), sfr::read_write_access, unsigned> ot12{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(11,11), sfr::read_write_access, unsigned> ot11{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(10,10), sfr::read_write_access, unsigned> ot10{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(9,9), sfr::read_write_access, unsigned> ot9{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(8,8), sfr::read_write_access, unsigned> ot8{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(7,7), sfr::read_write_access, unsigned> ot7{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(6,6), sfr::read_write_access, unsigned> ot6{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(5,5), sfr::read_write_access, unsigned> ot5{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(4,4), sfr::read_write_access, unsigned> ot4{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(3,3), sfr::read_write_access, unsigned> ot3{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(2,2), sfr::read_write_access, unsigned> ot2{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(1,1), sfr::read_write_access, unsigned> ot1{};
        ///Port x configuration bits (y =              0..15)
        constexpr sfr::field_location<addr, sfr::mask_from_range(0,0), sfr::read_write_access, unsigned> ot0{};
    }
}
