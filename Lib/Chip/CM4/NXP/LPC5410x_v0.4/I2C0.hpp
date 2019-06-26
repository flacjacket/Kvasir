#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//I2C-bus interface 0
    namespace I2c0Cfg{    ///<Configuration for shared functions.
        using Addr = Register::Address<0x40094000,0x00000000,0x00000000,unsigned>;
        ///Master Enable. When disabled, configurations settings for                                the Master function are not changed, but the Master function is                                internally reset.
        enum class MstenVal {
            disabled=0x00000000,     ///<Disabled. The I2C Master function is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The I2C Master function is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,MstenVal> msten{}; 
        namespace MstenValC{
            constexpr Register::FieldValue<decltype(msten)::Type,MstenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(msten)::Type,MstenVal::enabled> enabled{};
        }
        ///Slave Enable. When disabled, configurations settings for                                the Slave function are not changed, but the Slave function is                                internally reset.
        enum class SlvenVal {
            disabled=0x00000000,     ///<Disabled. The I2C slave function is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The I2C slave function is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,SlvenVal> slven{}; 
        namespace SlvenValC{
            constexpr Register::FieldValue<decltype(slven)::Type,SlvenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(slven)::Type,SlvenVal::enabled> enabled{};
        }
        ///Monitor Enable. When disabled, configurations settings for                                the Monitor function are not changed, but the Monitor function is                                internally reset.
        enum class MonenVal {
            disabled=0x00000000,     ///<Disabled. The I2C monitor function is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The I2C monitor function is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,MonenVal> monen{}; 
        namespace MonenValC{
            constexpr Register::FieldValue<decltype(monen)::Type,MonenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(monen)::Type,MonenVal::enabled> enabled{};
        }
        ///I2C bus Time-out Enable. When disabled, the time-out                                function is internally reset.
        enum class TimeoutenVal {
            disabled=0x00000000,     ///<Disabled. Time-out function is                                        disabled.
            enabled=0x00000001,     ///<Enabled. Time-out function is enabled. Both types                                        of time-out flags will be generated and will cause                                        interrupts if they are enabled. Typically, only one time-out                                        will be used in a system.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,TimeoutenVal> timeouten{}; 
        namespace TimeoutenValC{
            constexpr Register::FieldValue<decltype(timeouten)::Type,TimeoutenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(timeouten)::Type,TimeoutenVal::enabled> enabled{};
        }
        ///Monitor function Clock Stretching.
        enum class MonclkstrVal {
            disabled=0x00000000,     ///<Disabled. The monitor function will not perform                                        clock stretching. Software or DMA may not always be able to                                        read data provided by the monitor function before it is                                        overwritten. This mode may be used when non-invasive                                        monitoring is critical.
            enabled=0x00000001,     ///<Enabled. The monitor function will perform clock                                        stretching in order to ensure that software or DMA can read                                        all incoming data supplied by the monitor                                        function.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,MonclkstrVal> monclkstr{}; 
        namespace MonclkstrValC{
            constexpr Register::FieldValue<decltype(monclkstr)::Type,MonclkstrVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(monclkstr)::Type,MonclkstrVal::enabled> enabled{};
        }
        ///High-speed mode Capable enable. Since High Speed mode                                alters the way I2C pins drive and filter, as well as the timing for                                certain I2C signalling, enabling High-speed mode applies to all                                functions: master, slave, and monitor.
        enum class HscapableVal {
            fastModePlus=0x00000000,     ///<Fast-mode plus. The I2C block will support                                        Standard-mode, Fast-mode, and Fast-mode Plus, to the extent                                        that the pin electronics support these modes. Any changes                                        that need to be made to the pin controls, such as changing                                        the drive strength or filtering, must be made by software                                        via the IOCON register associated with each I2C                                        pin,
            highSpeed=0x00000001,     ///<High-speed. In addition to Standard-mode,                                        Fast-mode, and Fast-mode Plus, the I 2C block will support                                        High-speed mode to the extent that the pin electronics                                        support these modes. See Section 23.7.1.2 for more                                        information.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,HscapableVal> hscapable{}; 
        namespace HscapableValC{
            constexpr Register::FieldValue<decltype(hscapable)::Type,HscapableVal::fastModePlus> fastModePlus{};
            constexpr Register::FieldValue<decltype(hscapable)::Type,HscapableVal::highSpeed> highSpeed{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,6),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Stat{    ///<Status register for Master, Slave, and Monitor                        functions.
        using Addr = Register::Address<0x40094004,0x00000000,0x00000000,unsigned>;
        ///Master Pending. Indicates that the Master is waiting to                                continue communication on the I2C-bus (pending) or is idle. When the                                master is pending, the MSTSTATE bits indicate what type of software                                service if any the master expects. This flag will cause an interrupt                                when set if, enabled via the INTENSET register. The MSTPENDING flag                                is not set when the DMA is handling an event (if the MSTDMA bit in                                the MSTCTL register is set). If the master is in the idle state, and                                no communication is needed, mask this interrupt.
        enum class MstpendingVal {
            inProgress=0x00000000,     ///<In progress. Communication is in progress and the                                        Master function is busy and cannot currently accept a                                        command.
            pending=0x00000001,     ///<Pending. The Master function needs software service                                        or is in the idle state. If the master is not in the idle                                        state, it is waiting to receive or transmit data or the NACK                                        bit.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,MstpendingVal> mstpending{}; 
        namespace MstpendingValC{
            constexpr Register::FieldValue<decltype(mstpending)::Type,MstpendingVal::inProgress> inProgress{};
            constexpr Register::FieldValue<decltype(mstpending)::Type,MstpendingVal::pending> pending{};
        }
        ///Master State code. The master state code reflects the                                master state when the MSTPENDING bit is set, that is the master is                                pending or in the idle state. Each value of this field indicates a                                specific required service for the Master function. All other values                                are reserved. See Table 346 for details of state values and                                appropriate responses.
        enum class MststateVal {
            idle=0x00000000,     ///<Idle. The Master function is available to be used                                        for a new transaction.
            receiveReady=0x00000001,     ///<Receive ready. Received data available (Master                                        Receiver mode). Address plus Read was previously sent and                                        Acknowledged by slave.
            transmitReady=0x00000002,     ///<Transmit ready. Data can be transmitted (Master                                        Transmitter mode). Address plus Write was previously sent                                        and Acknowledged by slave.
            nackAddress=0x00000003,     ///<NACK Address. Slave NACKed address.
            nackData=0x00000004,     ///<NACK Data. Slave NACKed transmitted                                        data.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,1),Register::ReadWriteAccess,MststateVal> mststate{}; 
        namespace MststateValC{
            constexpr Register::FieldValue<decltype(mststate)::Type,MststateVal::idle> idle{};
            constexpr Register::FieldValue<decltype(mststate)::Type,MststateVal::receiveReady> receiveReady{};
            constexpr Register::FieldValue<decltype(mststate)::Type,MststateVal::transmitReady> transmitReady{};
            constexpr Register::FieldValue<decltype(mststate)::Type,MststateVal::nackAddress> nackAddress{};
            constexpr Register::FieldValue<decltype(mststate)::Type,MststateVal::nackData> nackData{};
        }
        ///Master Arbitration Loss flag. This flag can be cleared by                                software writing a 1 to this bit. It is also cleared automatically a                                1 is written to MSTCONTINUE.
        enum class MstarblossVal {
            noArbitrationLoss=0x00000000,     ///<No Arbitration Loss has occurred.
            arbitrationLoss=0x00000001,     ///<Arbitration loss. The Master function has                                        experienced an Arbitration Loss. At this point, the Master                                        function has already stopped driving the bus and gone to an                                        idle state. Software can respond by doing nothing, or by                                        sending a Start in order to attempt to gain control of the                                        bus when it next becomes idle.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,MstarblossVal> mstarbloss{}; 
        namespace MstarblossValC{
            constexpr Register::FieldValue<decltype(mstarbloss)::Type,MstarblossVal::noArbitrationLoss> noArbitrationLoss{};
            constexpr Register::FieldValue<decltype(mstarbloss)::Type,MstarblossVal::arbitrationLoss> arbitrationLoss{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Start/Stop Error flag. This flag can be cleared by                                software writing a 1 to this bit. It is also cleared automatically a                                1 is written to MSTCONTINUE.
        enum class MstststperrVal {
            noStartstopError=0x00000000,     ///<No Start/Stop Error has occurred.
            theMasterFunction=0x00000001,     ///<The Master function has experienced a Start/Stop                                        Error. A Start or Stop was detected at a time when it is not                                        allowed by the I2C specification. The Master interface has                                        stopped driving the bus and gone to an idle state, no action                                        is required. A request for a Start could be made, or                                        software could attempt to insure that the bus has not                                        stalled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,MstststperrVal> mstststperr{}; 
        namespace MstststperrValC{
            constexpr Register::FieldValue<decltype(mstststperr)::Type,MstststperrVal::noStartstopError> noStartstopError{};
            constexpr Register::FieldValue<decltype(mstststperr)::Type,MstststperrVal::theMasterFunction> theMasterFunction{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Pending. Indicates that the Slave function is waiting                                to continue communication on the I2C-bus and needs software service.                                This flag will cause an interrupt when set if enabled via INTENSET.                                The SLVPENDING flag is not set when the DMA is handling an event (if                                the SLVDMA bit in the SLVCTL register is set). The SLVPENDING flag                                is read-only and is automatically cleared when a 1 is written to the                                SLVCONTINUE bit in the MSTCTL register. The point in time when                                SlvPending is set depends on whether the I2C block is in HSCAPABLE                                mode. See Section 23.7.1.2.2. When the I2C block is configured to be                                HSCAPABLE, HS master codes are detected automatically. Due to the                                requirements of the HS I2C specification, slave addresses must also                                be detected automatically, since the address must be acknowledged                                before the clock can be stretched.
        enum class SlvpendingVal {
            inProgress=0x00000000,     ///<In progress. The Slave function does not currently                                        need service.
            pending=0x00000001,     ///<Pending. The Slave function needs service.                                        Information on what is needed can be found in the adjacent                                        SLVSTATE field.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,SlvpendingVal> slvpending{}; 
        namespace SlvpendingValC{
            constexpr Register::FieldValue<decltype(slvpending)::Type,SlvpendingVal::inProgress> inProgress{};
            constexpr Register::FieldValue<decltype(slvpending)::Type,SlvpendingVal::pending> pending{};
        }
        ///Slave State code. Each value of this field indicates a                                specific required service for the Slave function. All other values                                are reserved. See Table 347 for state values and                                actions.
        enum class SlvstateVal {
            slaveAddress=0x00000000,     ///<Slave address. Address plus R/W received. At least                                        one of the four slave addresses has been matched by                                        hardware.
            slaveReceive=0x00000001,     ///<Slave receive. Received data is available (Slave                                        Receiver mode).
            slaveTransmit=0x00000002,     ///<Slave transmit. Data can be transmitted (Slave                                        Transmitter mode).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,SlvstateVal> slvstate{}; 
        namespace SlvstateValC{
            constexpr Register::FieldValue<decltype(slvstate)::Type,SlvstateVal::slaveAddress> slaveAddress{};
            constexpr Register::FieldValue<decltype(slvstate)::Type,SlvstateVal::slaveReceive> slaveReceive{};
            constexpr Register::FieldValue<decltype(slvstate)::Type,SlvstateVal::slaveTransmit> slaveTransmit{};
        }
        ///Slave Not Stretching. Indicates when the slave function is                                stretching the I2C clock. This is needed in order to gracefully                                invoke Deep Sleep or Power-down modes during slave operation. This                                read-only flag reflects the slave function status in real                                time.
        enum class SlvnotstrVal {
            stretching=0x00000000,     ///<Stretching. The slave function is currently                                        stretching the I2C bus clock. Deep-Sleep or Power-down mode                                        cannot be entered at this time.
            notStretching=0x00000001,     ///<Not stretching. The slave function is not currently                                        stretching the I 2C bus clock. Deep-sleep or Power-down mode                                        could be entered at this time.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,SlvnotstrVal> slvnotstr{}; 
        namespace SlvnotstrValC{
            constexpr Register::FieldValue<decltype(slvnotstr)::Type,SlvnotstrVal::stretching> stretching{};
            constexpr Register::FieldValue<decltype(slvnotstr)::Type,SlvnotstrVal::notStretching> notStretching{};
        }
        ///Slave address match Index. This field is valid when the I2C                                slave function has been selected by receiving an address that                                matches one of the slave addresses defined by any enabled slave                                address registers, and provides an identification of the address                                that was matched. It is possible that more than one address could be                                matched, but only one match can be reported here.
        enum class SlvidxVal {
            address0=0x00000000,     ///<Address 0. Slave address 0 was                                        matched.
            address1=0x00000001,     ///<Address 1. Slave address 1 was                                        matched.
            address2=0x00000002,     ///<Address 2. Slave address 2 was                                        matched.
            address3=0x00000003,     ///<Address 3. Slave address 3 was                                        matched.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,12),Register::ReadWriteAccess,SlvidxVal> slvidx{}; 
        namespace SlvidxValC{
            constexpr Register::FieldValue<decltype(slvidx)::Type,SlvidxVal::address0> address0{};
            constexpr Register::FieldValue<decltype(slvidx)::Type,SlvidxVal::address1> address1{};
            constexpr Register::FieldValue<decltype(slvidx)::Type,SlvidxVal::address2> address2{};
            constexpr Register::FieldValue<decltype(slvidx)::Type,SlvidxVal::address3> address3{};
        }
        ///Slave selected flag. SLVSEL is set after an address match                                when software tells the Slave function to acknowledge the address.                                It is cleared when another address cycle presents an address that                                does not match an enabled address on the Slave function, when slave                                software decides to NACK a matched address, or when there is a Stop                                detected on the bus. SLVSEL is not cleared if software NACKs                                data.
        enum class SlvselVal {
            notSelected=0x00000000,     ///<Not selected. The Slave function is not currently                                        selected.
            selected=0x00000001,     ///<Selected. The Slave function is currently                                        selected.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,SlvselVal> slvsel{}; 
        namespace SlvselValC{
            constexpr Register::FieldValue<decltype(slvsel)::Type,SlvselVal::notSelected> notSelected{};
            constexpr Register::FieldValue<decltype(slvsel)::Type,SlvselVal::selected> selected{};
        }
        ///Slave Deselected flag. This flag will cause an interrupt                                when set if enabled via INTENSET. This flag can be cleared by                                writing a 1 to this bit.
        enum class SlvdeselVal {
            notDeselected=0x00000000,     ///<Not deselected. The Slave function has not become                                        deselected. This does not mean that it is currently                                        selected. That information can be found in the SLVSEL                                        flag.
            deselected=0x00000001,     ///<Deselected. The Slave function has become                                        deselected. This is specifically caused by the SLVSEL flag                                        changing from 1 to 0. See the description of SLVSEL for                                        details on when that event occurs.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,SlvdeselVal> slvdesel{}; 
        namespace SlvdeselValC{
            constexpr Register::FieldValue<decltype(slvdesel)::Type,SlvdeselVal::notDeselected> notDeselected{};
            constexpr Register::FieldValue<decltype(slvdesel)::Type,SlvdeselVal::deselected> deselected{};
        }
        ///Monitor Ready. This flag is cleared when the MONRXDAT                                register is read.
        enum class MonrdyVal {
            noData=0x00000000,     ///<No data. The Monitor function does not currently                                        have data available.
            dataWaiting=0x00000001,     ///<Data waiting. The Monitor function has data waiting                                        to be read.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,MonrdyVal> monrdy{}; 
        namespace MonrdyValC{
            constexpr Register::FieldValue<decltype(monrdy)::Type,MonrdyVal::noData> noData{};
            constexpr Register::FieldValue<decltype(monrdy)::Type,MonrdyVal::dataWaiting> dataWaiting{};
        }
        ///Monitor Overflow flag.
        enum class MonovVal {
            noOverrun=0x00000000,     ///<No overrun. Monitor data has not                                        overrun.
            overrun=0x00000001,     ///<Overrun. A Monitor data overrun has occurred. This                                        can only happen when Monitor clock stretching not enabled                                        via the MONCLKSTR bit in the CFG register. Writing 1 to this                                        bit clears the flag.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,MonovVal> monov{}; 
        namespace MonovValC{
            constexpr Register::FieldValue<decltype(monov)::Type,MonovVal::noOverrun> noOverrun{};
            constexpr Register::FieldValue<decltype(monov)::Type,MonovVal::overrun> overrun{};
        }
        ///Monitor Active flag. Indicates when the Monitor function                                considers the I 2C bus to be active. Active is defined here as when                                some Master is on the bus: a bus Start has occurred more recently                                than a bus Stop.
        enum class MonactiveVal {
            inactive=0x00000000,     ///<Inactive. The Monitor function considers the I2C                                        bus to be inactive.
            active=0x00000001,     ///<Active. The Monitor function considers the I2C bus                                        to be active.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,MonactiveVal> monactive{}; 
        namespace MonactiveValC{
            constexpr Register::FieldValue<decltype(monactive)::Type,MonactiveVal::inactive> inactive{};
            constexpr Register::FieldValue<decltype(monactive)::Type,MonactiveVal::active> active{};
        }
        ///Monitor Idle flag. This flag is set when the Monitor                                function sees the I2C bus change from active to inactive. This can                                be used by software to decide when to process data accumulated by                                the Monitor function. This flag will cause an interrupt when set if                                enabled via the INTENSET register. The flag can be cleared by                                writing a 1 to this bit.
        enum class MonidleVal {
            notIdle=0x00000000,     ///<Not idle. The I2C bus is not idle, or this flag has                                        been cleared by software.
            idle=0x00000001,     ///<Idle. The I2C bus has gone idle at least once since                                        the last time this flag was cleared by                                        software.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,MonidleVal> monidle{}; 
        namespace MonidleValC{
            constexpr Register::FieldValue<decltype(monidle)::Type,MonidleVal::notIdle> notIdle{};
            constexpr Register::FieldValue<decltype(monidle)::Type,MonidleVal::idle> idle{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Event Time-out Interrupt flag. Indicates when the time                                between events has been longer than the time specified by the                                TIMEOUT register. Events include Start, Stop, and clock edges. The                                flag is cleared by writing a 1 to this bit. No time-out is created                                when the I2C-bus is idle.
        enum class EventtimeoutVal {
            noTimeOut=0x00000000,     ///<No time-out. I2C bus events have not caused a                                        time-out.
            eventTimeOut=0x00000001,     ///<Event time-out. The time between I2C bus events has                                        been longer than the time specified by the I2C TIMEOUT                                        register.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,EventtimeoutVal> eventtimeout{}; 
        namespace EventtimeoutValC{
            constexpr Register::FieldValue<decltype(eventtimeout)::Type,EventtimeoutVal::noTimeOut> noTimeOut{};
            constexpr Register::FieldValue<decltype(eventtimeout)::Type,EventtimeoutVal::eventTimeOut> eventTimeOut{};
        }
        ///SCL Time-out Interrupt flag. Indicates when SCL has                                remained low longer than the time specific by the TIMEOUT register.                                The flag is cleared by writing a 1 to this bit.
        enum class ScltimeoutVal {
            noTimeOut=0x00000000,     ///<No time-out. SCL low time has not caused a                                        time-out.
            timeOut=0x00000001,     ///<Time-out. SCL low time has caused a                                        time-out.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,ScltimeoutVal> scltimeout{}; 
        namespace ScltimeoutValC{
            constexpr Register::FieldValue<decltype(scltimeout)::Type,ScltimeoutVal::noTimeOut> noTimeOut{};
            constexpr Register::FieldValue<decltype(scltimeout)::Type,ScltimeoutVal::timeOut> timeOut{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,26),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Intenset{    ///<Interrupt Enable Set and read register.
        using Addr = Register::Address<0x40094008,0x00000000,0x00000000,unsigned>;
        ///Master Pending interrupt Enable.
        enum class MstpendingenVal {
            disabled=0x00000000,     ///<Disabled. The MstPending interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The MstPending interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,MstpendingenVal> mstpendingen{}; 
        namespace MstpendingenValC{
            constexpr Register::FieldValue<decltype(mstpendingen)::Type,MstpendingenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(mstpendingen)::Type,MstpendingenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Arbitration Loss interrupt Enable.
        enum class MstarblossenVal {
            disabled=0x00000000,     ///<Disabled. The MstArbLoss interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The MstArbLoss interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,MstarblossenVal> mstarblossen{}; 
        namespace MstarblossenValC{
            constexpr Register::FieldValue<decltype(mstarblossen)::Type,MstarblossenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(mstarblossen)::Type,MstarblossenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Start/Stop Error interrupt Enable.
        enum class MstststperrenVal {
            disabled=0x00000000,     ///<Disabled. The MstStStpErr interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The MstStStpErr interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,MstststperrenVal> mstststperren{}; 
        namespace MstststperrenValC{
            constexpr Register::FieldValue<decltype(mstststperren)::Type,MstststperrenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(mstststperren)::Type,MstststperrenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Pending interrupt Enable.
        enum class SlvpendingenVal {
            disabled=0x00000000,     ///<Disabled. The SlvPending interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The SlvPending interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,SlvpendingenVal> slvpendingen{}; 
        namespace SlvpendingenValC{
            constexpr Register::FieldValue<decltype(slvpendingen)::Type,SlvpendingenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(slvpendingen)::Type,SlvpendingenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Not Stretching interrupt Enable.
        enum class SlvnotstrenVal {
            disabled=0x00000000,     ///<Disabled. The SlvNotStr interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The SlvNotStr interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,SlvnotstrenVal> slvnotstren{}; 
        namespace SlvnotstrenValC{
            constexpr Register::FieldValue<decltype(slvnotstren)::Type,SlvnotstrenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(slvnotstren)::Type,SlvnotstrenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,12),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Deselect interrupt Enable.
        enum class SlvdeselenVal {
            disabled=0x00000000,     ///<Disabled. The SlvDeSel interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The SlvDeSel interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,SlvdeselenVal> slvdeselen{}; 
        namespace SlvdeselenValC{
            constexpr Register::FieldValue<decltype(slvdeselen)::Type,SlvdeselenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(slvdeselen)::Type,SlvdeselenVal::enabled> enabled{};
        }
        ///Monitor data Ready interrupt Enable.
        enum class MonrdyenVal {
            disabled=0x00000000,     ///<Disabled. The MonRdy interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The MonRdy interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,MonrdyenVal> monrdyen{}; 
        namespace MonrdyenValC{
            constexpr Register::FieldValue<decltype(monrdyen)::Type,MonrdyenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(monrdyen)::Type,MonrdyenVal::enabled> enabled{};
        }
        ///Monitor Overrun interrupt Enable.
        enum class MonovenVal {
            disabled=0x00000000,     ///<Disabled. The MonOv interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The MonOv interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,MonovenVal> monoven{}; 
        namespace MonovenValC{
            constexpr Register::FieldValue<decltype(monoven)::Type,MonovenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(monoven)::Type,MonovenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Monitor Idle interrupt Enable.
        enum class MonidleenVal {
            disabled=0x00000000,     ///<Disabled. The MonIdle interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The MonIdle interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,MonidleenVal> monidleen{}; 
        namespace MonidleenValC{
            constexpr Register::FieldValue<decltype(monidleen)::Type,MonidleenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(monidleen)::Type,MonidleenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Event time-out interrupt Enable.
        enum class EventtimeoutenVal {
            disabled=0x00000000,     ///<Disabled. The Event time-out interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The Event time-out interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,EventtimeoutenVal> eventtimeouten{}; 
        namespace EventtimeoutenValC{
            constexpr Register::FieldValue<decltype(eventtimeouten)::Type,EventtimeoutenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(eventtimeouten)::Type,EventtimeoutenVal::enabled> enabled{};
        }
        ///SCL time-out interrupt Enable.
        enum class ScltimeoutenVal {
            disabled=0x00000000,     ///<Disabled. The SCL time-out interrupt is                                        disabled.
            enabled=0x00000001,     ///<Enabled. The SCL time-out interrupt is                                        enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,ScltimeoutenVal> scltimeouten{}; 
        namespace ScltimeoutenValC{
            constexpr Register::FieldValue<decltype(scltimeouten)::Type,ScltimeoutenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(scltimeouten)::Type,ScltimeoutenVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,26),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Intenclr{    ///<Interrupt Enable Clear register.
        using Addr = Register::Address<0x4009400c,0x00000000,0x00000000,unsigned>;
        ///Master Pending interrupt clear. Writing 1 to this bit                                clears the corresponding bit in the INTENSET register if                                implemented.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> mstpendingclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Arbitration Loss interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> mstarblossclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Start/Stop Error interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> mstststperrclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Pending interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> slvpendingclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Not Stretching interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> slvnotstrclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,12),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Deselect interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> slvdeselclr{}; 
        ///Monitor data Ready interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> monrdyclr{}; 
        ///Monitor Overrun interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> monovclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Monitor Idle interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> monidleclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Event time-out interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> eventtimeoutclr{}; 
        ///SCL time-out interrupt clear.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,unsigned> scltimeoutclr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,26),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Timeout{    ///<Time-out value register.
        using Addr = Register::Address<0x40094010,0x00000000,0x00000000,unsigned>;
        ///Time-out time value, bottom four bits. These are hard-wired                                to 0xF. This gives a minimum time-out of 16 I2C function clocks and                                also a time-out resolution of 16 I2C function clocks.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> tomin{}; 
        ///Time-out time value. Specifies the time-out interval value                                in increments of 16 I2C function clocks, as defined by the CLKDIV                                register. To change this value while I 2C is in operation, disable                                all time-outs, write a new value to TIMEOUT, then re-enable                                time-outs. 0x000 = A time-out will occur after 16 counts of the I2C                                function clock. 0x001 = A time-out will occur after 32 counts of the                                I2C function clock. ... 0xFFF = A time-out will occur after 65,536                                counts of the I2C function clock.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,4),Register::ReadWriteAccess,unsigned> to{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Clkdiv{    ///<Clock pre-divider for the entire I2C block. This determines what                        time increments are used for the MSTTIME register, and controls some timing                        of the Slave function.
        using Addr = Register::Address<0x40094014,0x00000000,0x00000000,unsigned>;
        ///This field controls how the clock (PCLK) is used by the I2C                                functions that need an internal clock in order to operate. 0x0000 =                                PCLK is used directly by the I2C. 0x0001 = PCLK is divided by 2                                before use. 0x0002 = PCLK is divided by 3 before use. ... 0xFFFF =                                PCLK is divided by 65,536 before use.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> divval{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Intstat{    ///<Interrupt Status register for Master, Slave, and Monitor                        functions.
        using Addr = Register::Address<0x40094018,0x00000000,0x00000000,unsigned>;
        ///Master Pending.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> mstpending{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Arbitration Loss flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> mstarbloss{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master Start/Stop Error flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> mstststperr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Pending.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> slvpending{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Not Stretching status.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> slvnotstr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,12),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Slave Deselected flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> slvdesel{}; 
        ///Monitor Ready.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> monrdy{}; 
        ///Monitor Overflow flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> monov{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Monitor Idle flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> monidle{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Event time-out Interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> eventtimeout{}; 
        ///SCL time-out Interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,unsigned> scltimeout{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,26),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Mstctl{    ///<Master control register.
        using Addr = Register::Address<0x40094020,0x00000000,0x00000000,unsigned>;
        ///Master Continue. This bit is write-only.
        enum class MstcontinueVal {
            noEffect=0x00000000,     ///<No effect.
            continue_=0x00000001,     ///<Continue. Informs the Master function to continue                                        to the next operation. This must done after writing transmit                                        data, reading received data, or any other housekeeping                                        related to the next bus operation.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,MstcontinueVal> mstcontinue{}; 
        namespace MstcontinueValC{
            constexpr Register::FieldValue<decltype(mstcontinue)::Type,MstcontinueVal::noEffect> noEffect{};
            constexpr Register::FieldValue<decltype(mstcontinue)::Type,MstcontinueVal::continue_> continue_{};
        }
        ///Master Start control. This bit is write-only.
        enum class MststartVal {
            noEffect=0x00000000,     ///<No effect.
            start=0x00000001,     ///<Start. A Start will be generated on the I2C bus at                                        the next allowed time.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,MststartVal> mststart{}; 
        namespace MststartValC{
            constexpr Register::FieldValue<decltype(mststart)::Type,MststartVal::noEffect> noEffect{};
            constexpr Register::FieldValue<decltype(mststart)::Type,MststartVal::start> start{};
        }
        ///Master Stop control. This bit is write-only.
        enum class MststopVal {
            noEffect=0x00000000,     ///<No effect.
            stop=0x00000001,     ///<Stop. A Stop will be generated on the I2C bus at                                        the next allowed time, preceded by a NACK to the slave if                                        the master is receiving data from the slave (Master Receiver                                        mode).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,MststopVal> mststop{}; 
        namespace MststopValC{
            constexpr Register::FieldValue<decltype(mststop)::Type,MststopVal::noEffect> noEffect{};
            constexpr Register::FieldValue<decltype(mststop)::Type,MststopVal::stop> stop{};
        }
        ///Master DMA enable. Data operations of the I2C can be                                performed with DMA. Protocol type operations such as Start, address,                                Stop, and address match must always be done with software, typically                                via an interrupt. When a DMA data transfer is complete, MSTDMA must                                be cleared prior to beginning the next operation, typically a Start                                or Stop.This bit is read/write.
        enum class MstdmaVal {
            disable=0x00000000,     ///<Disable. No DMA requests are generated for master                                        operation.
            enable=0x00000001,     ///<Enable. A DMA request is generated for I2C master                                        data operations. When this I2C master is generating                                        Acknowledge bits in Master Receiver mode, the acknowledge is                                        generated automatically.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,MstdmaVal> mstdma{}; 
        namespace MstdmaValC{
            constexpr Register::FieldValue<decltype(mstdma)::Type,MstdmaVal::disable> disable{};
            constexpr Register::FieldValue<decltype(mstdma)::Type,MstdmaVal::enable> enable{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,4),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Msttime{    ///<Master timing configuration.
        using Addr = Register::Address<0x40094024,0x00000000,0x00000000,unsigned>;
        ///Master SCL Low time. Specifies the minimum low time that                                will be asserted by this master on SCL. Other devices on the bus                                (masters or slaves) could lengthen this time. This corresponds to                                the parameter tLOW in the I2C bus specification. I2C bus                                specification parameters tBUF and t SU;STA have the same values and                                are also controlled by MSTSCLLOW.
        enum class MstscllowVal {
            v2Clocks=0x00000000,     ///<2 clocks. Minimum SCL low time is 2 clocks of the                                        I2C clock pre-divider.
            v3Clocks=0x00000001,     ///<3 clocks. Minimum SCL low time is 3 clocks of the                                        I2C clock pre-divider.
            v4Clocks=0x00000002,     ///<4 clocks. Minimum SCL low time is 4 clocks of the                                        I2C clock pre-divider.
            v5Clocks=0x00000003,     ///<5 clocks. Minimum SCL low time is 5 clocks of the                                        I2C clock pre-divider.
            v6Clocks=0x00000004,     ///<6 clocks. Minimum SCL low time is 6 clocks of the                                        I2C clock pre-divider.
            v7Clocks=0x00000005,     ///<7 clocks. Minimum SCL low time is 7 clocks of the                                        I2C clock pre-divider.
            v8Clocks=0x00000006,     ///<8 clocks. Minimum SCL low time is 8 clocks of the                                        I2C clock pre-divider.
            v9Clocks=0x00000007,     ///<9 clocks. Minimum SCL low time is 9 clocks of the                                        I2C clock pre-divider.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,MstscllowVal> mstscllow{}; 
        namespace MstscllowValC{
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v2Clocks> v2Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v3Clocks> v3Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v4Clocks> v4Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v5Clocks> v5Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v6Clocks> v6Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v7Clocks> v7Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v8Clocks> v8Clocks{};
            constexpr Register::FieldValue<decltype(mstscllow)::Type,MstscllowVal::v9Clocks> v9Clocks{};
        }
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Master SCL High time. Specifies the minimum high time that                                will be asserted by this master on SCL. Other masters in a                                multi-master system could shorten this time. This corresponds to the                                parameter tHIGH in the I2C bus specification. I2C bus specification                                parameters tSU;STO and tHD;STA have the same values and are also                                controlled by MSTSCLHIGH.
        enum class MstsclhighVal {
            v2Clocks=0x00000000,     ///<2 clocks. Minimum SCL high time is 2 clock of the                                        I2C clock pre-divider.
            v3Clocks=0x00000001,     ///<3 clocks. Minimum SCL high time is 3 clocks of the                                        I2C clock pre-divider .
            v4Clocks=0x00000002,     ///<4 clocks. Minimum SCL high time is 4 clock of the                                        I2C clock pre-divider.
            v5Clocks=0x00000003,     ///<5 clocks. Minimum SCL high time is 5 clock of the                                        I2C clock pre-divider.
            v6Clocks=0x00000004,     ///<6 clocks. Minimum SCL high time is 6 clock of the                                        I2C clock pre-divider.
            v7Clocks=0x00000005,     ///<7 clocks. Minimum SCL high time is 7 clock of the                                        I2C clock pre-divider.
            v8Clocks=0x00000006,     ///<8 clocks. Minimum SCL high time is 8 clock of the                                        I2C clock pre-divider.
            v9Clocks=0x00000007,     ///<9 clocks. Minimum SCL high time is 9 clocks of the                                        I2C clock pre-divider.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,4),Register::ReadWriteAccess,MstsclhighVal> mstsclhigh{}; 
        namespace MstsclhighValC{
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v2Clocks> v2Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v3Clocks> v3Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v4Clocks> v4Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v5Clocks> v5Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v6Clocks> v6Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v7Clocks> v7Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v8Clocks> v8Clocks{};
            constexpr Register::FieldValue<decltype(mstsclhigh)::Type,MstsclhighVal::v9Clocks> v9Clocks{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,7),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Mstdat{    ///<Combined Master receiver and transmitter data                        register.
        using Addr = Register::Address<0x40094028,0x00000000,0x00000000,unsigned>;
        ///Master function data register. Read: read the most recently                                received data for the Master function. Write: transmit data using                                the Master function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> data{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvctl{    ///<Slave control register.
        using Addr = Register::Address<0x40094040,0x00000004,0x00000000,unsigned>;
        ///Slave Continue.
        enum class SlvcontinueVal {
            noEffect=0x00000000,     ///<No effect.
            continue_=0x00000001,     ///<Continue. Informs the Slave function to continue to                                        the next operation. This must be done after writing transmit                                        data, reading received data, or any other housekeeping                                        related to the next bus operation.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,SlvcontinueVal> slvcontinue{}; 
        namespace SlvcontinueValC{
            constexpr Register::FieldValue<decltype(slvcontinue)::Type,SlvcontinueVal::noEffect> noEffect{};
            constexpr Register::FieldValue<decltype(slvcontinue)::Type,SlvcontinueVal::continue_> continue_{};
        }
        ///Slave NACK.
        enum class SlvnackVal {
            noEffect=0x00000000,     ///<No effect.
            nack=0x00000001,     ///<NACK. Causes the Slave function to NACK the master                                        when the slave is receiving data from the master (Slave                                        Receiver mode).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,SlvnackVal> slvnack{}; 
        namespace SlvnackValC{
            constexpr Register::FieldValue<decltype(slvnack)::Type,SlvnackVal::noEffect> noEffect{};
            constexpr Register::FieldValue<decltype(slvnack)::Type,SlvnackVal::nack> nack{};
        }
        ///Slave DMA enable.
        enum class SlvdmaVal {
            disabled=0x00000000,     ///<Disabled. No DMA requests are issued for Slave mode                                        operation.
            enabled=0x00000001,     ///<Enabled. DMA requests are issued for I2C slave data                                        transmission and reception.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,SlvdmaVal> slvdma{}; 
        namespace SlvdmaValC{
            constexpr Register::FieldValue<decltype(slvdma)::Type,SlvdmaVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(slvdma)::Type,SlvdmaVal::enabled> enabled{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,4),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvdat{    ///<Combined Slave receiver and transmitter data                        register.
        using Addr = Register::Address<0x40094044,0x00000000,0x00000000,unsigned>;
        ///Slave function data register. Read: read the most recently                                received data for the Slave function. Write: transmit data using the                                Slave function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> data{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvqual0{    ///<Slave Qualification for address 0.
        using Addr = Register::Address<0x40094058,0x00000000,0x00000000,unsigned>;
        ///Qualify mode for slave address 0.
        enum class Qualmode0Val {
            mask=0x00000000,     ///<Mask. The SLVQUAL0 field is used as a logical mask                                        for matching address 0.
            extend=0x00000001,     ///<Extend. The SLVQUAL0 field is used to extend                                        address 0 matching in a range of addresses.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Qualmode0Val> qualmode0{}; 
        namespace Qualmode0ValC{
            constexpr Register::FieldValue<decltype(qualmode0)::Type,Qualmode0Val::mask> mask{};
            constexpr Register::FieldValue<decltype(qualmode0)::Type,Qualmode0Val::extend> extend{};
        }
        ///Slave address Qualifier for address 0. A value of 0 causes                                the address in SLVADR0 to be used as-is, assuming that it is                                enabled. If QUALMODE0 = 0, any bit in this field which is set to 1                                will cause an automatic match of the corresponding bit of the                                received address when it is compared to the SLVADR0 register. If                                QUALMODE0 = 1, an address range is matched for address 0. This range                                extends from the value defined by SLVADR0 to the address defined by                                SLVQUAL0 (address matches when SLVADR0[7:1] <= received address                                <= SLVQUAL0[7:1]).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,1),Register::ReadWriteAccess,unsigned> slvqual0{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Monrxdat{    ///<Monitor receiver data register.
        using Addr = Register::Address<0x40094080,0x00000000,0x00000000,unsigned>;
        ///Monitor function Receiver Data. This reflects every data                                byte that passes on the I2C pins.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> monrxdat{}; 
        ///Monitor Received Start.
        enum class MonstartVal {
            noStartDetected=0x00000000,     ///<No start detected. The monitor function has not                                        detected a Start event on the I2C bus.
            startDetected=0x00000001,     ///<Start detected. The monitor function has detected a                                        Start event on the I2C bus.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,MonstartVal> monstart{}; 
        namespace MonstartValC{
            constexpr Register::FieldValue<decltype(monstart)::Type,MonstartVal::noStartDetected> noStartDetected{};
            constexpr Register::FieldValue<decltype(monstart)::Type,MonstartVal::startDetected> startDetected{};
        }
        ///Monitor Received Repeated Start.
        enum class MonrestartVal {
            noRepeatedStartDe=0x00000000,     ///<No repeated start detected. The monitor function                                        has not detected a Repeated Start event on the I2C                                        bus.
            repeatedStartDetec=0x00000001,     ///<Repeated start detected. The monitor function has                                        detected a Repeated Start event on the I2C                                        bus.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,MonrestartVal> monrestart{}; 
        namespace MonrestartValC{
            constexpr Register::FieldValue<decltype(monrestart)::Type,MonrestartVal::noRepeatedStartDe> noRepeatedStartDe{};
            constexpr Register::FieldValue<decltype(monrestart)::Type,MonrestartVal::repeatedStartDetec> repeatedStartDetec{};
        }
        ///Monitor Received NACK.
        enum class MonnackVal {
            acknowledged=0x00000000,     ///<Acknowledged. The data currently being provided by                                        the monitor function was acknowledged by at least one master                                        or slave receiver.
            notAcknowledged=0x00000001,     ///<Not acknowledged. The data currently being provided                                        by the monitor function was not acknowledged by any                                        receiver.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,MonnackVal> monnack{}; 
        namespace MonnackValC{
            constexpr Register::FieldValue<decltype(monnack)::Type,MonnackVal::acknowledged> acknowledged{};
            constexpr Register::FieldValue<decltype(monnack)::Type,MonnackVal::notAcknowledged> notAcknowledged{};
        }
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,11),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvadr0{    ///<Slave address 0.
        using Addr = Register::Address<0x40094048,0x00000000,0x00000000,unsigned>;
        ///Slave Address n Disable.
        enum class SadisableVal {
            enabled=0x00000000,     ///<Enabled. Slave Address n is enabled.
            ignoredSlaveAddres=0x00000001,     ///<Ignored Slave Address n is ignored.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,SadisableVal> sadisable{}; 
        namespace SadisableValC{
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::ignoredSlaveAddres> ignoredSlaveAddres{};
        }
        ///Slave Address. Seven bit slave address that is compared to                                received addresses if enabled.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,1),Register::ReadWriteAccess,unsigned> slvadr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvadr1{    ///<Slave address 0.
        using Addr = Register::Address<0x4009404c,0x00000000,0x00000000,unsigned>;
        ///Slave Address n Disable.
        enum class SadisableVal {
            enabled=0x00000000,     ///<Enabled. Slave Address n is enabled.
            ignoredSlaveAddres=0x00000001,     ///<Ignored Slave Address n is ignored.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,SadisableVal> sadisable{}; 
        namespace SadisableValC{
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::ignoredSlaveAddres> ignoredSlaveAddres{};
        }
        ///Slave Address. Seven bit slave address that is compared to                                received addresses if enabled.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,1),Register::ReadWriteAccess,unsigned> slvadr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvadr2{    ///<Slave address 0.
        using Addr = Register::Address<0x40094050,0x00000000,0x00000000,unsigned>;
        ///Slave Address n Disable.
        enum class SadisableVal {
            enabled=0x00000000,     ///<Enabled. Slave Address n is enabled.
            ignoredSlaveAddres=0x00000001,     ///<Ignored Slave Address n is ignored.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,SadisableVal> sadisable{}; 
        namespace SadisableValC{
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::ignoredSlaveAddres> ignoredSlaveAddres{};
        }
        ///Slave Address. Seven bit slave address that is compared to                                received addresses if enabled.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,1),Register::ReadWriteAccess,unsigned> slvadr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace I2c0Slvadr3{    ///<Slave address 0.
        using Addr = Register::Address<0x40094054,0x00000000,0x00000000,unsigned>;
        ///Slave Address n Disable.
        enum class SadisableVal {
            enabled=0x00000000,     ///<Enabled. Slave Address n is enabled.
            ignoredSlaveAddres=0x00000001,     ///<Ignored Slave Address n is ignored.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,SadisableVal> sadisable{}; 
        namespace SadisableValC{
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(sadisable)::Type,SadisableVal::ignoredSlaveAddres> ignoredSlaveAddres{};
        }
        ///Slave Address. Seven bit slave address that is compared to                                received addresses if enabled.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,1),Register::ReadWriteAccess,unsigned> slvadr{}; 
        ///Reserved. Read value is undefined, only zero should be                                written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
