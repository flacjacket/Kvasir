#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Group GPIO input interrupt 1
    namespace Gint1Ctrl{    ///<GPIO grouped interrupt control register
        using Addr = Register::Address<0x40014000,0x00000000,0x00000000,unsigned>;
        ///Group interrupt status. This bit is cleared by writing a                                one to it. Writing zero has no effect.
        enum class Int_Val {
            noRequest=0x00000000,     ///<No request. No interrupt request is                                        pending.
            requestActive=0x00000001,     ///<Request active. Interrupt request is                                        active.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Int_Val> int_{}; 
        namespace Int_ValC{
            constexpr Register::FieldValue<decltype(int_)::Type,Int_Val::noRequest> noRequest{};
            constexpr Register::FieldValue<decltype(int_)::Type,Int_Val::requestActive> requestActive{};
        }
        ///Combine enabled inputs for group interrupt
        enum class CombVal {
            or_=0x00000000,     ///<Or. OR functionality: A grouped interrupt is                                        generated when any one of the enabled inputs is active                                        (based on its programmed polarity).
            and_=0x00000001,     ///<And. AND functionality: An interrupt is generated                                        when all enabled bits are active (based on their programmed                                        polarity).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,CombVal> comb{}; 
        namespace CombValC{
            constexpr Register::FieldValue<decltype(comb)::Type,CombVal::or_> or_{};
            constexpr Register::FieldValue<decltype(comb)::Type,CombVal::and_> and_{};
        }
        ///Group interrupt trigger
        enum class TrigVal {
            edgeTriggered=0x00000000,     ///<Edge-triggered.
            levelTriggered=0x00000001,     ///<Level-triggered.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,TrigVal> trig{}; 
        namespace TrigValC{
            constexpr Register::FieldValue<decltype(trig)::Type,TrigVal::edgeTriggered> edgeTriggered{};
            constexpr Register::FieldValue<decltype(trig)::Type,TrigVal::levelTriggered> levelTriggered{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Gint1PortPol0{    ///<GPIO grouped interrupt port 0 polarity register
        using Addr = Register::Address<0x40014020,0x00000000,0x00000000,unsigned>;
        ///Configure pin polarity of port m pins for group interrupt.                                Bit n corresponds to pin PIOm_n of port m. 0 = the pin is active                                LOW. If the level on this pin is LOW, the pin contributes to the                                group interrupt. 1 = the pin is active HIGH. If the level on this                                pin is HIGH, the pin contributes to the group                                interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> pol{}; 
    }
    namespace Gint1PortPol1{    ///<GPIO grouped interrupt port 0 polarity register
        using Addr = Register::Address<0x40014024,0x00000000,0x00000000,unsigned>;
        ///Configure pin polarity of port m pins for group interrupt.                                Bit n corresponds to pin PIOm_n of port m. 0 = the pin is active                                LOW. If the level on this pin is LOW, the pin contributes to the                                group interrupt. 1 = the pin is active HIGH. If the level on this                                pin is HIGH, the pin contributes to the group                                interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> pol{}; 
    }
    namespace Gint1PortPol2{    ///<GPIO grouped interrupt port 0 polarity register
        using Addr = Register::Address<0x40014028,0x00000000,0x00000000,unsigned>;
        ///Configure pin polarity of port m pins for group interrupt.                                Bit n corresponds to pin PIOm_n of port m. 0 = the pin is active                                LOW. If the level on this pin is LOW, the pin contributes to the                                group interrupt. 1 = the pin is active HIGH. If the level on this                                pin is HIGH, the pin contributes to the group                                interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> pol{}; 
    }
    namespace Gint1PortEna0{    ///<GPIO grouped interrupt port 0 enable register
        using Addr = Register::Address<0x40014040,0x00000000,0x00000000,unsigned>;
        ///Enable port 0 pin for group interrupt. Bit n corresponds to                                pin Pm_n of port m. 0 = the port 0 pin is disabled and does not                                contribute to the grouped interrupt. 1 = the port 0 pin is enabled                                and contributes to the grouped interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> ena{}; 
    }
    namespace Gint1PortEna1{    ///<GPIO grouped interrupt port 0 enable register
        using Addr = Register::Address<0x40014044,0x00000000,0x00000000,unsigned>;
        ///Enable port 0 pin for group interrupt. Bit n corresponds to                                pin Pm_n of port m. 0 = the port 0 pin is disabled and does not                                contribute to the grouped interrupt. 1 = the port 0 pin is enabled                                and contributes to the grouped interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> ena{}; 
    }
    namespace Gint1PortEna2{    ///<GPIO grouped interrupt port 0 enable register
        using Addr = Register::Address<0x40014048,0x00000000,0x00000000,unsigned>;
        ///Enable port 0 pin for group interrupt. Bit n corresponds to                                pin Pm_n of port m. 0 = the port 0 pin is disabled and does not                                contribute to the grouped interrupt. 1 = the port 0 pin is enabled                                and contributes to the grouped interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> ena{}; 
    }
    namespace Gint1PortPol0{    ///<GPIO grouped interrupt port 0 polarity register
        using Addr = Register::Address<0x40014020,0x00000000,0x00000000,unsigned>;
        ///Configure pin polarity of port m pins for group interrupt.                                Bit n corresponds to pin PIOm_n of port m. 0 = the pin is active                                LOW. If the level on this pin is LOW, the pin contributes to the                                group interrupt. 1 = the pin is active HIGH. If the level on this                                pin is HIGH, the pin contributes to the group                                interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> pol{}; 
    }
    namespace Gint1PortPol1{    ///<GPIO grouped interrupt port 0 polarity register
        using Addr = Register::Address<0x40014024,0x00000000,0x00000000,unsigned>;
        ///Configure pin polarity of port m pins for group interrupt.                                Bit n corresponds to pin PIOm_n of port m. 0 = the pin is active                                LOW. If the level on this pin is LOW, the pin contributes to the                                group interrupt. 1 = the pin is active HIGH. If the level on this                                pin is HIGH, the pin contributes to the group                                interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> pol{}; 
    }
    namespace Gint1PortPol2{    ///<GPIO grouped interrupt port 0 polarity register
        using Addr = Register::Address<0x40014028,0x00000000,0x00000000,unsigned>;
        ///Configure pin polarity of port m pins for group interrupt.                                Bit n corresponds to pin PIOm_n of port m. 0 = the pin is active                                LOW. If the level on this pin is LOW, the pin contributes to the                                group interrupt. 1 = the pin is active HIGH. If the level on this                                pin is HIGH, the pin contributes to the group                                interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> pol{}; 
    }
    namespace Gint1PortEna0{    ///<GPIO grouped interrupt port 0 enable register
        using Addr = Register::Address<0x40014040,0x00000000,0x00000000,unsigned>;
        ///Enable port 0 pin for group interrupt. Bit n corresponds to                                pin Pm_n of port m. 0 = the port 0 pin is disabled and does not                                contribute to the grouped interrupt. 1 = the port 0 pin is enabled                                and contributes to the grouped interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> ena{}; 
    }
    namespace Gint1PortEna1{    ///<GPIO grouped interrupt port 0 enable register
        using Addr = Register::Address<0x40014044,0x00000000,0x00000000,unsigned>;
        ///Enable port 0 pin for group interrupt. Bit n corresponds to                                pin Pm_n of port m. 0 = the port 0 pin is disabled and does not                                contribute to the grouped interrupt. 1 = the port 0 pin is enabled                                and contributes to the grouped interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> ena{}; 
    }
    namespace Gint1PortEna2{    ///<GPIO grouped interrupt port 0 enable register
        using Addr = Register::Address<0x40014048,0x00000000,0x00000000,unsigned>;
        ///Enable port 0 pin for group interrupt. Bit n corresponds to                                pin Pm_n of port m. 0 = the port 0 pin is disabled and does not                                contribute to the grouped interrupt. 1 = the port 0 pin is enabled                                and contributes to the grouped interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> ena{}; 
    }
}
