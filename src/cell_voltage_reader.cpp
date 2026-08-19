
#include "cell_voltage_reader.hpp"

// Constructors
CellVoltageReader::CellVoltageReader(uint8_t cell_number)
    : cell_number(cell_number), measurement{0, CELL_MEASUREMENT_INVALID}
{
}

// Methods
void CellVoltageReader::read_cell_voltage()
{
    measurement.voltage = 3650;
    measurement.validity = CELL_MEASUREMENT_VALID;

    // Simulation
}

CellVoltageData CellVoltageReader::get_measurement() const
{
    return measurement;
}