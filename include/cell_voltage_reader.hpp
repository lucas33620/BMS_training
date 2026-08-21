#pragma once

#include "cell_voltage_types.hpp"
#include "i_cell_monitor.hpp"

namespace bms 
{
    class CellVoltageReader : public ICellMonitor
    {
    public:
        CellVoltageReader(uint8_t cell_number);

        void read_cell_voltage();

        CellVoltageData get_measurement() const override;

    private:
        uint8_t cell_number;
        CellVoltageData measurement;
    };
} // namespace bms