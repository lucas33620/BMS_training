#include <cstdint>

enum CellMeasurementValidity
{
    CELL_MEASUREMENT_INVALID = 0,
    CELL_MEASUREMENT_VALID
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