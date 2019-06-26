#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Product name title=UM10375 Chapter title=LPC13xx Windowed WatchDog Timer (WWDT) Modification date=4/19/2011 Major revision=2 Minor revision=1 
    namespace WwdtMod{    ///<Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer.
        using Addr = Register::Address<0x40004000,0x00000000,0x00000000,unsigned>;
        ///Watchdog enable bit. This bit is Set Only. Remark: Setting this bit to one also locks the watchdog clock source. Once the watchdog timer is enabled, the watchdog timer clock source cannot be changed. If the watchdog timer is needed in Deep-sleep mode, the watchdog clock source must be changed to watchdog oscillator before setting this bit to one.                            
        enum class WdenVal {
            stop=0x00000000,     ///<The watchdog timer is stopped.
            run=0x00000001,     ///<The watchdog timer is running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,WdenVal> wden{}; 
        namespace WdenValC{
            constexpr Register::FieldValue<decltype(wden)::Type,WdenVal::stop> stop{};
            constexpr Register::FieldValue<decltype(wden)::Type,WdenVal::run> run{};
        }
        ///Watchdog reset enable bit. This bit is Set Only.
        enum class WdresetVal {
            reset=0x00000000,     ///<A watchdog timeout will not cause a chip reset.
            interrupt=0x00000001,     ///<A watchdog timeout will cause a chip reset.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,WdresetVal> wdreset{}; 
        namespace WdresetValC{
            constexpr Register::FieldValue<decltype(wdreset)::Type,WdresetVal::reset> reset{};
            constexpr Register::FieldValue<decltype(wdreset)::Type,WdresetVal::interrupt> interrupt{};
        }
        ///Watchdog time-out flag. Set when the watchdog timer times out, by a feed error, or by events associated with WDPROTECT, cleared by software. Causes a chip reset if WDRESET = 1.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> wdtof{}; 
        ///Watchdog interrupt flag. Set when the timer reaches the value in WDWARNINT. Cleared by software.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> wdint{}; 
        ///Watchdog update mode. This bit is Set Only.
        enum class WdprotectVal {
            anytime=0x00000000,     ///<The watchdog reload value (WDTC) can be changed at any time.
            match=0x00000001,     ///<The watchdog reload value (WDTC) can be changed only after the counter is below the value of WDWARNINT and WDWINDOW. Note: this mode is intended for use only when WDRESET =1.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,WdprotectVal> wdprotect{}; 
        namespace WdprotectValC{
            constexpr Register::FieldValue<decltype(wdprotect)::Type,WdprotectVal::anytime> anytime{};
            constexpr Register::FieldValue<decltype(wdprotect)::Type,WdprotectVal::match> match{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,5),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace WwdtTc{    ///<Watchdog timer constant register. This register determines the time-out value.
        using Addr = Register::Address<0x40004004,0x00000000,0x00000000,unsigned>;
        ///Watchdog time-out interval.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> count{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace WwdtFeed{    ///<Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC.
        using Addr = Register::Address<0x40004008,0x00000000,0x00000000,unsigned>;
        ///Feed value should be 0xAA followed by 0x55.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> feed{}; 
        ///Reserved
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace WwdtTv{    ///<Watchdog timer value register. This register reads out the current value of the Watchdog timer.
        using Addr = Register::Address<0x4000400c,0x00000000,0x00000000,unsigned>;
        ///Counter timer value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> count{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace WwdtWarnint{    ///<Watchdog Warning Interrupt compare value.
        using Addr = Register::Address<0x40004014,0x00000000,0x00000000,unsigned>;
        ///Watchdog warning interrupt compare value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,0),Register::ReadWriteAccess,unsigned> warnint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,10),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace WwdtWindow{    ///<Watchdog Window compare value.
        using Addr = Register::Address<0x40004018,0x00000000,0x00000000,unsigned>;
        ///Watchdog window value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> window{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
