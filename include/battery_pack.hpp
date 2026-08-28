#pragma once
#include "cell_voltage_types.hpp"
#include <array>
#include <cstddef>

namespace bms
{
    enum class BatteryPackResult : uint8_t
    {
        OK = 0,
        INVALID_INDEX
    };

    class BatteryPack
    {
    public :
        BatteryPack();
        static constexpr std::size_t CELL_COUNT = 4;

        const std::array<CellVoltageData, CELL_COUNT>& get_cells() const;
        BatteryPackResult set_cell(std::size_t index, const CellVoltageData& data);

    private :
        std::array<CellVoltageData, CELL_COUNT> cells; // cells have exactly 4 éléments of type CellVoltageData (std::array<T, N>)

    };

}