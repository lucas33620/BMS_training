#pragma once

#include "i_cell_monitor.hpp"

namespace bms 
{
    enum class CellVoltageStatus : uint8_t
    {
        INVALID = 0,
        NORMAL,
        UNDERVOLTAGE,
        OVERVOLTAGE
    };

    class BatteryMonitor
    {
    public:
        BatteryMonitor(ICellMonitor& reader);
        CellVoltageStatus check_cell_voltage() const;
        CellVoltageStatus check_cell_voltage(const CellVoltageData& data) const;

    private:
        ICellMonitor& reader; // Reference to the original CellVoltageReader instance

    };
} // namespace bms