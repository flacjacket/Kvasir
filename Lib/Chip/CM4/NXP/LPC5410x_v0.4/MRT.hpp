#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Multi-Rate Timer
    namespace MrtModcfg{    ///<Module Configuration register. This register provides information                        about this particular MRT instance, and allows choosing an overall mode for                        the idle channel feature.
        using Addr = Register::Address<0x400740f0,0x00000000,0x00000000,unsigned>;
        ///Identifies the number of channels in this                                MRT.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> noc{}; 
        ///Identifies the number of timer bits in this                                MRT.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,4),Register::ReadWriteAccess,unsigned> nob{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Selects the operating mode for the INUSE flags and the                                IDLE_CH register. See Idle channel register (IDLE_CH) for                                details.
        enum class MultitaskVal {
            hardwareStatusMode=0x00000000,     ///<Hardware status mode. In this mode, the INUSE(n)                                        flags for all channels are reset.
            multiTaskMode=0x00000001,     ///<Multi-task mode.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,MultitaskVal> multitask{}; 
        namespace MultitaskValC{
            constexpr Register::FieldValue<decltype(multitask)::Type,MultitaskVal::hardwareStatusMode> hardwareStatusMode{};
            constexpr Register::FieldValue<decltype(multitask)::Type,MultitaskVal::multiTaskMode> multiTaskMode{};
        }
    }
    namespace MrtIdleCh{    ///<Idle channel register. This register returns the number of the                        first idle channel.
        using Addr = Register::Address<0x400740f4,0x00000000,0x00000000,unsigned>;
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Idle channel. Reading the CHAN bits, returns the lowest                                idle timer channel. The number is positioned such that it can be                                used as an offset from the MRT base address in order to access the                                registers for the allocated channel. If all timer channels are                                running, CHAN = 0xF. See text above for more details.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> chan{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtIrqFlag{    ///<Global interrupt flag register
        using Addr = Register::Address<0x400740f8,0x00000000,0x00000000,unsigned>;
        ///Monitors the interrupt flag of TIMER0.
        enum class Gflag0Val {
            noPendingInterrupt=0x00000000,     ///<No pending interrupt. Writing a zero is equivalent                                        to no operation.
            pendingInterrupt=0x00000001,     ///<Pending interrupt. The interrupt is pending because                                        TIMER0 has reached the end of the time interval. If the                                        INTEN bit in the CONTROL0 register is also set to 1, the                                        interrupt for timer channel 0 and the global interrupt are                                        raised. Writing a 1 to this bit clears the interrupt                                        request.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Gflag0Val> gflag0{}; 
        namespace Gflag0ValC{
            constexpr Register::FieldValue<decltype(gflag0)::Type,Gflag0Val::noPendingInterrupt> noPendingInterrupt{};
            constexpr Register::FieldValue<decltype(gflag0)::Type,Gflag0Val::pendingInterrupt> pendingInterrupt{};
        }
        ///Monitors the interrupt flag of TIMER1. See description of                                channel 0.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> gflag1{}; 
        ///Monitors the interrupt flag of TIMER2. See description of                                channel 0.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> gflag2{}; 
        ///Monitors the interrupt flag of TIMER3. See description of                                channel 0.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> gflag3{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,4),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtIntval0{    ///<MRTn Time interval value register. This value is loaded into the                        TIMER0 register.
        using Addr = Register::Address<0x40074000,0x00000000,0x00000000,unsigned>;
        ///Time interval load value. This value is loaded into the                                TIMERn register and the MRT channel n starts counting down from                                IVALUE -1. If the timer is idle, writing a non-zero value to this                                bit field starts the timer immediately. If the timer is running,                                writing a zero to this bit field does the following: If LOAD = 1,                                the timer stops immediately. If LOAD = 0, the timer stops at the end                                of the time interval.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> ivalue{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,24),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Determines how the timer interval value IVALUE -1 is loaded                                into the TIMERn register. This bit is write-only. Reading this bit                                always returns 0.
        enum class LoadVal {
            noForceLoad=0x00000000,     ///<No force load. The load from the INTVALn register                                        to the TIMERn register is processed at the end of the time                                        interval if the repeat mode is selected.
            forceLoad=0x00000001,     ///<Force load. The INTVALn interval value IVALUE -1 is                                        immediately loaded into the TIMERn register while TIMERn is                                        running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,LoadVal> load{}; 
        namespace LoadValC{
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::noForceLoad> noForceLoad{};
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::forceLoad> forceLoad{};
        }
    }
    namespace MrtIntval1{    ///<MRTn Time interval value register. This value is loaded into the                        TIMER0 register.
        using Addr = Register::Address<0x40074010,0x00000000,0x00000000,unsigned>;
        ///Time interval load value. This value is loaded into the                                TIMERn register and the MRT channel n starts counting down from                                IVALUE -1. If the timer is idle, writing a non-zero value to this                                bit field starts the timer immediately. If the timer is running,                                writing a zero to this bit field does the following: If LOAD = 1,                                the timer stops immediately. If LOAD = 0, the timer stops at the end                                of the time interval.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> ivalue{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,24),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Determines how the timer interval value IVALUE -1 is loaded                                into the TIMERn register. This bit is write-only. Reading this bit                                always returns 0.
        enum class LoadVal {
            noForceLoad=0x00000000,     ///<No force load. The load from the INTVALn register                                        to the TIMERn register is processed at the end of the time                                        interval if the repeat mode is selected.
            forceLoad=0x00000001,     ///<Force load. The INTVALn interval value IVALUE -1 is                                        immediately loaded into the TIMERn register while TIMERn is                                        running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,LoadVal> load{}; 
        namespace LoadValC{
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::noForceLoad> noForceLoad{};
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::forceLoad> forceLoad{};
        }
    }
    namespace MrtIntval2{    ///<MRTn Time interval value register. This value is loaded into the                        TIMER0 register.
        using Addr = Register::Address<0x40074020,0x00000000,0x00000000,unsigned>;
        ///Time interval load value. This value is loaded into the                                TIMERn register and the MRT channel n starts counting down from                                IVALUE -1. If the timer is idle, writing a non-zero value to this                                bit field starts the timer immediately. If the timer is running,                                writing a zero to this bit field does the following: If LOAD = 1,                                the timer stops immediately. If LOAD = 0, the timer stops at the end                                of the time interval.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> ivalue{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,24),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Determines how the timer interval value IVALUE -1 is loaded                                into the TIMERn register. This bit is write-only. Reading this bit                                always returns 0.
        enum class LoadVal {
            noForceLoad=0x00000000,     ///<No force load. The load from the INTVALn register                                        to the TIMERn register is processed at the end of the time                                        interval if the repeat mode is selected.
            forceLoad=0x00000001,     ///<Force load. The INTVALn interval value IVALUE -1 is                                        immediately loaded into the TIMERn register while TIMERn is                                        running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,LoadVal> load{}; 
        namespace LoadValC{
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::noForceLoad> noForceLoad{};
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::forceLoad> forceLoad{};
        }
    }
    namespace MrtIntval3{    ///<MRTn Time interval value register. This value is loaded into the                        TIMER0 register.
        using Addr = Register::Address<0x40074030,0x00000000,0x00000000,unsigned>;
        ///Time interval load value. This value is loaded into the                                TIMERn register and the MRT channel n starts counting down from                                IVALUE -1. If the timer is idle, writing a non-zero value to this                                bit field starts the timer immediately. If the timer is running,                                writing a zero to this bit field does the following: If LOAD = 1,                                the timer stops immediately. If LOAD = 0, the timer stops at the end                                of the time interval.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> ivalue{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,24),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Determines how the timer interval value IVALUE -1 is loaded                                into the TIMERn register. This bit is write-only. Reading this bit                                always returns 0.
        enum class LoadVal {
            noForceLoad=0x00000000,     ///<No force load. The load from the INTVALn register                                        to the TIMERn register is processed at the end of the time                                        interval if the repeat mode is selected.
            forceLoad=0x00000001,     ///<Force load. The INTVALn interval value IVALUE -1 is                                        immediately loaded into the TIMERn register while TIMERn is                                        running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,LoadVal> load{}; 
        namespace LoadValC{
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::noForceLoad> noForceLoad{};
            constexpr Register::FieldValue<decltype(load)::Type,LoadVal::forceLoad> forceLoad{};
        }
    }
    namespace MrtTimer0{    ///<MRTn Timer register. This register reads the value of the                        down-counter.
        using Addr = Register::Address<0x40074004,0x00000000,0x00000000,unsigned>;
        ///Holds the current timer value of the down-counter. The                                initial value of the TIMERn register is loaded as IVALUE - 1 from                                the INTVALn register either at the end of the time interval or                                immediately in the following cases: INTVALn register is updated in                                the idle state. INTVALn register is updated with LOAD = 1. When the                                timer is in idle state, reading this bit fields returns -1 (0x00FF                                FFFF).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> value{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtTimer1{    ///<MRTn Timer register. This register reads the value of the                        down-counter.
        using Addr = Register::Address<0x40074014,0x00000000,0x00000000,unsigned>;
        ///Holds the current timer value of the down-counter. The                                initial value of the TIMERn register is loaded as IVALUE - 1 from                                the INTVALn register either at the end of the time interval or                                immediately in the following cases: INTVALn register is updated in                                the idle state. INTVALn register is updated with LOAD = 1. When the                                timer is in idle state, reading this bit fields returns -1 (0x00FF                                FFFF).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> value{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtTimer2{    ///<MRTn Timer register. This register reads the value of the                        down-counter.
        using Addr = Register::Address<0x40074024,0x00000000,0x00000000,unsigned>;
        ///Holds the current timer value of the down-counter. The                                initial value of the TIMERn register is loaded as IVALUE - 1 from                                the INTVALn register either at the end of the time interval or                                immediately in the following cases: INTVALn register is updated in                                the idle state. INTVALn register is updated with LOAD = 1. When the                                timer is in idle state, reading this bit fields returns -1 (0x00FF                                FFFF).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> value{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtTimer3{    ///<MRTn Timer register. This register reads the value of the                        down-counter.
        using Addr = Register::Address<0x40074034,0x00000000,0x00000000,unsigned>;
        ///Holds the current timer value of the down-counter. The                                initial value of the TIMERn register is loaded as IVALUE - 1 from                                the INTVALn register either at the end of the time interval or                                immediately in the following cases: INTVALn register is updated in                                the idle state. INTVALn register is updated with LOAD = 1. When the                                timer is in idle state, reading this bit fields returns -1 (0x00FF                                FFFF).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,0),Register::ReadWriteAccess,unsigned> value{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtCtrl0{    ///<MRTn Control register. This register controls the MRTn                        modes.
        using Addr = Register::Address<0x40074008,0x00000000,0x00000000,unsigned>;
        ///Enable the TIMERn interrupt.
        enum class IntenVal {
            disabled=0x00000000,     ///<TIMERn interrupt is disabled.
            enabled=0x00000001,     ///<TIMERn interrupt is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntenVal> inten{}; 
        namespace IntenValC{
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::enabled> enabled{};
        }
        ///Selects timer mode.
        enum class ModeVal {
            repeatInterruptMod=0x00000000,     ///<Repeat interrupt mode.
            oneShotInterruptM=0x00000001,     ///<One-shot interrupt mode.
            oneShotStallMode=0x00000002,     ///<One-shot stall mode.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,1),Register::ReadWriteAccess,ModeVal> mode{}; 
        namespace ModeValC{
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::repeatInterruptMod> repeatInterruptMod{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotInterruptM> oneShotInterruptM{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotStallMode> oneShotStallMode{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtCtrl1{    ///<MRTn Control register. This register controls the MRTn                        modes.
        using Addr = Register::Address<0x40074018,0x00000000,0x00000000,unsigned>;
        ///Enable the TIMERn interrupt.
        enum class IntenVal {
            disabled=0x00000000,     ///<TIMERn interrupt is disabled.
            enabled=0x00000001,     ///<TIMERn interrupt is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntenVal> inten{}; 
        namespace IntenValC{
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::enabled> enabled{};
        }
        ///Selects timer mode.
        enum class ModeVal {
            repeatInterruptMod=0x00000000,     ///<Repeat interrupt mode.
            oneShotInterruptM=0x00000001,     ///<One-shot interrupt mode.
            oneShotStallMode=0x00000002,     ///<One-shot stall mode.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,1),Register::ReadWriteAccess,ModeVal> mode{}; 
        namespace ModeValC{
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::repeatInterruptMod> repeatInterruptMod{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotInterruptM> oneShotInterruptM{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotStallMode> oneShotStallMode{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtCtrl2{    ///<MRTn Control register. This register controls the MRTn                        modes.
        using Addr = Register::Address<0x40074028,0x00000000,0x00000000,unsigned>;
        ///Enable the TIMERn interrupt.
        enum class IntenVal {
            disabled=0x00000000,     ///<TIMERn interrupt is disabled.
            enabled=0x00000001,     ///<TIMERn interrupt is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntenVal> inten{}; 
        namespace IntenValC{
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::enabled> enabled{};
        }
        ///Selects timer mode.
        enum class ModeVal {
            repeatInterruptMod=0x00000000,     ///<Repeat interrupt mode.
            oneShotInterruptM=0x00000001,     ///<One-shot interrupt mode.
            oneShotStallMode=0x00000002,     ///<One-shot stall mode.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,1),Register::ReadWriteAccess,ModeVal> mode{}; 
        namespace ModeValC{
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::repeatInterruptMod> repeatInterruptMod{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotInterruptM> oneShotInterruptM{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotStallMode> oneShotStallMode{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtCtrl3{    ///<MRTn Control register. This register controls the MRTn                        modes.
        using Addr = Register::Address<0x40074038,0x00000000,0x00000000,unsigned>;
        ///Enable the TIMERn interrupt.
        enum class IntenVal {
            disabled=0x00000000,     ///<TIMERn interrupt is disabled.
            enabled=0x00000001,     ///<TIMERn interrupt is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntenVal> inten{}; 
        namespace IntenValC{
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(inten)::Type,IntenVal::enabled> enabled{};
        }
        ///Selects timer mode.
        enum class ModeVal {
            repeatInterruptMod=0x00000000,     ///<Repeat interrupt mode.
            oneShotInterruptM=0x00000001,     ///<One-shot interrupt mode.
            oneShotStallMode=0x00000002,     ///<One-shot stall mode.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,1),Register::ReadWriteAccess,ModeVal> mode{}; 
        namespace ModeValC{
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::repeatInterruptMod> repeatInterruptMod{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotInterruptM> oneShotInterruptM{};
            constexpr Register::FieldValue<decltype(mode)::Type,ModeVal::oneShotStallMode> oneShotStallMode{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtStat0{    ///<MRTn Status register.
        using Addr = Register::Address<0x4007400c,0x00000000,0x00000000,unsigned>;
        ///Monitors the interrupt flag.
        enum class IntflagVal {
            noPendingInterrupt=0x00000000,     ///<No pending interrupt. Writing a zero is equivalent                                        to no operation.
            pendingInterrupt=0x00000001,     ///<Pending interrupt. The interrupt is pending because                                        TIMERn has reached the end of the time interval. If the                                        INTEN bit in the CONTROLn is also set to 1, the interrupt                                        for timer channel n and the global interrupt are raised.                                        Writing a 1 to this bit clears the interrupt                                        request.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntflagVal> intflag{}; 
        namespace IntflagValC{
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::noPendingInterrupt> noPendingInterrupt{};
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::pendingInterrupt> pendingInterrupt{};
        }
        ///Indicates the state of TIMERn. This bit is                                read-only.
        enum class RunVal {
            idleState=0x00000000,     ///<Idle state. TIMERn is stopped.
            running=0x00000001,     ///<Running. TIMERn is running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,RunVal> run{}; 
        namespace RunValC{
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::idleState> idleState{};
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::running> running{};
        }
        ///Channel In Use flag. Operating details depend on the                                MULTITASK bit in the MODCFG register, and affects the use of                                IDLE_CH. 
        enum class InuseVal {
            no=0x00000000,     ///<This channel is not in use.
            yes=0x00000001,     ///<This channel is in use.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,InuseVal> inuse{}; 
        namespace InuseValC{
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::no> no{};
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::yes> yes{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,2),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtStat1{    ///<MRTn Status register.
        using Addr = Register::Address<0x4007401c,0x00000000,0x00000000,unsigned>;
        ///Monitors the interrupt flag.
        enum class IntflagVal {
            noPendingInterrupt=0x00000000,     ///<No pending interrupt. Writing a zero is equivalent                                        to no operation.
            pendingInterrupt=0x00000001,     ///<Pending interrupt. The interrupt is pending because                                        TIMERn has reached the end of the time interval. If the                                        INTEN bit in the CONTROLn is also set to 1, the interrupt                                        for timer channel n and the global interrupt are raised.                                        Writing a 1 to this bit clears the interrupt                                        request.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntflagVal> intflag{}; 
        namespace IntflagValC{
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::noPendingInterrupt> noPendingInterrupt{};
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::pendingInterrupt> pendingInterrupt{};
        }
        ///Indicates the state of TIMERn. This bit is                                read-only.
        enum class RunVal {
            idleState=0x00000000,     ///<Idle state. TIMERn is stopped.
            running=0x00000001,     ///<Running. TIMERn is running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,RunVal> run{}; 
        namespace RunValC{
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::idleState> idleState{};
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::running> running{};
        }
        ///Channel In Use flag. Operating details depend on the                                MULTITASK bit in the MODCFG register, and affects the use of                                IDLE_CH. 
        enum class InuseVal {
            no=0x00000000,     ///<This channel is not in use.
            yes=0x00000001,     ///<This channel is in use.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,InuseVal> inuse{}; 
        namespace InuseValC{
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::no> no{};
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::yes> yes{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,2),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtStat2{    ///<MRTn Status register.
        using Addr = Register::Address<0x4007402c,0x00000000,0x00000000,unsigned>;
        ///Monitors the interrupt flag.
        enum class IntflagVal {
            noPendingInterrupt=0x00000000,     ///<No pending interrupt. Writing a zero is equivalent                                        to no operation.
            pendingInterrupt=0x00000001,     ///<Pending interrupt. The interrupt is pending because                                        TIMERn has reached the end of the time interval. If the                                        INTEN bit in the CONTROLn is also set to 1, the interrupt                                        for timer channel n and the global interrupt are raised.                                        Writing a 1 to this bit clears the interrupt                                        request.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntflagVal> intflag{}; 
        namespace IntflagValC{
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::noPendingInterrupt> noPendingInterrupt{};
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::pendingInterrupt> pendingInterrupt{};
        }
        ///Indicates the state of TIMERn. This bit is                                read-only.
        enum class RunVal {
            idleState=0x00000000,     ///<Idle state. TIMERn is stopped.
            running=0x00000001,     ///<Running. TIMERn is running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,RunVal> run{}; 
        namespace RunValC{
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::idleState> idleState{};
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::running> running{};
        }
        ///Channel In Use flag. Operating details depend on the                                MULTITASK bit in the MODCFG register, and affects the use of                                IDLE_CH. 
        enum class InuseVal {
            no=0x00000000,     ///<This channel is not in use.
            yes=0x00000001,     ///<This channel is in use.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,InuseVal> inuse{}; 
        namespace InuseValC{
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::no> no{};
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::yes> yes{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,2),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MrtStat3{    ///<MRTn Status register.
        using Addr = Register::Address<0x4007403c,0x00000000,0x00000000,unsigned>;
        ///Monitors the interrupt flag.
        enum class IntflagVal {
            noPendingInterrupt=0x00000000,     ///<No pending interrupt. Writing a zero is equivalent                                        to no operation.
            pendingInterrupt=0x00000001,     ///<Pending interrupt. The interrupt is pending because                                        TIMERn has reached the end of the time interval. If the                                        INTEN bit in the CONTROLn is also set to 1, the interrupt                                        for timer channel n and the global interrupt are raised.                                        Writing a 1 to this bit clears the interrupt                                        request.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,IntflagVal> intflag{}; 
        namespace IntflagValC{
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::noPendingInterrupt> noPendingInterrupt{};
            constexpr Register::FieldValue<decltype(intflag)::Type,IntflagVal::pendingInterrupt> pendingInterrupt{};
        }
        ///Indicates the state of TIMERn. This bit is                                read-only.
        enum class RunVal {
            idleState=0x00000000,     ///<Idle state. TIMERn is stopped.
            running=0x00000001,     ///<Running. TIMERn is running.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,RunVal> run{}; 
        namespace RunValC{
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::idleState> idleState{};
            constexpr Register::FieldValue<decltype(run)::Type,RunVal::running> running{};
        }
        ///Channel In Use flag. Operating details depend on the                                MULTITASK bit in the MODCFG register, and affects the use of                                IDLE_CH. 
        enum class InuseVal {
            no=0x00000000,     ///<This channel is not in use.
            yes=0x00000001,     ///<This channel is in use.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,InuseVal> inuse{}; 
        namespace InuseValC{
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::no> no{};
            constexpr Register::FieldValue<decltype(inuse)::Type,InuseVal::yes> yes{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,2),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
