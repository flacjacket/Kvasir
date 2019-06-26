#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Registers group
    namespace GcrPdid{    ///<Part Device Identification number Register
        using Addr = Register::Address<0x50000000,0x00000000,0x00000000,unsigned>;
        ///This register reflects device part number code. S/W can read this register to identify which device is used.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pdid{}; 
    }
    namespace GcrRstsrc{    ///<System Reset Source Register
        using Addr = Register::Address<0x50000004,0xffffffff,0x00000000,unsigned>;
        ///The RSTS_POR flag is set by the "reset signal" which is from the Power-On Reset (POR) module or bit CHIP_RST (IPRSTC1[0]) is set, to indicate the previous reset source.1= The Power-On-Reset(POR) or CHIP_RST=1 had issued the reset signal to reset the system.0= No reset from PORThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsPor{}; 
        ///The RSTS_RESET flag is set by the "reset signal" from the /RESET pin to indicate the previous reset source.1= The Pin /RESET had issued the reset signal to reset the system.0= No reset from Pin /RESETThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsReset{}; 
        ///The RSTS_WDT flag is set by the "reset signal" from the Watch Dog Timer to indicate the previous reset source.1= The Watch Dog Timer had issued the reset signal to reset the system.0= No reset from Watch-DogThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsWdt{}; 
        ///The RSTS_LVR flag is set by the "reset signal" from the Low-Voltage-Reset module to indicate the previous reset source.1= The LVR module had issued the reset signal to reset the system.0= No reset from LVRThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsLvr{}; 
        ///The RSTS_BOD flag is set by the "reset signal" from the Brown-Out-Detected module to indicate the previous reset source.1= The Brown-Out-Detected module had issued the reset signal to reset the system.0= No reset from BODThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsBod{}; 
        ///The RSTS_MCU flag is set by the "reset signal" from the MCU Cortex_M0 kernel to indicate the previous reset source.1= The MCU Cortex_M0 had issued the reset signal to reset the system by software writing 1 to bit SYSRESTREQ(AIRCR[2], Application Interrupt and Reset Control Register) in system control registers of Cortex_M0 kernel.0= No reset from MCUThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsMcu{}; 
        ///The RSTS_CPU flag is set by hardware if software writes CPU_RST (IPRSTC1[1]) with a "1" to rest Cortex-M0 CPU kernel and Flash memory controller(FMC).1= The Cortex-M0 CPU kernel and FMC are reset by software set CPU_RST to 1.0= No reset from CPUThis bit is cleared by writing 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> rstsCpu{}; 
    }
    namespace GcrIprstc1{    ///<IP Reset Control Resister1
        using Addr = Register::Address<0x50000008,0xfffffff4,0x00000000,unsigned>;
        ///CHIP one shot reset.Set this bit will reset the CHIP, including CPU kernel and all peripherals, and this bit will automatically return to "0" after the 2 clock cycles.The CHIP_RST is same as the POR reset , all the chip module is reset and the chip setting from flash are also reloadThis bit is the protected bit, program this need an open lock sequence, write "59h","16h","88h" to address 0x5000_0100 to un-lock this bit. Reference the register REGWRPROT at address GCR_BA + 0x1000= Normal1= Reset CHIP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::modify>,unsigned> chipRst{}; 
        ///CPU kernel one shot reset.Set this bit will reset the Cortex-M0 CPU kernel and Flash memory controller (FMC). This bit will automatically return to "0" after the 2 clock cyclesThis bit is the protected bit, program this need an open lock sequence, write "59h","16h","88h" to address 0x5000_0100 to un-lock this bit. Reference the register REGWRPROT at address GCR_BA + 0x1000= Normal1= Reset CPU
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::modify>,unsigned> cpuRst{}; 
        ///EBI Controller ResetSet these bit "1" will generate a reset signal to the EBI. User need to set this bit to "0" to release from the reset stateThis bit is the protected bit, program this need an open lock sequence, write "59h","16h","88h" to address 0x5000_0100 to un-lock this bit. Reference the register REGWRPROT at address GCR_BA + 0x1000= Normal operation1= EBI IP reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ebiRst{}; 
    }
    namespace GcrIprstc2{    ///<IP Reset Control Resister 2
        using Addr = Register::Address<0x5000000c,0xefcccec1,0x00000000,unsigned>;
        ///GPIO (P0~P4) controller Reset0= GPIO controller normal operation1= GPIO controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> gpioRst{}; 
        ///Timer0 controller Reset0= Timer0 controller normal operation1= Timer0 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> tmr0Rst{}; 
        ///Timer1 controller Reset0= Timer1 controller normal operation1= Timer1 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> tmr1Rst{}; 
        ///Timer2 controller Reset0= Timer2 controller normal operation1= Timer2 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> tmr2Rst{}; 
        ///Timer3 controller Reset0= Timer3 controller normal operation1= Timer3 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> tmr3Rst{}; 
        ///I2C controller Reset0= I2C controller normal operation1= I2C controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> i2cRst{}; 
        ///SPI0 controller Reset0= SPI0 controller normal operation1= SPI0 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> spi0Rst{}; 
        ///SPI1 controller Reset0= SPI1 controller normal operation1= SPI1 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> spi1Rst{}; 
        ///UART0 controller Reset0= UART0 controller Normal operation1= UART0 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> uart0Rst{}; 
        ///UART1 controller Reset0 = UART1 controller normal operation1 = UART1 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> uart1Rst{}; 
        ///PWM0~3 controller Reset0= PWM0~3 controller normal operation1= PWM0~3 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> pwm03Rst{}; 
        ///PWM4~7 controller Reset0= PWM4~7 controller normal operation1= PWM4~7 controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> pwm47Rst{}; 
        ///ADC Controller Reset0= ADC controller normal operation1= ADC controller reset
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(28,28),Register::ReadWriteAccess,unsigned> adcRst{}; 
    }
    namespace GcrBodcr{    ///<Brown Out Detector Control Register
        using Addr = Register::Address<0x50000018,0xffffff10,0x00000000,unsigned>;
        ///Brown Out Detector Enable (initiated & write-protected bit)The default value is set by flash controller user configuration register config0 bit[23]1= Brown Out Detector function is enabled0= Brown Out Detector function is disabled
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> bodEn{}; 
        ///Brown Out Detector Threshold Voltage Selection (initiated & write-protected bit)The default value is set by flash controller user configuration register config0 bit[22:21]BOV_VL[1]    BOV_VL[0]    Brown out voltage    1    1    4.5V    1    0    3.8V    0    1    2.7V    0    0    2.2V    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,1),Register::ReadWriteAccess,unsigned> bodVl{}; 
        ///Brown Out Reset Enable (initiated & write-protected bit)1= Enable the Brown Out "RESET" function, when the Brown Out Detector function is enable and the detected voltage is lower than the threshold then assert a signal to reset the chipThe default value is set by flash controller user configuration register config0 bit[20]0= Enable the Brown Out "INTERRUPT" function, when the Brown Out Detector function is enable and the detected voltage is lower than the threshold then assert a signal to interrupt the MCU Cortex-M0When the BOD_EN is enabled and the interrupt is assert, the interrupt will keep till to the BOD_EN set to "0". The interrupt for CPU can be blocked by disable the NVIC in CPU for BOD interrupt or disable the interrupt source by disable the BOD_EN and then re-enable the BOD_EN function if the BOD function is required
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> bodRsten{}; 
        ///Brown Out Detector Interrupt Flag1= When Brown Out Detector detects the VDD is dropped through the voltage of BOD_VL setting or the VDD is raised up through the voltage of BOD_VL setting, this bit is set to "1" and the brown out interrupt is requested if brown out interrupt is enabled.0= Brown Out Detector does not detect any voltage draft at VDD down through or up through the voltage of BOD_VL setting.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> bodIntf{}; 
        ///Brown Out Detector Low power Mode (write-protected bit)1= Enable the BOD low power mode0= BOD operate in normal mode (default)The BOD consumes about 100uA in normal mode, the low power mode can reduce the current to about 1/10 but slow the BOD response.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> bodLpm{}; 
        ///The status for Brown Out Detector output state1= Brown Out Detector status output is 1, the detected voltage is lower than BOD_VL setting. If the BOD_EN is "0"(disabled), this bit always response "0"0= Brown Out Detector status output is 0, the detected voltage is higher than BOD_VL setting
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> bodOut{}; 
        ///Low Voltage Reset Enable (write-protected bit)The LVR function reset the chip when the input power voltage is lower than LVR circuit setting. LVR function is enabled in default.1= Enabled Low Voltage Reset function - After enable the bit, the LVR function will active with 100uS delay for LVR output stable.(default).0= Disabled Low Voltage Reset function
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> lvrEn{}; 
    }
    namespace GcrPorcr{    ///<Power-On-Reset Controller Register
        using Addr = Register::Address<0x50000024,0xffff0000,0x00000000,unsigned>;
        ///The register is used for the Power-On-Reset enable control. When power on, the POR circuit generates a reset signal to reset the whole chip function, but noise on the power may cause the POR active again. If set the POR_DIS_CODE equal to 0x5AA5, the POR reset function will be disabled and the POR function will re-active till the power voltage is lower to set the POR_DIS_CODE to another value or reset by chip other reset function. Include:PIN reset, Watch dog, LVR reset BOD reset, ICE reset command and the software-chip reset functionThis register is the protected register, program this need an open lock sequence, write "59h","16h","88h" to address 0x5000_0100 to un-lock this bit. Reference the register REGWRPROT at address GCR_BA + 0x100
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> porDisCode{}; 
    }
    namespace GcrP0Mfp{    ///<P0 multiple function and input type control register
        using Addr = Register::Address<0x50000030,0xff000000,0x00000000,unsigned>;
        ///P0 multiple function SelectionThe pin function of P0 is depending on P0_MFP and P0_ALT.Refer to P0_ALT descriptions in detail.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> p0Mfp{}; 
        ///P0.0 alternate function SelectionThe pin function of P0.0 is depend on P0_MFP[0] and P0_ALT[0].P0_ALT[0]    P0_MFP[0]    P0.0function    0    0    P0.0    0    1    AD0(EBI)    1    0    CTS1(UART1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> p0Alt0{}; 
        ///P0.1 alternate function SelectionThe pin function of P0.1 is depend on P0_MFP[1] and P0_ALT[1].P0_ALT[1]    P0_MFP[1]    P0.1function    0    0    P0.1    0    1    AD1(EBI)    1    0    RTS1(UART1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> p0Alt1{}; 
        ///P0.2 alternate function SelectionThe pin function of P0.2 is depend on P0_MFP[2] and P0_ALT[2].P0_ALT[2]    P0_MFP[2]    P0.2function    0    0    P0.2    0    1    AD2(EBI)    1    0    CTS0(UART0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> p0Alt2{}; 
        ///P0.3 alternate function SelectionThe pin function of P0.3 is depend on P0_MFP[3] and P0_ALT[3].P0_ALT[3]    P0_MFP[3]    P0.3function    0    0    P0.3    0    1    AD3(EBI)    1    0    RTS0(UART0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> p0Alt3{}; 
        ///P0.4 alternate function SelectionThe pin function of P0.4 is depend on P0_MFP[4] and P0_ALT[4].P0_ALT[4]    P0_MFP[4]    P0.4function    0    0    P0.4    0    1    AD4(EBI)    1    0    SPISS1(SPI1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> p0Alt4{}; 
        ///P0.5 alternate function SelectionThe pin function of P0.5 is depend on P0_MFP[5] and P0_ALT[5].P0_ALT[5]    P0_MFP[5]    P0.5 function    0    0    P0.5    0    1    AD5(EBI)    1    0    MOSI_1(SPI1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> p0Alt5{}; 
        ///P0.6 alternate function SelectionThe pin function of P0.6 is depend on P0_MFP[6] and P0_ALT[6].P0_ALT[6]    P0_MFP[6]    P0.6 function    0    0    P0.6    0    1    AD6(EBI)    1    0    MISO_1(SPI1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> p0Alt6{}; 
        ///P0.7 alternate function SelectionThe pin function of P0.7 is depend on P0_MFP[7] and P0_ALT[7].P0_ALT[7]    P0_MFP[7]    P0.7 function    0    0    P0.7    0    1    AD7(EBI)    1    0    SPICLK1(SPI1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> p0Alt7{}; 
        ///P0[7:0] input Schmitt Trigger function Enable1= P0[7:0] I/O input Schmitt Trigger function enable0= P0[7:0] I/O input Schmitt Trigger function disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> p0Typen{}; 
    }
    namespace GcrP1Mfp{    ///<P1 multiple function and input type control register
        using Addr = Register::Address<0x50000034,0xff000000,0x00000000,unsigned>;
        ///P1 multiple function SelectionThe pin function of P1 is depending on P1_MFP and P1_ALT.Refer to P1_ALT descriptions in detail.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> p1Mfp{}; 
        ///P1.0 alternate function SelectionThe pin function of P1.0 is depend on P1_MFP[0] and P1_ALT[0].P1_ALT[0]    P1_MFP[0]    P1.0function    0    0    P1.0    0    1    AIN0(ADC)    1    0    T2(Timer2)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> p1Alt0{}; 
        ///P1.1 alternate function SelectionThe pin function of P1.1 is depend on P1_MFP[1] and P1_ALT[1].P1_ALT[1]    P1_MFP[1]    P1.1function    0    0    P1.1    0    1    AIN1(ADC)    1    0    T3(Timer3)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> p1Alt1{}; 
        ///P1.2 alternate function SelectionThe pin function of P1.2 is depend on P1_MFP[2] and P1_ALT[2].P1_ALT[2]    P1_MFP[2]    P1.2function    0    0    P1.2    0    1    AIN2(ADC)    1    0    RXD1(UART1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> p1Alt2{}; 
        ///P1.3 alternate function SelectionThe pin function of P1.3 is depend on P1_MFP[3] and P1_ALT[3].P1_ALT[3]    P1_MFP[3]    P1.3function    0    0    P1.3    0    1    AIN3(ADC)    1    0    TXD1(UART1)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> p1Alt3{}; 
        ///P1.4 alternate function SelectionThe pin function of P1.4 is depend on P1_MFP[4] and P1_ALT[4].P1_ALT[4]    P1_MFP[4]    P1.4function    0    0    P1.4    0    1    AIN4(ADC)    1    0    SPISS0(SPI0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> p1Alt4{}; 
        ///P1.5 alternate function SelectionThe pin function of P1.5 is depend on P1_MFP[5] and P1_ALT[5].P1_ALT[5]    P1_MFP[5]    P1.5 function    0    0    P1.5    0    1    AIN5(ADC)    1    0    MOSI_0(SPI0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> p1Alt5{}; 
        ///P1.6 alternate function SelectionThe pin function of P1.6 is depend on P1_MFP[6] and P1_ALT[6].P1_ALT[6]    P1_MFP[6]    P1.6 function    0    0    P1.6    0    1    AIN6(ADC)    1    0    MISO_0(SPI0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> p1Alt6{}; 
        ///P1.7 alternate function SelectionThe pin function of P1.7 is depend on P1_MFP[7] and P1_ALT[7].P1_ALT[7]    P1_MFP[7]    P1.7 function    0    0    P1.7    0    1    AIN7(ADC)    1    0    SPICLK0(SPI0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> p1Alt7{}; 
        ///P1[7:0] input Schmitt Trigger function Enable1= P1[7:0] I/O input Schmitt Trigger function enable0= P1[7:0] I/O input Schmitt Trigger function disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> p1Typen{}; 
    }
    namespace GcrP2Mfp{    ///<P2 multiple function and input type control register
        using Addr = Register::Address<0x50000038,0xff000000,0x00000000,unsigned>;
        ///P2 multiple function SelectionThe pin function of P2 is depending on P2_MFP and P2_ALT.Refer to P2_ALT descriptions in detail.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> p2Mfp{}; 
        ///P2.0 alternate function SelectionThe pin function of P2.0 is depend on P2_MFP[0] and P2_ALT[0].P2_ALT[0]    P2_MFP[0]    P2.0function    0    0    P2.0    0    1    AD8(EBI)    1    0    PWM0(PWM generator 0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> p2Alt0{}; 
        ///P2.1 alternate function SelectionThe pin function of P2.1 is depend on P2_MFP[1] and P2_ALT[1].P2_ALT[1]    P2_MFP[1]    P2.1function    0    0    P2.1    0    1    AD9(EBI)    1    0    PWM1(PWM generator 0)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> p2Alt1{}; 
        ///P2.2 alternate function SelectionThe pin function of P2.2 is depend on P2_MFP[2] and P2_ALT[2].P2_ALT[2]    P2_MFP[2]    P2.2function    0    0    P2.2    0    1    AD10(EBI)    1    0    PWM2(PWM generator 2)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> p2Alt2{}; 
        ///P2.3 alternate function SelectionThe pin function of P2.3 is depend on P2_MFP[3] and P2_ALT[3].P2_ALT[3]    P2_MFP[3]    P2.3function    0    0    P2.3    0    1    AD11(EBI)    1    0    PWM3(PWM generator 2)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> p2Alt3{}; 
        ///P2.4 alternate function SelectionThe pin function of P2.4 is depend on P2_MFP[4] and P2_ALT[4].P2_ALT[4]    P2_MFP[4]    P0.4function    0    0    P0.4    0    1    AD12(EBI)    1    0    PWM4(PWM generator 4)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> p2Alt4{}; 
        ///P2.5 alternate function SelectionThe pin function of P2.5 is depend on P2_MFP[5] and P2_ALT[5].P2_ALT[5]    P2_MFP[5]    P2.5 function    0    0    P2.5    0    1    AD13(EBI)    1    0    PWM5(PWM generator 4)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> p2Alt5{}; 
        ///P2.6 alternate function SelectionThe pin function of P2.6 is depend on P2_MFP[6] and P2_ALT[6].P2_ALT[6]    P2_MFP[6]    P2.6 function    0    0    P2.6    0    1    AD14(EBI)    1    0    PWM6(PWM generator 6)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> p2Alt6{}; 
        ///P2.7 alternate function SelectionThe pin function of P2.7 is depend on P2_MFP[7] and P2_ALT[7].P2_ALT[7]    P2_MFP[7]    P2.7 function    0    0    P2.7    0    1    AD15(EBI)    1    0    PWM7(PWM generator 6)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> p2Alt7{}; 
        ///P2[7:0] input Schmitt Trigger function Enable1= P2[7:0] I/O input Schmitt Trigger function enable0= P2[7:0] I/O input Schmitt Trigger function disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> p2Typen{}; 
    }
    namespace GcrP3Mfp{    ///<P3 multiple function and input type control register
        using Addr = Register::Address<0x5000003c,0xff000000,0x00000000,unsigned>;
        ///P3 multiple function SelectionThe pin function of P3 is depending on P3_MFP and P3_ALT.Refer to P3_ALT descriptions in detail.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> p3Mfp{}; 
        ///P3.0 alternate function SelectionThe pin function of P3.0 is depend on P3_MFP[0] and P3_ALT[0].P3_ALT[0]    P3_MFP[0]    P3.0function    0    0    P3.0    0    1    RXD(UART0)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> p3Alt0{}; 
        ///P3.1 alternate function SelectionThe pin function of P3.1 is depend on P3_MFP[1] and P3_ALT[1].P3_ALT[1]    P3_MFP[1]    P3.1function    0    0    P3.1    0    1    TXD(UART0)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> p3Alt1{}; 
        ///P3.2 alternate function SelectionThe pin function of P3.2 is depend on P3_MFP[2] and P3_ALT[2].P3_ALT[2]    P3_MFP[2]    P3.2function    0    0    P3.2    0    1    /INT0    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> p3Alt2{}; 
        ///P3.3 alternate function SelectionThe pin function of P3.3 is depend on P3_MFP[3] and P3_ALT[3].P3_ALT[3]    P3_MFP[3]    P3.3function    0    0    P3.3    0    1    /INT1    1    0    MCLK(EBI)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> p3Alt3{}; 
        ///P3.4 alternate function SelectionThe pin function of P3.4 is depend on P3_MFP[4] and P3_ALT[4].P3_ALT[4]    P3_MFP[4]    P3.4function    0    0    P3.4    0    1    T0(Timer0)    1    0    SDA(I2C)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> p3Alt4{}; 
        ///P3.5 alternate function SelectionThe pin function of P3.5 is depend on P3_MFP[5] and P3_ALT[5].P3_ALT[5]    P3_MFP[5]    P3.5 function    0    0    P3.5    0    1    T1(Timer1)    1    0    SCL(I2C)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> p3Alt5{}; 
        ///P3.6 alternate function SelectionThe pin function of P3.6 is depend on P3_MFP[6] and P3_ALT[6].P3_ALT[6]    P3_MFP[6]    P3.6 function    0    0    P3.6    0    1    WR(EBI)    1    0    CKO(Clock Driver output)    1    1    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> p3Alt6{}; 
        ///P3.7 alternate function SelectionThe pin function of P3.7 is depend on P3_MFP[7] and P3_ALT[7].P3_ALT[7]    P3_MFP[7]    P3.7 function    0    0    P3.7    0    1    RD(EBI)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> p3Alt7{}; 
        ///P3[7:0] input Schmitt Trigger function Enable1= P3[7:0] I/O input Schmitt Trigger function enable0= P3[7:0] I/O input Schmitt Trigger function disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> p3Typen{}; 
    }
    namespace GcrP4Mfp{    ///<P4 input type control register
        using Addr = Register::Address<0x50000040,0xff000000,0x00000000,unsigned>;
        ///P4 multiple function SelectionThe pin function of P4 is depending on P4_MFP and P4_ALT.Refer to P4_ALT descriptions in detail.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> p4Mfp{}; 
        ///P4.0 alternate function SelectionThe pin function of P4.0 is depend on P4_MFP[0] and P4_ALT[0].P4_ALT[0]    P4_MFP[0]    P4.0function    0    0    P4.0    0    1    PWM0(PWM generator 0)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> p4Alt0{}; 
        ///P4.1 alternate function SelectionThe pin function of P4.1 is depend on P4_MFP[1] and P4_ALT[1].P4_ALT[1]    P4_MFP[1]    P4.1function    0    0    P4.1    0    1    PWM1(PWM generator 0)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> p4Alt1{}; 
        ///P4.2 alternate function SelectionThe pin function of P4.2 is depend on P4_MFP[2] and P4_ALT[2].P4_ALT[2]    P4_MFP[2]    P4.2function    0    0    P4.2    0    1    PWM2(PWM generator 2)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> p4Alt2{}; 
        ///P4.3 alternate function SelectionThe pin function of P4.3 is depend on P4_MFP[3] and P4_ALT[3].P4_ALT[3]    P4_MFP[3]    P4.3function    0    0    P4.3    0    1    PWM3(PWM generator 2)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> p4Alt3{}; 
        ///P4.4 alternate function SelectionThe pin function of P4.4 is depend on P4_MFP[4] and P4_ALT[4].P4_ALT[4]    P4_MFP[4]    P4.4function    0    0    P4.4    0    1    /CS(EBI)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> p4Alt4{}; 
        ///P4.5 alternate function SelectionThe pin function of P4.5 is depend on P4_MFP[5] and P4_ALT[5].P4_ALT[5]    P4_MFP[5]    P4.5 function    0    0    P4.5    0    1    ALE(EBI)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> p4Alt5{}; 
        ///P4.6 alternate function SelectionThe pin function of P4.6 is depend on P4_MFP[6] and P4_ALT[6].P4_ALT[6]    P4_MFP[6]    P4.6 function    0    0    P4.6    0    1    ICE_CLK(ICE)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> p4Alt6{}; 
        ///P4.7 alternate function SelectionThe pin function of P4.7 is depend on P4_MFP[7] and P4_ALT[7].P4_ALT[7]    P4_MFP[7]    P4.7 function    0    0    P4.7    0    1    ICE_DAT(ICE)    1    x    Reserved    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> p4Alt7{}; 
        ///P4[7:0] input Schmitt Trigger function Enable1= P4[7:0] I/O input Schmitt Trigger function enable0= P4[7:0] I/O input Schmitt Trigger function disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> p4Typen{}; 
    }
    namespace GcrRegwrprot{    ///<Register Lock Key address
        using Addr = Register::Address<0x50000100,0xffffff00,0x00000000,unsigned>;
        ///Register Write-Protected Code (Write Only)Some write-protected registers have to be disabled the protected function by writing the sequence value "59h", "16h", "88h" to this field. After this sequence is completed, the REGPROTDIS bit will be set to 1 and write-protected registers can be normal write.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::Access<Register::AccessType::writeOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> regwrprot{}; 
        ///Register Write-Protected Disable index (Read only)1 = Protection is disabled for writing protected registers0 = Protection is enabled for writing protected registers. Any write to the protected register is ignored.The Write-Protected registers list are below table:Registers    Address    Note    IPRSTC1    0x5000_0008    None    BODCR    0x5000_0018    None    PORCR    0x5000_001C    None    PWRCON    0x5000_0200    bit[6] is not protected for power wake-up interrupt clear    APBCLK bit[0]    0x5000_0208    bit[0] is watch dog clock enable    CLKSEL0    0x5000_0210    HCLK and CPU STCLK clock source select    CLK_SEL1 bit[1:0]    0x5000_0214    Watch dog clock source select    ISPCON    0x5000_C000    Flash ISP Control register    WTCR    0x4000_4000    None    FATCON    0x5000_C018    None    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> regprotdis{}; 
    }
}
