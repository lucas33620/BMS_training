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
        CellVoltageStatus check_cell_voltage(const CellVoltageData& data);

    private:

    };
} // namespace bms