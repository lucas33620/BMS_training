#include "battery_pack.hpp"

namespace bms
{
    BatteryPack::BatteryPack()
    {
        for (std::size_t i = 0; i < CELL_COUNT; i++)
        {
            cells[i].voltage = 0U;
            cells[i].validity = CellMeasurementValidity::INVALID;
        }
    }

    const std::array<CellVoltageData, BatteryPack::CELL_COUNT>& BatteryPack::get_cells() const
    {
        return cells;
    }

    bool BatteryPack::set_cell(std::size_t index, const CellVoltageData& data)
    {
        if (index < CELL_COUNT)
        {
            cells[index] = data;
            return true;
        }
        return false;
    }

} // Allow to avoid using the namespace bms:: prefix every time when using the BatteryPack class.