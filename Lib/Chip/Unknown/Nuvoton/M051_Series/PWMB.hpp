#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Registers group
    namespace PwmbPpr{    ///<PWM Pre-scalar Register
        using Addr = Register::Address<0x40140000,0x00000000,0x00000000,unsigned>;
        ///Clock pre-scalar 0(PWM counter 0 & 1 for group A and PWM counter 4 & 5 for group B)Clock input is divided by (CP01 + 1) before it is fed to the corresponding PWM counterIf CP01=0, then the pre-scalar 0 output clock will be stopped. So corresponding PWM counter will be stopped also.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> cp01{}; 
        ///Clock pre-scalar 2(PWM counter 2 & 3 for group A and PWM counter 6 & 7 for group B)Clock input is divided by (CP23 + 1) before it is fed to the corresponding PWM counterIf CP23=0, then the pre-scalar 2 output clock will be stopped. So corresponding PWM counter will be stopped also.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,8),Register::ReadWriteAccess,unsigned> cp23{}; 
        ///Dead zone interval register for pair of channel 0 and channel 1(PWM0 and PWM1 pair for PWM group A, PWM4 and PWM5 pair for PWM group B)These 8 bits determine dead zone length.The unit time of dead zone length is received from corresponding CSR bits.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> dzi01{}; 
        ///Dead zone interval register for pair of channel 2 and channel 3(PWM2 and PWM3 pair for PWM group A, PWM6 and PWM7 pair for PWM group B)These 8 bits determine dead zone length.The unit time of dead zone length is received from corresponding CSR bits.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> dzi23{}; 
    }
    namespace PwmbCsr{    ///<PWM Clock Select Register
        using Addr = Register::Address<0x40140004,0xffff8888,0x00000000,unsigned>;
        ///Timer 0 Clock Source Selection(PWM timer 0 for group A and PWM timer 4 for group B)Select clock input for timer.(Table is the same as CSR3)
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> csr0{}; 
        ///Timer 1 Clock Source Selection(PWM timer 1 for group A and PWM timer 5 for group B)Select clock input for timer.(Table is the same as CSR3)
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,4),Register::ReadWriteAccess,unsigned> csr1{}; 
        ///Timer 2 Clock Source Selection(PWM timer 2 for group A and PWM timer 6 for group B)Select clock input for timer.(Table is the same as CSR3)
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,8),Register::ReadWriteAccess,unsigned> csr2{}; 
        ///Timer 3 Clock Source Selection (PWM timer 3 for group A and PWM timer 7 for group B)Select clock input for timer.CSR3 [14:12]    Input clock divided by    100    1    011    16    010    8    001    4    000    2    
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,12),Register::ReadWriteAccess,unsigned> csr3{}; 
    }
    namespace PwmbPcr{    ///<PWM Control Register
        using Addr = Register::Address<0x40140008,0xf2f2f2c2,0x00000000,unsigned>;
        ///PWM-Timer 0 Enable/Disable Start Run (PWM timer 0 for group A and PWM timer 4 for group B)1 = Enable corresponding PWM-Timer Start Run0 = Stop corresponding PWM-Timer Running
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0en{}; 
        ///PWM-Timer 0 Output Inverter ON/OFF(PWM timer 0 for group A and PWM timer 4 for group B)1 = Inverter ON0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch0inv{}; 
        ///PWM-Timer 0 Auto-reload/One-Shot Mode(PWM timer 0 for group A and PWM timer 4 for group B)1 = Auto-reload Mode0 = One-Shot ModeNote: If there is a rising transition at this bit, it will cause CNR0 and CMR0 be clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch0mod{}; 
        ///Dead-Zone 0 Generator Enable/Disable(PWM0 and PWM1 pair for PWM group A, PWM4 and PWM5 pair for PWM group B)1 = Enable0 = DisableNote: When Dead-Zone Generator is enabled, the pair of PWM0 and PWM1 becomes a complementary pair for PWM group A and the pair of PWM4 and PWM5 becomes a complementary pair for PWM group B.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> dzen01{}; 
        ///Dead-Zone 2 Generator Enable/Disable(PWM2 and PWM3 pair for PWM group A, PWM6 and PWM7 pair for PWM group B)1 = Enable0 = DisableNote: When Dead-Zone Generator is enabled, the pair of PWM2 and PWM3 becomes a complementary pair for PWM group A and the pair of PWM6 and PWM7 becomes a complementary pair for PWM group B.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> dzen23{}; 
        ///PWM-Timer 1 Enable/Disable Start Run (PWM timer 1 for group A and PWM timer 5 for group B)1 = Enable corresponding PWM-Timer Start Run0 = Stop corresponding PWM-Timer Running
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> ch1en{}; 
        ///PWM-Timer 1 Output Inverter ON/OFF(PWM timer 1 for group A and PWM timer 5 for group B)1 = Inverter ON0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> ch1inv{}; 
        ///PWM-Timer 1 Auto-reload/One-Shot Mode(PWM timer 1 for group A and PWM timer 5 for group B)1 = Auto-reload Mode0 = One-Shot ModeNote: If there is a rising transition at this bit, it will cause CNR1 and CMR1 be clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> ch1mod{}; 
        ///PWM-Timer 2 Enable/Disable Start Run (PWM timer 2 for group A and PWM timer 6 for group B)1 = Enable corresponding PWM-Timer Start Run0 = Stop corresponding PWM-Timer Running
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> ch2en{}; 
        ///PWM-Timer 2 Output Inverter ON/OFF(PWM timer 2 for group A and PWM timer 6 for group B)1 = Inverter ON0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> ch2inv{}; 
        ///PWM-Timer 2 Auto-reload/One-Shot Mode(PWM timer 2 for group A and PWM timer 6 for group B)1 = Auto-reload Mode0 = One-Shot ModeNote: If there is a rising transition at this bit, it will cause CNR2 and CMR2 be clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> ch2mod{}; 
        ///PWM-Timer 3 Enable/Disable Start Run (PWM timer 3 for group A and PWM timer 7 for group B)1 = Enable corresponding PWM-Timer Start Run0 = Stop corresponding PWM-Timer Running
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> ch3en{}; 
        ///PWM-Timer 3 Output Inverter ON/OFF(PWM timer 3 for group A and PWM timer 7 for group B)1 = Inverter ON0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,unsigned> ch3inv{}; 
        ///PWM-Timer 3 Auto-reload/One-Shot Mode(PWM timer 3 for group A and PWM timer 7 for group B)1 = Auto-reload Mode0 = One-Shot ModeNote: If there is a rising transition at this bit, it will cause CNR3 and CMR3 be clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,unsigned> ch3mod{}; 
    }
    namespace PwmbCnr0{    ///<PWM Counter Register 0
        using Addr = Register::Address<0x4014000c,0xffff0000,0x00000000,unsigned>;
        ///PWM Counter/Timer Loaded ValueCNR determines the PWM period.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cnr{}; 
    }
    namespace PwmbCmr0{    ///<PWM Comparator Register 0
        using Addr = Register::Address<0x40140010,0xffff0000,0x00000000,unsigned>;
        ///PWM Comparator RegisterCNR determines the PWM duty.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cmr{}; 
    }
    namespace PwmbPdr0{    ///<PWM Data Register 0
        using Addr = Register::Address<0x40140014,0xffff0000,0x00000000,unsigned>;
        ///PWM Data RegisterUser can monitor PDR to know the current value in 16-bit down counter.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pdr{}; 
    }
    namespace PwmbCnr1{    ///<PWM Counter Register 1
        using Addr = Register::Address<0x40140018,0xffff0000,0x00000000,unsigned>;
        ///PWM Counter/Timer Loaded ValueCNR determines the PWM period.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cnr{}; 
    }
    namespace PwmbCmr1{    ///<PWM Comparator Register 1
        using Addr = Register::Address<0x4014001c,0xffff0000,0x00000000,unsigned>;
        ///PWM Comparator RegisterCNR determines the PWM duty.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cmr{}; 
    }
    namespace PwmbPdr1{    ///<PWM Data Register 1
        using Addr = Register::Address<0x40140020,0xffff0000,0x00000000,unsigned>;
        ///PWM Data RegisterUser can monitor PDR to know the current value in 16-bit down counter.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pdr{}; 
    }
    namespace PwmbCnr2{    ///<PWM Counter Register 2
        using Addr = Register::Address<0x40140024,0xffff0000,0x00000000,unsigned>;
        ///PWM Counter/Timer Loaded ValueCNR determines the PWM period.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cnr{}; 
    }
    namespace PwmbCmr2{    ///<PWM Comparator Register 2
        using Addr = Register::Address<0x40140028,0xffff0000,0x00000000,unsigned>;
        ///PWM Comparator RegisterCNR determines the PWM duty.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cmr{}; 
    }
    namespace PwmbPdr2{    ///<PWM Data Register 2
        using Addr = Register::Address<0x4014002c,0xffff0000,0x00000000,unsigned>;
        ///PWM Data RegisterUser can monitor PDR to know the current value in 16-bit down counter.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pdr{}; 
    }
    namespace PwmbCnr3{    ///<PWM Counter Register 3
        using Addr = Register::Address<0x40140030,0xffff0000,0x00000000,unsigned>;
        ///PWM Counter/Timer Loaded ValueCNR determines the PWM period.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cnr{}; 
    }
    namespace PwmbCmr3{    ///<PWM Comparator Register 3
        using Addr = Register::Address<0x40140034,0xffff0000,0x00000000,unsigned>;
        ///PWM Comparator RegisterCNR determines the PWM duty.PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 45 or 67, depends on selected PWM channel.Duty ratio = (CMR+1)/(CNR+1).CMR >= CNR: PWM output is always high.CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit(Unit = one PWM clock cycle)Note: Any write to CNR will take effect in next PWM cycle.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cmr{}; 
    }
    namespace PwmbPdr3{    ///<PWM Data Register 3
        using Addr = Register::Address<0x40140038,0xffff0000,0x00000000,unsigned>;
        ///PWM Data RegisterUser can monitor PDR to know the current value in 16-bit down counter.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pdr{}; 
    }
    namespace PwmbPier{    ///<PWM Interrupt Enable Register
        using Addr = Register::Address<0x40140040,0xfffffff0,0x00000000,unsigned>;
        ///PWM channel 0 Interrupt Enable1 = Enable0 = Disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pwmie0{}; 
        ///PWM channel 1 Interrupt Enable1 = Enable0 = Disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pwmie1{}; 
        ///PWM channel 2 Interrupt Enable1 = Enable0 = Disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pwmie2{}; 
        ///PWM channel 3 Interrupt Enable1 = Enable0 = Disable 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pwmie3{}; 
    }
    namespace PwmbPiir{    ///<PWM Interrupt Indication Register
        using Addr = Register::Address<0x40140044,0xffffffff,0x00000000,unsigned>;
        ///PWM channel 0 Interrupt StatusFlag is set by hardware when PWM0 down counter reaches zero, software can clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> pwmif0{}; 
        ///PWM channel 1 Interrupt StatusFlag is set by hardware when PWM1 down counter reaches zero, software can clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> pwmif1{}; 
        ///PWM channel 2 Interrupt StatusFlag is set by hardware when PWM2 down counter reaches zero, software can clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> pwmif2{}; 
        ///PWM channel 3 Interrupt StatusFlag is set by hardware when PWM3 down counter reaches zero, software can clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> pwmif3{}; 
    }
    namespace PwmbCcr0{    ///<Capture Control Register
        using Addr = Register::Address<0x40140050,0xfff0fff0,0x00000000,unsigned>;
        ///PWM Group Channel 0 Inverter ON/OFF1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> inv0{}; 
        ///PWM Group Channel 0 Rising Latch Interrupt Enable ON/OFF1 = Enable rising latch interrupt0 = Disable rising latch interruptWhen Enable, if Capture detects PWM group channel 0 has rising transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> crlIe0{}; 
        ///PWM Group Channel 0 Falling Latch Interrupt Enable ON/OFF1 = Enable falling latch interrupt0 = Disable falling latch interruptWhen Enable, if Capture detects PWM group channel 0 has falling transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> cflIe0{}; 
        ///Capture Channel 0 transition Enable/Disable1 = Enable capture function on PWM group channel 0.0 = Disable capture function on PWM group channel 0When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising latch) and CFLR (Falling latch).When Disable, Capture does not update CRLR and CFLR, and disable PWM group channel 0 Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> capch0en{}; 
        ///Capture0 Interrupt Indication FlagIf PWM group channel 0 rising latch interrupt is enabled (CRL_IE0=1), a rising transition occurs at PWM group channel 0 will result in CAPIF0 to high; Similarly, a falling transition will cause CAPIF0 to be set high if PWM group channel 0 falling latch interrupt is enabled (CFL_IE0=1). This flag is clear by software with a write 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> capif0{}; 
        ///CRLR0 Latched Indicator BitWhen PWM group input channel 0 has a rising transition, CRLR0 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> crlri0{}; 
        ///CFLR0 Latched Indicator BitWhen PWM group input channel 0 has a falling transition, CFLR0 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> cflri0{}; 
        ///PWM Group Channel 1 Inverter ON/OFF1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> inv1{}; 
        ///PWM Group Channel 1 Rising Latch Interrupt Enable ON/OFF1 = Enable rising latch interrupt0 = Disable rising latch interruptWhen Enable, if Capture detects PWM group channel 1 has rising transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> crlIe1{}; 
        ///PWM Group Channel 1 Falling Latch Interrupt Enable ON/OFF1 = Enable falling latch interrupt0 = Disable falling latch interruptWhen Enable, if Capture detects PWM group channel 1 has falling transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> cflIe1{}; 
        ///Capture Channel 1 transition Enable/Disable1 = Enable capture function on PWM group channel 1.0 = Disable capture function on PWM group channel 1When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising latch) and CFLR (Falling latch).When Disable, Capture does not update CRLR and CFLR, and disable PWM group channel 1 Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> capch1en{}; 
        ///Capture1 Interrupt Indication FlagIf PWM group channel 1 rising latch interrupt is enabled (CRL_IE1=1), a rising transition occurs at PWM group channel 1 will result in CAPIF1 to high; Similarly, a falling transition will cause CAPIF1 to be set high if PWM group channel 1 falling latch interrupt is enabled (CFL_IE1=1). This flag is clear by software with a write 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(20,20),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> capif1{}; 
        ///CRLR1 Latched Indicator BitWhen PWM group input channel 1 has a rising transition, CRLR1 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,22),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> crlri1{}; 
        ///CFLR1 Latched Indicator BitWhen PWM group input channel 1 has a falling transition, CFLR1 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,23),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> cflri1{}; 
    }
    namespace PwmbCcr2{    ///<Capture Control Register
        using Addr = Register::Address<0x40140054,0xfff0fff0,0x00000000,unsigned>;
        ///PWM Group Channel 2 Inverter ON/OFF1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> inv2{}; 
        ///PWM Group Channel 2 Rising Latch Interrupt Enable ON/OFF1 = Enable rising latch interrupt0 = Disable rising latch interruptWhen Enable, if Capture detects PWM group channel 2 has rising transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> crlIe2{}; 
        ///PWM Group Channel 2 Falling Latch Interrupt Enable ON/OFF1 = Enable falling latch interrupt0 = Disable falling latch interruptWhen Enable, if Capture detects PWM group channel 2 has falling transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> cflIe2{}; 
        ///Capture Channel 2 transition Enable/Disable1 = Enable capture function on PWM group channel 2.0 = Disable capture function on PWM group channel 2When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising latch) and CFLR (Falling latch).When Disable, Capture does not update CRLR and CFLR, and disable PWM group channel 2 Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> capch2en{}; 
        ///Capture2 Interrupt Indication FlagIf PWM group channel 2 rising latch interrupt is enabled (CRL_IE2=1), a rising transition occurs at PWM group channel 2 will result in CAPIF2 to high; Similarly, a falling transition will cause CAPIF2 to be set high if PWM group channel 2 falling latch interrupt is enabled (CFL_IE2=1). This flag is clear by software with a write 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> capif2{}; 
        ///CRLR2 Latched Indicator BitWhen PWM group input channel 2 has a rising transition, CRLR2 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> crlri2{}; 
        ///CFLR2 Latched Indicator BitWhen PWM group input channel 2 has a falling transition, CFLR2 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> cflri2{}; 
        ///PWM Group Channel 3 Inverter ON/OFF1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer0 = Inverter OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> inv3{}; 
        ///PWM Group Channel 3 Rising Latch Interrupt Enable ON/OFF1 = Enable rising latch interrupt0 = Disable rising latch interruptWhen Enable, if Capture detects PWM group channel 3 has rising transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> crlIe3{}; 
        ///PWM Group Channel 3 Falling Latch Interrupt Enable ON/OFF1 = Enable falling latch interrupt0 = Disable falling latch interruptWhen Enable, if Capture detects PWM group channel 3 has falling transition, Capture issues an Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> cflIe3{}; 
        ///Capture Channel 3 transition Enable/Disable1 = Enable capture function on PWM group channel 3.0 = Disable capture function on PWM group channel 3When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising latch) and CFLR (Falling latch).When Disable, Capture does not update CRLR and CFLR, and disable PWM group channel 3 Interrupt.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> capch3en{}; 
        ///Capture3 Interrupt Indication FlagIf PWM group channel 3 rising latch interrupt is enabled (CRL_IE3=1), a rising transition occurs at PWM group channel 3 will result in CAPIF3 to high; Similarly, a falling transition will cause CAPIF3 to be set high if PWM group channel 3 falling latch interrupt is enabled (CFL_IE3=1). This flag is clear by software with a write 1 to itself.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(20,20),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> capif3{}; 
        ///CRLR3 Latched Indicator BitWhen PWM group input channel 3 has a rising transition, CRLR3 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,22),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> crlri3{}; 
        ///CFLR3 Latched Indicator BitWhen PWM group input channel 3 has a falling transition, CFLR3 was latched with the value of PWM down-counter and this bit is set by hardware.Clear this bit by writing a one to it.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,23),Register::Access<Register::AccessType::readWrite,Register::ReadActionType::normal,Register::ModifiedWriteValueType::oneToClear>,unsigned> cflri3{}; 
    }
    namespace PwmbCrlr0{    ///<Capture Rising Latch Register (Channel 0)
        using Addr = Register::Address<0x40140058,0xffff0000,0x00000000,unsigned>;
        ///Capture Rising Latch RegisterLatch the PWM counter when Channel 0/1/2/3 has rising transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> crlr{}; 
    }
    namespace PwmbCflr0{    ///<Capture Falling Latch Register (Channel 0)
        using Addr = Register::Address<0x4014005c,0xffff0000,0x00000000,unsigned>;
        ///Capture Falling Latch RegisterLatch the PWM counter when Channel 01/2/3 has Falling transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> cflr{}; 
    }
    namespace PwmbCrlr1{    ///<Capture Rising Latch Register (Channel 1)
        using Addr = Register::Address<0x40140060,0xffff0000,0x00000000,unsigned>;
        ///Capture Rising Latch RegisterLatch the PWM counter when Channel 0/1/2/3 has rising transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> crlr{}; 
    }
    namespace PwmbCflr1{    ///<Capture Falling Latch Register (Channel 1)
        using Addr = Register::Address<0x40140064,0xffff0000,0x00000000,unsigned>;
        ///Capture Falling Latch RegisterLatch the PWM counter when Channel 01/2/3 has Falling transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> cflr{}; 
    }
    namespace PwmbCrlr2{    ///<Capture Rising Latch Register (channel 2)
        using Addr = Register::Address<0x40140068,0xffff0000,0x00000000,unsigned>;
        ///Capture Rising Latch RegisterLatch the PWM counter when Channel 0/1/2/3 has rising transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> crlr{}; 
    }
    namespace PwmbCflr2{    ///<Capture Falling Latch Register (channel 2)
        using Addr = Register::Address<0x4014006c,0xffff0000,0x00000000,unsigned>;
        ///Capture Falling Latch RegisterLatch the PWM counter when Channel 0/1/2/3 has Falling transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> cflr{}; 
    }
    namespace PwmbCrlr3{    ///<Capture Rising Latch Register (channel 3)
        using Addr = Register::Address<0x40140070,0xffff0000,0x00000000,unsigned>;
        ///Capture Rising Latch RegisterLatch the PWM counter when Channel 0/1/2/3 has rising transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> crlr{}; 
    }
    namespace PwmbCflr3{    ///<Capture Falling Latch Register (channel 3)
        using Addr = Register::Address<0x40140074,0xffff0000,0x00000000,unsigned>;
        ///Capture Falling Latch RegisterLatch the PWM counter when Channel 0/1/2/3 has Falling transition.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> cflr{}; 
    }
    namespace PwmbCapenr{    ///<Capture Input Enable Register
        using Addr = Register::Address<0x40140078,0xfffffff0,0x00000000,unsigned>;
        ///Capture Input Enable RegisterThere are four capture inputs from pad. Bit0~Bit3 are used to control each inputs ON or OFF. 0 = OFF (PWMx multi-function pin input does not affect input capture function.)1 = (PWMx multi-function pin input will affect its input capture function.)CAPENRBit 3210 for PWM group ABit xxx1 -> Capture channel 0 is from P2 [0] Bit xx1x -> Capture channel 1 is from P2 [1] Bit x1xx -> Capture channel 2 is from P2 [2]Bit 1xxx -> Capture channel 3 is from P2 [3]Bit 3210 for PWM group BBit xxx1 -> Capture channel 0 is from P2 [4] Bit xx1x -> Capture channel 1 is from P2 [5] Bit x1xx -> Capture channel 2 is from P2 [6]Bit 1xxx -> Capture channel 3 is from P2 [7]
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> capenr{}; 
    }
    namespace PwmbPoe{    ///<PWM Output Enable
        using Addr = Register::Address<0x4014007c,0xfffffff0,0x00000000,unsigned>;
        ///PWM Channel 0 Output Enable Register1 = Enable PWM channel 0 output to pin.0 = Disable PWM channel 0 output to pin.Note: The corresponding GPIO pin also must be switched to PWM function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pwm0{}; 
        ///PWM Channel 1 Output Enable Register1 = Enable PWM channel 1 output to pin.0 = Disable PWM channel 1 output to pin.Note: The corresponding GPIO pin also must be switched to PWM function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pwm1{}; 
        ///PWM Channel 2 Output Enable Register1 = Enable PWM channel 2 output to pin.0 = Disable PWM channel 2 output to pin.Note: The corresponding GPIO pin also must be switched to PWM function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pwm2{}; 
        ///PWM Channel 3 Output Enable Register1 = Enable PWM channel 3 output to pin.0 = Disable PWM channel 3 output to pin.Note: The corresponding GPIO pin also must be switched to PWM function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pwm3{}; 
    }
}
