
#include "cell_voltage_reader.hpp"

// Constructors
bms::CellVoltageReader::CellVoltageReader(uint8_t cell_number)
    : cell_number(cell_number), measurement{0, bms::CellMeasurementValidity::INVALID}
{
}

// Methods
void bms::CellVoltageReader::read_cell_voltage()
{
    measurement.voltage = 2650;
    measurement.validity = bms::CellMeasurementValidity::VALID;

    // Simulation
}

bms::CellVoltageData bms::CellVoltageReader::get_measurement() const
{
    return measurement;
}