#include "battery_monitor.hpp"

namespace bms
{
    BatteryMonitor::BatteryMonitor(ICellMonitor& reader)
        :reader(reader)
    {
    }

    CellVoltageStatus BatteryMonitor::check_cell_voltage() const
    {
        CellVoltageData data = reader.get_measurement();

        return check_cell_voltage(data);    
    }

    CellVoltageStatus BatteryMonitor::check_cell_voltage(const CellVoltageData& data) const
    {
        if (data.validity == CellMeasurementValidity::INVALID)
        {
            return CellVoltageStatus::INVALID;
        }

        if (data.voltage < 3000)
        {
            return CellVoltageStatus::UNDERVOLTAGE;
        }
        else if (data.voltage > 4200)
        {
            return CellVoltageStatus::OVERVOLTAGE;
        }
        return CellVoltageStatus::NORMAL;
        
    }

    BatteryPackResult BatteryMonitor::check_battery_pack(const BatteryPack& pack) const
    {
        uint16_t voltage_min = 0;
        uint16_t voltage_max = 0;

        CellVoltageStatus pack_status = CellVoltageStatus::NORMAL;
        bool has_valid_measurement = false;

        const auto& cells = pack.get_cells();

        for (std::size_t i = 0; i < BatteryPack::CELL_COUNT; ++i)
        {
            const CellVoltageStatus cell_status = check_cell_voltage(cells[i]);

            if (cell_status == CellVoltageStatus::INVALID)
            {
                pack_status = CellVoltageStatus::INVALID;
                continue;
            }

            if (cell_status == CellVoltageStatus::OVERVOLTAGE &&
                pack_status != CellVoltageStatus::INVALID)
            {
                pack_status = CellVoltageStatus::OVERVOLTAGE;
            }
            else if (cell_status == CellVoltageStatus::UNDERVOLTAGE &&
                    pack_status != CellVoltageStatus::INVALID &&
                    pack_status != CellVoltageStatus::OVERVOLTAGE)
            {
                pack_status = CellVoltageStatus::UNDERVOLTAGE;
            }

            if (!has_valid_measurement)
            {
                voltage_min = cells[i].voltage;
                voltage_max = cells[i].voltage;
                has_valid_measurement = true;
            }
            else
            {
                if (cells[i].voltage < voltage_min)
                {
                    voltage_min = cells[i].voltage;
                }

                if (cells[i].voltage > voltage_max)
                {
                    voltage_max = cells[i].voltage;
                }
            }
        }

        return BatteryPackResult{
            pack_status,
            voltage_min,
            voltage_max
        };
    }

}