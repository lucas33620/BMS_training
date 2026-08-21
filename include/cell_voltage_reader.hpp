#pragma once

#include <cstdint>

namespace bms 
{
    enum class CellMeasurementValidity : uint8_t
    {
        INVALID = 0,
        VALID
    };

    struct CellVoltageData
    {
        uint16_t voltage;
        CellMeasurementValidity validity;
    };

    class CellVoltageReader
    {
    public:
        CellVoltageReader(uint8_t cell_number);

        void read_cell_voltage();

        CellVoltageData get_measurement() const;

    private:
        uint8_t cell_number;
        CellVoltageData measurement;
    };
} // namespace bms