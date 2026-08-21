#pragma once

#include "cell_voltage_reader.hpp"

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
        BatteryMonitor(CellVoltageReader& reader);
        CellVoltageStatus check_cell_voltage() const;
        CellVoltageStatus check_cell_voltage(const CellVoltageData& data) const;

    private:
    CellVoltageReader& reader; // Reference to the original CellVoltageReader instance

    };
} // namespace bms