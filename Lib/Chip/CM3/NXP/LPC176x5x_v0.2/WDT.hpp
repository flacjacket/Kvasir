#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Watchdog Timer (WDT) 
    namespace WdtMod{    ///<Watchdog mode register. This register determines the basic mode and status of the Watchdog Timer.
        using Addr = Register::Address<0x40000000,0x00000000,0x00000000,unsigned>;
        ///Watchdog enable bit. This bit is Set Only.
        enum class WdenVal {
            stop=0x00000000,     ///<The watchdog timer is stopped.
            run=0x00000001,     ///<The watchdog timer is running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,WdenVal> wden{}; 
        namespace WdenValC{
            constexpr Register::FieldValue<decltype(wden)::Type,WdenVal::stop> stop{};
            constexpr Register::FieldValue<decltype(wden)::Type,WdenVal::run> run{};
        }
        ///Watchdog reset enable bit. This bit is Set Only. See Table 652.
        enum class WdresetVal {
            noreset=0x00000000,     ///<A watchdog timeout will not cause a chip reset.
            reset=0x00000001,     ///<A watchdog timeout will cause a chip reset.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,WdresetVal> wdreset{}; 
        namespace WdresetValC{
            constexpr Register::FieldValue<decltype(wdreset)::Type,WdresetVal::noreset> noreset{};
            constexpr Register::FieldValue<decltype(wdreset)::Type,WdresetVal::reset> reset{};
        }
        ///Watchdog time-out flag. Set when the watchdog timer times out, cleared by software.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> wdtof{}; 
        ///Watchdog interrupt flag.  Cleared by software.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> wdint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,4),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace WdtTc{    ///<Watchdog timer constant register. The value in this register determines the time-out value.
        using Addr = Register::Address<0x40000004,0x00000000,0x00000000,unsigned>;
        ///Watchdog time-out interval.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> count{}; 
    }
    namespace WdtFeed{    ///<Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC.
        using Addr = Register::Address<0x40000008,0xffffff00,0x00000000,unsigned>;
        ///Feed value should be 0xAA followed by 0x55.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> feed{}; 
    }
    namespace WdtTv{    ///<Watchdog timer value register. This register reads out the current value of the Watchdog timer.
        using Addr = Register::Address<0x4000000c,0x00000000,0x00000000,unsigned>;
        ///Counter timer value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> count{}; 
    }
    namespace WdtClksel{    ///<Watchdog clock select register.
        using Addr = Register::Address<0x40000010,0x00000000,0x00000000,unsigned>;
        ///Selects source of WDT clock
        enum class ClkselVal {
            irc=0x00000000,     ///<IRC
            pclk=0x00000001,     ///<Peripheral clock
            rtcosc=0x00000002,     ///<RTC oscillator
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,ClkselVal> clksel{}; 
        namespace ClkselValC{
            constexpr Register::FieldValue<decltype(clksel)::Type,ClkselVal::irc> irc{};
            constexpr Register::FieldValue<decltype(clksel)::Type,ClkselVal::pclk> pclk{};
            constexpr Register::FieldValue<decltype(clksel)::Type,ClkselVal::rtcosc> rtcosc{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///If this bit is set to one writing to this register does not affect bit 0. The clock source can only be changed by first clearing this bit, then writing the new value of bit 0.
        enum class LockVal {
            unlocked=0x00000000,     ///<This bit is set to 0 on any reset. It cannot be cleared by software.
            locked=0x00000001,     ///<Software can set this bit to 1 at any time. Once WDLOCK is set, the bits of this register                                        cannot be modified.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,LockVal> lock{}; 
        namespace LockValC{
            constexpr Register::FieldValue<decltype(lock)::Type,LockVal::unlocked> unlocked{};
            constexpr Register::FieldValue<decltype(lock)::Type,LockVal::locked> locked{};
        }
    }
}
