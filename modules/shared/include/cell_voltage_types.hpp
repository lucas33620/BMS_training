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
} // namespace bms