#include "battery_monitor.hpp"

bms::CellVoltageStatus bms::BatteryMonitor::check_cell_voltage(const CellVoltageData& data)
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