#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//CRC engine
    namespace CrcMode{    ///<CRC mode register
        using Addr = Register::Address<0x1c010000,0x00000000,0x00000000,unsigned>;
        ///CRC polynom: 1X= CRC-32 polynomial 01= CRC-16 polynomial                                00= CRC-CCITT polynomial
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,unsigned> crcPoly{}; 
        ///Data bit order: 1= Bit order reverse for CRC_WR_DATA (per                                byte) 0= No bit order reverse for CRC_WR_DATA (per                                byte)
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> bitRvsWr{}; 
        ///Data complement: 1= 1s complement for CRC_WR_DATA 0= No 1s                                complement for CRC_WR_DATA
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> cmplWr{}; 
        ///CRC sum bit order: 1= Bit order reverse for CRC_SUM 0= No                                bit order reverse for CRC_SUM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> bitRvsSum{}; 
        ///CRC sum complement: 1= 1s complement for CRC_SUM 0=No 1s                                complement for CRC_SUM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> cmplSum{}; 
        ///Always 0 when read
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,6),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace CrcSeed{    ///<CRC seed register
        using Addr = Register::Address<0x1c010004,0x00000000,0x00000000,unsigned>;
        ///A write access to this register will load CRC seed value to                                CRC_SUM register with selected bit order and 1s complement                                pre-processes. A write access to this register will overrule the CRC                                calculation in progresses.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> crcSeed{}; 
    }
    namespace CrcSum{    ///<CRC checksum register
        using Addr = Register::Address<0x1c010008,0x00000000,0x00000000,unsigned>;
        ///The most recent CRC sum can be read through this register                                with selected bit order and 1s complement                                post-processes.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> crcSum{}; 
    }
    namespace CrcWrData{    ///<CRC data register
        using Addr = Register::Address<0x1c010008,0x00000000,0x00000000,unsigned>;
        ///Data written to this register will be taken to perform CRC                                calculation with selected bit order and 1s complement pre-process.                                Any write size 8, 16 or 32-bit are allowed and accept back-to-back                                transactions.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> crcWrData{}; 
    }
}
