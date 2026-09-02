#include <gtest/gtest.h>

#include "battery_monitor.hpp"
#include "cell_voltage_reader.hpp"

namespace bms
{
    TEST(BatteryMonitorTest, TestCellVoltageReturnsUndervoltage)
    {
        CellVoltageReader reader;
        BatteryMonitor monitor(reader);

        CellVoltageData cell;
        cell.voltage = 2999;
        cell.validity = CellMeasurementValidity::VALID;

        const auto status = monitor.check_cell_voltage(cell);

        EXPECT_EQ(status, CellVoltageStatus::UNDERVOLTAGE);
    }

    TEST(BatteryMonitorTest, ValidCellVoltageReturnsNormal)
    {
        bms::CellVoltageReader reader(2);
        bms::BatteryMonitor monitor(reader);

        bms::CellVoltageData cell;
        cell.voltage = 3000 ;
        cell.validity = bms::CellMeasurementValidity::VALID;

        const auto status = monitor.check_cell_voltage(cell);

        EXPECT_EQ(bms::CellVoltageStatus::NORMAL, status);
    }
}