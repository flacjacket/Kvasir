#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Registers group
    namespace Uart2UaRbr{    ///<Receive Buffer Register.
        using Addr = Register::Address<0x40154000,0xffffff00,0x00000000,unsigned>;
        ///Receive Buffer RegisterBy reading this register, the UART will return an 8-bit data received from Rx pin (LSB first).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::modify,Register::ModifiedWriteValueType::normal>,unsigned> rbr{}; 
    }
    namespace Uart2UaThr{    ///<Transmit Holding Register.
        using Addr = Register::Address<0x40154000,0xffffff00,0x00000000,unsigned>;
        ///Transmit Holding RegisterBy writing to this register, the UART will send out an 8-bit data through the TX pin (LSB first).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::Access<Register::AccessType::writeOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::modify>,unsigned> thr{}; 
    }
    namespace Uart2UaIer{    ///<Interrupt Enable Register.
        using Addr = Register::Address<0x40154004,0xffffffff,0x00000000,unsigned>;
        ///Receive Data Available Interrupt Enable.0 = Mask off INT_RDA1 = Enable INT_RDA
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rdaIen{}; 
        ///Transmit Holding Register Empty Interrupt Enable0 = Mask off INT_THRE1 = Enable INT_THRE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> threIen{}; 
        ///Receive Line Status Interrupt Enable0 = Mask off INT_RLS1 = Enable INT_RLS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rlsIen{}; 
        ///Modem Status Interrupt Enable0 = Mask off INT_MODEM1 = Enable INT_MODEM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> modemIen{}; 
        ///Rx Time out Interrupt Enable0 = Mask off INT_TOUT1 = Enable INT_TOUT.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rtoIen{}; 
        ///Buffer Error Interrupt Enable0 = Mask off INT_Buf_ERR1 = Enable INT_Buf_ERR
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> bufErrIen{}; 
        ///Wake up CPU function enable0 = Disable UART wake up CPU function1 = Enable wake up function, when the system is in deep sleep mode, an external /CTS change will wake up CPU from deep sleep mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> wakeEn{}; 
        ///LIN RX Break Field Detected Interrupt Enable0 = Mask off Lin bus Rx break filed interrupt.1 = Enable Lin bus Rx break filed interrupt.Note: This field is used for LIN function mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> linRxBrkIen{}; 
        ///Time-Out Counter Enable1 = Enable Time-out counter.0 = Disable Time-out counter.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> timeOutEn{}; 
        ///RTS Auto Flow Control Enable1 = Enable RTS auto flow control.0 = Disable RTS auto flow control.When RTS auto-flow is enabled, if the number of bytes in the Rx FIFO equals the UA_FCR[RTS_Tri_Lev], the UART will de-assert RTS signal.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> autoRtsEn{}; 
        ///CTS Auto Flow Control Enable1 = Enable CTS auto flow control.0 = Disable CTS auto flow control.When CTS auto-flow is enabled, the UART will send data to external device when CTS input assert (UART will not send data to device until CTS is asserted).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> autoCtsEn{}; 
        ///TX DMA Enable 1 = Enable TX DMA.0 = Disable TX DMA.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> dmaTxEn{}; 
        ///Time-Out Counter Enable1 = Enable RX DMA.0 = Disable RX DMA.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> dmaRxEn{}; 
    }
    namespace Uart2UaFcr{    ///<FIFO Control Register.
        using Addr = Register::Address<0x40154008,0xffffffff,0x00000000,unsigned>;
        ///Rx Field Software ResetWhen Rx_RST is set, all the bytes in the transmit FIFO and Rx internal state machine are cleared.0 = Writing 0 to this bit has no effect.1 = Writing 1 to this bit will reset the Rx internal state machine and pointers.Note: This bit will auto clear needs at least 3 UART engine clock cycles.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rfr{}; 
        ///Tx Field Software ResetWhen Tx_RST is set, all the bytes in the transmit FIFO and Tx internal state machine are cleared.0 = Writing 0 to this bit has no effect.1 = Writing 1 to this bit will reset the Tx internal state machine and pointers.Note: This bit will auto clear needs at least 3 UART engine clock cycles.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> tfr{}; 
        ///Rx FIFO Interrupt (INT_RDA) Trigger Level When the number of bytes in the receive FIFO equals the RFITL then the RDA_IF will be set (if IER [RDA_IEN] is enable, an interrupt will generated).RFITL    INTR_RDA Trigger Level (Bytes)    0000    01    0001    04    0010    08    0011    14    0100    30/14 (High Speed/Normal Speed)    0101    46/14 (High Speed/Normal Speed)    0110    62/14 (High Speed/Normal Speed)    others    62/14 (High Speed/Normal Speed)    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rfitl{}; 
        ///Receiver Disable registerThe receiver is disabled or not (set 1 is disable receiver)1 = Disable Receiver.0 = Enable Receiver.Note: This field is used for RS-485 Normal Multi-drop mode. It should be programmed before UA_ALT_CSR [RS-485_NMM] is programmed.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rxDis{}; 
        ///RTS Trigger Level for Auto-flow Control Use(not available in UART2 channel)RTS_Tri_Lev    Trigger Level (Bytes)    0000    01    0001    04    0010    08    0011    14    0100    30/14 (High Speed/Normal Speed)    0101    46/14 (High Speed/Normal Speed)    0110    62/14 (High Speed/Normal Speed)    others    62/14 (High Speed/Normal Speed)    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,16),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rtsTriLev{}; 
    }
    namespace Uart2UaLcr{    ///<Line Control Register.
        using Addr = Register::Address<0x4015400c,0xfffffff7,0x00000000,unsigned>;
        ///Word Length SelectWLS[1:0]    Character length    00    5 bits    01    6 bits    10    7 bits    11    8 bits    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> wls{}; 
        ///Number of "STOP bit"0= One "STOP bit" is generated in the transmitted data1= One and a half "STOP bit" is generated in the transmitted data when 5-bit word length is selected;Two "STOP bit" is generated when 6-, 7- and 8-bit word length is selected.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> nsb{}; 
        ///Parity Bit Enable0 = Parity bit is not generated (transmit data) or checked (receive data) during transfer.1 = Parity bit is generated or checked between the "last data word bit" and "stop bit" of the serial data.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pbe{}; 
        ///Even Parity Enable0 = Odd number of logic 1's are transmitted or checked in the data word and parity bits.1 = Even number of logic 1's are transmitted or checked in the data word and parity bits.This bit has effect only when bit 3 (parity bit enable) is set.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> epe{}; 
        ///Stick Parity Enable 0 = Disable stick parity 1 = When bits PBE , EPE and SPE are set, the parity bit is transmitted and checked as cleared. When PBE and SPE are set and EPE is cleared, the parity bit is transmitted and checked as set.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> spe{}; 
        ///Break Control Bit When this bit is set to logic 1, the serial data output (TX) is forced to the Spacing State (logic 0). This bit acts only on TX and has no effect on the transmitter logic.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> bcb{}; 
    }
    namespace Uart2UaMcr{    ///<Modem Control Register.
        using Addr = Register::Address<0x40154010,0xffffdfff,0x00000000,unsigned>;
        ///RTS (Request-To-Send) Signal (not available in UART2 channel)0: Drive RTS pin to logic 1 (If the LEV_RTS set to low level triggered).1: Drive RTS pin to logic 0 (If the LEV_RTS set to low level triggered).0: Drive RTS pin to logic 0 (If the LEV_RTS set to hihg level triggered).1: Drive RTS pin to logic 1 (If the LEV_RTS set to high level triggered).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rts{}; 
        ///RTS Trigger Level (not available in UART2 channel)This bit can change the RTS trigger level.0= low level triggered1= high level triggered
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> levRts{}; 
        ///RTS Pin State (not available in UART2 channel)This bit is the output pin status of RTS.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rtsSt{}; 
    }
    namespace Uart2UaMsr{    ///<Modem Status Register.
        using Addr = Register::Address<0x40154014,0xffffffef,0x00000000,unsigned>;
        ///Detect CTS State Change Flag (not available in UART2 channel)This bit is set whenever CTS input has change state, and it will generate Modem interrupt to CPU when UA_IER [Modem_IEN] is set to 1.NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> dctsf{}; 
        ///CTS Pin Status (not available in UART2 channel)This bit is the pin status of CTS. 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> ctsSt{}; 
        ///CTS Trigger Level (not available in UART2 channel)This bit can change the CTS trigger level.0= low level triggered1= high level triggered
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> levCts{}; 
    }
    namespace Uart2UaFsr{    ///<FIFO Status Register.
        using Addr = Register::Address<0x40154018,0xee000086,0x00000000,unsigned>;
        ///Rx overflow Error IF (Read Only) This bit is set when Rx FIFO overflow.If the number of bytes of received data is greater than Rx FIFO(UA_RBR) size, 64/16 bytes of (UA_RBR), this bit will be set.NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rxOverIf{}; 
        ///RS-485 Address Byte Detection Flag (Read Only) (Low Density Only)This bit is set to logic 1 and set UA_ALT_CSR [RS485_ADD_EN] whenever in RS-485 mode the receiver detect any address byte received address byte character (bit9 = 1) bit, and it is reset whenever the CPU writes 1 to this bit.NOTE: This field is used for RS-485 function mode.NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rs485AddDetf{}; 
        ///Parity Error FlagThis bit is set to logic 1 whenever the received character does not have a valid "parity bit", and is reset whenever the CPU writes 1 to this bit.NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pef{}; 
        ///Framing Error FlagThis bit is set to logic 1 whenever the received character does not have a valid "stop bit" (that is, the stop bit following the last data bit or parity bit is detected as a logic 0), and is reset whenever the CPU writes 1 to this bit.NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> fef{}; 
        ///Break Interrupt FlagThis bit is set to a logic 1 whenever the received data input(Rx) is held in the "spacing state" (logic 0) for longer than a full word transmission time (that is, the total time of "start bit" + data bits + parity + stop bits) and is reset whenever the CPU writes 1 to this bit.NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> bif{}; 
        ///Rx FIFO pointer (Read Only)This field indicates the Rx FIFO Buffer Pointer. When UART receives one byte from external device, Rx_Pointer increases one. When one byte of Rx FIFO is read by CPU, Rx_Pointer decreases one.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,8),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rxPointer{}; 
        ///Receiver FIFO Empty (Read Only)This bit initiate Rx FIFO empty or not.When the last byte of Rx FIFO has been read by CPU, hardware sets this bit high. It will be cleared when UART receives any new data.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rxEmpty{}; 
        ///Receiver FIFO Full (Read Only)This bit initiates Rx FIFO full or not.This bit is set when RX_POINTER is equal to 64/16(UART0/UART1), otherwise is cleared by hardware.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rxFull{}; 
        ///TX FIFO Pointer (Read Only)This field indicates the Tx FIFO Buffer Pointer. When CPU write one byte into UA_THR, Tx_Pointer increases one. When one byte of Tx FIFO is transferred to Transmitter Shift Register, Tx_Pointer decreases one.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(21,16),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> txPointer{}; 
        ///Transmitter FIFO Empty (Read Only)This bit indicates Tx FIFO empty or not.When the last byte of Tx FIFO has been transferred to Transmitter Shift Register, hardware sets this bit high. It will be cleared when writing data into THR (Tx FIFO not empty).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,22),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> txEmpty{}; 
        ///Transmitter FIFO Full (Read Only)This bit indicates Tx FIFO full or not.This bit is set when Tx_Point is equal to 64/16(UART0/UART1), otherwise is cleared by hardware.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,23),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> txFull{}; 
        ///Tx Overflow Error Interrupt Flag (Read Only)If Tx FIFO(UA_THR) is full, an additional write to UA_THR will cause this bit to logic 1. NOTE: This bit is read only, but can be cleared by writing '1' to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> txOverIf{}; 
        ///Transmitter Empty Flag (Read Only)Bit is set by hardware when Tx FIFO(UA_THR) is empty and the STOP bit of the last byte has been transmitted.Bit is cleared automatically when Tx FIFO is not empty or the last byte transmission has not completed.NOTE: This bit is read only. 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(28,28),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> teFlag{}; 
    }
    namespace Uart2UaIsr{    ///<Interrupt Status Register.
        using Addr = Register::Address<0x4015401c,0x43434040,0x00000000,unsigned>;
        ///Receive Data Available Interrupt Flag (Read Only).When the number of bytes in the Rx FIFO equals the RFITL then the RDA_IF will be set. If IER[RDA_IEN] is enabled, the RDA interrupt will be generated. NOTE: This bit is read only and it will be cleared when the number of unread bytes of Rx FIFO drops below the threshold level (RFITL).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rdaIf{}; 
        ///Transmit Holding Register Empty Interrupt Flag (Read Only). This bit is set when the last data of TX FIFO is transferred to Transmitter Shift Register. If UA_IER[THRE_IEN] is enabled, the THRE interrupt will be generated.NOTE: This bit is read only and it will be cleared when writing data into THR (TX FIFO not empty).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> threIf{}; 
        ///Receive Line Interrupt Flag (Read Only).This bit is set when the Rx receive data have parity error, framing error or break error (at least one of 3 bits, BIF, FEF and PEF, is set). If IER[RLS_IEN] is enabled, the RLS interrupt will be generated.NOTE: This bit is read only and reset to 0 when all bits of BIF, FEF and PEF are cleared.NOTE: When in RS-485 function mode, this field include "receiver detect any address byte received address byte character (bit9 = 1') bit. "
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rlsIf{}; 
        ///MODEM Interrupt Flag (Read Only) (not available in UART2 channel)This bit is set when the CTS pin has state change(DCTSF=1). if UA_IER[Modem_IEN] is enabled, the Modem interrupt will be generated.NOTE: This bit is read only and reset to 0 when bit DCTSF is cleared by a write 1 on DCTSF.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> modemIf{}; 
        ///Time Out Interrupt Flag (Read Only)This bit is set when the RX FIFO is not empty and no activities occurres in the RX FIFO and the time out counter equal to TOIC. If IER[Tout_IEN] is enabled, the Tout interrupt will be generated. NOTE: This bit is read only and user can read UA_RBR (Rx is in active) to clear it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> toutIf{}; 
        ///Buffer Error Interrupt Flag (Read Only)This bit is set when the TX or RX FIFO overflows (TX_Over_IF or RX_Over_IF is set). When BUF_ERR_IF is set, the transfer maybe is not correct. If UA_IER[BUF_ERR_IEN] is enabled, the buffer error interrupt will be generated.NOTE: This bit is cleared when both TX_OVER_IF and RX_OVER_IF are cleared. 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> bufErrIf{}; 
        ///LIN Bus RX Break Field Detected FlagThis bit is set when RX received LIN Break Field. If UA_IER[LIN_RX_BRK_IEN] is enabled the LIN RX Break interrupt will be generated.NOTE: This bit is read only and user can write 1 to clear it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> linRxBreakIf{}; 
        ///Receive Data Available Interrupt Indicator (INT_RDA).This bit is set if RDA_IEN and RDA_IF are both set to 1.1 = The RDA interrupt is generated.0 = No RDA interrupt is generated .
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rdaInt{}; 
        ///Transmit Holding Register Empty Interrupt Indicator (INT_THRE).This bit is set if THRE_IEN and THRE_IF are both set to 1.1 = The THRE interrupt is generated.0 = No THRE interrupt is generated.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> threInt{}; 
        ///Receive Line Status Interrupt Indicator to (INT_RLS).This bit is set if RLS_IEN and RLS_IF are both set to 1.1 = The RLS interrupt is generated.0 = No RLS interrupt is generated.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> rlsInt{}; 
        ///MODEM Status Interrupt Indicator to (INT_MOS).This bit is set if MODEM_IEN and MODEM_IF are both set to 1..1 = The Modem interrupt is generated.0 = No Modem interrupt is generated.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> modemInt{}; 
        ///Time Out Interrupt Indicator (INT_Tout)This bit is set if TOUT_IEN and TOUT_IF are both set to 1.1 = The Tout interrupt is generated.0 = No Tout interrupt is generated.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> toutInt{}; 
        ///Buffer Error Interrupt Indicator (INT_Buf_err)This bit is set if BUF_ERR_IEN and BUF_ERR_IF are both set to 1.1 = The buffer error interrupt is generated.0 = No buffer error interrupt is generated.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> bufErrInt{}; 
        ///LIN Bus Rx Break Field Detected Interrupt Indicator This bit is set if LIN_RX_BRK_IEN and LIN_RX_BREAK_IF are both set to 1.1 = The LIN RX Break interrupt is generated.0 = No LIN RX Break interrupt is generated.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::Access<Register::AccessType::read-writeOnce,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> linRxBreakInt{}; 
        ///In DMA mode, Receive Line Status Flag (Read Only)This bit is set when the Rx receive data have parity error, framing error or break error (at least one of 3 bits, BIF, FEF and PEF, is set). If IER[RLS_IEN] is enabled, the RLS interrupt will be generated.NOTE: This bit is read only and reset to 0 when all bits of BIF, FEF and PEF are cleared.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> hwRlsIf{}; 
        ///In DMA mode, MODEM Interrupt Flag (Read Only) (not available in UART2 channel)This bit is set when the CTS pin has state change(DCTSF=1). if IER[Modem_IEN] is enabled, the Modem interrupt will be generated.NOTE: This bit is read only and reset to 0 when bit DCTSF is cleared by a write 1 on DCTSF.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> hwModemIf{}; 
        ///In DMA mode, Time out Interrupt Flag (Read Only)This bit is set when the Rx FIFO is not empty and no activities occurres in the Rx FIFO and the time out counter equal to TOIC. If IER[Tout_IEN] is enabled, the Tout interrupt will be generated. NOTE: This bit is read only and user can read UA_RBR (Rx is in active) to clear it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> hwToutIf{}; 
        ///In DMA mode, Buffer Error Interrupt Flag (Read Only)This bit is set when the Tx or Rx FIFO overflows (Tx_Over_IF or Rx_Over_IF is set). When Buf_Err_IF is set, the transfer maybe is not correct. If IER[Buf_Err_IEN] is enabled, the buffer error interrupt will be generated.NOTE: This bit is cleared when both Tx_Over_IF and Rx_Over_IF are cleared.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> hwBufErrIf{}; 
        ///In DMA mode, LIN Bus Rx Break Field Detect Interrupt FlagThis bit is set when Rx received LIN Break Field. If IER[LIN_RX_BRK_IEN] is enabled the LIN RX Break interrupt will be generated.NOTE: This bit is read only and user can write 1 to clear it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,unsigned> hwLinRxBreakIf{}; 
        ///In DMA mode, Receive Line Status Interrupt Indicator (INT_RLS).This bit is set if RLS_IEN and HW_RLS_IF are both set to 1.1 = The RLS interrupt is generated in DMA mode.0 = No RLS interrupt is generated in DMA mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,unsigned> hwRlsInt{}; 
        ///In DMA mode, MODEM Status Interrupt Indicator (INT_MOS)(not available in UART2 channel).This bit is set if MODEM_IEN and HW_MODEM_IF are both set to 1.1 = The Modem interrupt is generated in DMA mode.0 = No Modem interrupt is generated in DMA mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,unsigned> hwModemInt{}; 
        ///In DMA mode, Time Out Interrupt Indicator (INT_Tout)This bit is set if TOUT_IEN and HW_TOUT_IF are both set to 1.1 = The Tout interrupt is generated in DMA mode.0 = No Tout interrupt is generated in DMA mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(28,28),Register::ReadWriteAccess,unsigned> hwToutInt{}; 
        ///In DMA mode, Buffer Error Interrupt Indicator(INT_Buf_err)This bit is set if BUF_ERR_IEN and HW_BUF_ERR_IF are both set to 1.1 = The buffer error interrupt is generated in DMA mode.0 = No buffer error interrupt is generated in DMA mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(29,29),Register::ReadWriteAccess,unsigned> hwBufErrInt{}; 
        ///In DMA mode, LIN Bus Rx Break Field Detected Interrupt IndicatorThis bit is set if LIN_RX_BRK_IEN and HW_LIN_RX_BREAK_IF are both set to 1.1 = The LIN RX Break interrupt is generated in DMA mode.0 = No LIN RX Break interrupt is generated in DMA mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,unsigned> hwLinRxBreakInt{}; 
    }
    namespace Uart2UaTor{    ///<Time Out Register
        using Addr = Register::Address<0x40154020,0xffffffff,0x00000000,unsigned>;
        ///Time Out Interrupt ComparatorThe time out counter resets and starts counting (the counting clock = baud rate) whenever the RX FIFO receives a new data word. Once the content of time out counter (TOUT_CNT) is equal to that of time out interrupt comparator (TOIC), a receiver time out interrupt (INTR_TOUT) is generated if UA_IER [RTO_IEN]. A new incoming data word or RX FIFO empty clears INTR_TOUT.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> toic{}; 
        ///TX Delay time value (Low Density Only)This field is use to programming the transfer delay time between the last stop bit and next start bit.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,8),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> dly{}; 
    }
    namespace Uart2UaBaud{    ///<Baud Rate Divisor Register
        using Addr = Register::Address<0x40154024,0xc0ffffff,0x00000000,unsigned>;
        ///Baud Rate Divider The field indicated the baud rate divider
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> brd{}; 
        ///Divider XThe baud rate divider M = X+1.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(27,24),Register::ReadWriteAccess,unsigned> dividerX{}; 
        ///Divider X equal 10 = Divider M = X (the equation of M = X+1, but Divider_X[27:24] must > =8)1 = Divider M = 1 (the equation of M = 1, but BRD[15:0] must >=3).Mode    DIV_X_EN     DIV_X_ONE     DIVIDER X     BRD     Baud rate equation     0     Disable     0     B    A    UART_CLK / [16 * (A+2)]    1     Enable     0     B    A    UART_CLK/[(B+1)*(A+2)],B must >= 8    2     Enable     1    Don't Care    A    UART_CLK / (A+2), A must >=3    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(28,28),Register::ReadWriteAccess,unsigned> divXOne{}; 
        ///Divider X EnableThe BRD = Baud Rate Divider, and the baud rate equation is Baud Rate = Clock / [ M * (BRD + 2) ] ; The default value of M is 16.0 = Disable divider X (the equation of M = 16)1 = Enable divider X (the equation of M = X+1, but Divider_X[27:24 must > =8).NOTE: When in IrDA mode, this bit must disable.Mode    DIV_X_EN     DIV_X_ONE     DIVIDER X     BRD     Baud rate equation     0     Disable     0     B    A    UART_CLK / [16 * (A+2)]    1     Enable     0     B    A    UART_CLK/[(B+1)*(A+2)],B must >= 8    2     Enable     1    Don't Care    A    UART_CLK / (A+2), A must >=3    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(29,29),Register::ReadWriteAccess,unsigned> divXEn{}; 
    }
    namespace Uart2UaIrcr{    ///<IrDA Control Register.
        using Addr = Register::Address<0x40154028,0xffffffbf,0x00000040,unsigned>;
        ///Enable IrDA Receiver1: Enable IrDA transmitter0: Enable IrDA receiver
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> txSelect{}; 
        ///INV_TX1= Inverse TX output signal0= No inversion
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> invTx{}; 
        ///INV_RX1= Inverse RX input signal0= No inversion
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::zeroToSet>,unsigned> invRx{}; 
    }
    namespace Uart2UaAltCsr{    ///<LIN Break Failed Count Register.
        using Addr = Register::Address<0x4015402c,0xffffffff,0x00000000,unsigned>;
        ///UART LIN Break Field LengthThis field indicates a 4-bit LIN TX break field count.NOTE: This break field length is UA_LIN_BKFL + 2
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> uaLinBkfl{}; 
        ///LIN RX Enable1 = Enable LIN RX mode.0 = Disable LIN RX mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> linRxEn{}; 
        ///LIN TX Break Mode Enable1 = Enable LIN TX Break mode.0 = Disable LIN TX Break mode.NOTE: When TX break field transfer operation finish, this will be cleared automatically.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> linTxEn{}; 
        ///RS-485 Normal Multi-drop Operation Mode (NMM) (Low Density Only)1 = Enable RS-485 Normal Multi-drop Operation Mode (NMM).0 = Disable RS-485 Normal Multi-drop Operation Mode (NMM).Note: It can't be active with RS485_AAD operation mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rs485Nmm{}; 
        ///RS-485 Auto Address Detection Operation Mode (AAD) (Low Density Only)1 = Enable RS-485 Auto Address Detection Operation Mode (AAD).0 = Disable RS-485 Auto Address Detection Operation Mode (AAD).Note: It can't be active with RS485_NMM operation mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rs485Aad{}; 
        ///RS-485 Auto Direction Mode (AUD) (Low Density Only)1 = Enable RS-485 Auto Direction Operation Mode (AUO).0 = Disable RS-485 Auto Direction Operation Mode (AUO).Note:This field is used for RS-485 any operation mode.Note: It can be active with RS-485_AAD or RS485_NMM operation mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rs485Aud{}; 
        ///RS-485 Address Detection Enable (Low Density Only)1 = Enable address detection mode.0 = Disable address detection mode.Note: This field is used for RS485 any operation mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> rs485AddEn{}; 
        ///Address match value register (Low Density Only)This field contains the RS-485 address match values.Note: This field is used for RS-485 auto address detection mode.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> addrMatch{}; 
    }
    namespace Uart2UaFunSel{    ///<Function Select Register.
        using Addr = Register::Address<0x40154030,0xffffffff,0x00000000,unsigned>;
        ///Function Select Enable00 = UART Function01 = Enable LIN Function10 = Enable IrDA Function11 = Enable RS-485 Function (Low Density Only)
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToSet>,unsigned> funSel{}; 
    }
}
