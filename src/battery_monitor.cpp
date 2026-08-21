#include "battery_monitor.hpp"

bms::BatteryMonitor::BatteryMonitor(CellVoltageReader& reader)
    :reader(reader)
{
}

bms::CellVoltageStatus bms::BatteryMonitor::check_cell_voltage() const
{
    CellVoltageData data = reader.get_measurement();
    return check_cell_voltage(data);
    
}

bms::CellVoltageStatus bms::BatteryMonitor::check_cell_voltage(const CellVoltageData& data) const
{
    if (data.validity == CellMeasurementValidity::INVALID)
    {
        return CellVoltageStatus::INVALID;
    }

    if (data.voltage < 3000)
    {
        return bms::CellVoltageStatus::UNDERVOLTAGE;
    }
    else if (data.voltage > 4200)
    {
        return bms::CellVoltageStatus::OVERVOLTAGE;
    }
    return bms::CellVoltageStatus::NORMAL;
    
}