#pragma once

#include "cell_voltage_types.hpp"

namespace bms
{
    // Interface of CellVoltageReader
    class ICellMonitor
    {
    public :
        virtual ~ICellMonitor() = default;

        virtual CellVoltageData get_measurement() const = 0;
    };

}