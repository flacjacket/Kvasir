#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Mailbox
    namespace MailboxIrq0{    ///<Interrupt request register for the Cortex-M0+ CPU.
        using Addr = Register::Address<0x1c02c000,0x00000000,0x00000000,unsigned>;
        ///If any bit is set, an interrupt request is sent to the                                Cortex-M0+ interrupt controller.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> intreq{}; 
    }
    namespace MailboxIrq0set{    ///<Set bits in IRQ0
        using Addr = Register::Address<0x1c02c004,0x00000000,0x00000000,unsigned>;
        ///Writing 1 sets the corresponding bit in the IRQ0                                register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> intreqset{}; 
    }
    namespace MailboxIrq0clr{    ///<Clear bits in IRQ0
        using Addr = Register::Address<0x1c02c008,0x00000000,0x00000000,unsigned>;
        ///Writing 1 clears the corresponding bit in the IRQ0                                register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> intreqclr{}; 
    }
    namespace MailboxIrq1{    ///<Interrupt request register for the Cortex M4 CPU.
        using Addr = Register::Address<0x1c02c010,0x00000000,0x00000000,unsigned>;
        ///If any bit is set, an interrupt request is sent to the                                Cortex-M0+ interrupt controller.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> intreq{}; 
    }
    namespace MailboxIrq1set{    ///<Set bits in IRQ1
        using Addr = Register::Address<0x1c02c014,0x00000000,0x00000000,unsigned>;
        ///Writing 1 sets the corresponding bit in the IRQ1                                register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> intreqset{}; 
    }
    namespace MailboxIrq1clr{    ///<Clear bits in IRQ1
        using Addr = Register::Address<0x1c02c018,0x00000000,0x00000000,unsigned>;
        ///Writing 1 clears the corresponding bit in the IRQ1                                register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> intreqclr{}; 
    }
    namespace MailboxMutex{    ///<Mutual exclusion register
        using Addr = Register::Address<0x1c02c0f8,0x00000000,0x00000000,unsigned>;
        ///Cleared when read, set when written. See usage description                                above.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ex{}; 
        ///Reserved
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,1),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
