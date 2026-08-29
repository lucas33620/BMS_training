#pragma once

#include "i_cell_monitor.hpp"
#include "battery_pack.hpp"
#include "cell_voltage_types.hpp"
#include "numeric_utils.hpp"
#include "battery_monitor_cfg.hpp"

namespace bms 
{
    enum class CellVoltageStatus : uint8_t
    {
        INVALID = 0,
        NORMAL,
        UNDERVOLTAGE,
        OVERVOLTAGE
    };

    // Invalid > Overvoltage > Undervoltage > Normal
    struct BatteryPackResult
    {
        CellVoltageStatus status;
        uint16_t voltage_min;
        uint16_t voltage_max;
    };

    class BatteryMonitor
    {
    public:
        BatteryMonitor(ICellMonitor& reader);
        CellVoltageStatus check_cell_voltage() const;
        CellVoltageStatus check_cell_voltage(const CellVoltageData& data) const;

        BatteryPackResult check_battery_pack(const BatteryPack& pack) const;

    private:
        ICellMonitor& reader; // Reference to the original CellVoltageReader instance

    };
} // namespace bms