#include <gtest/gtest.h>

#include "battery_monitor.hpp"
#include "cell_voltage_reader.hpp"

namespace bms
{
    TEST(BatteryMonitorTest, VoltageBelowLowerThresholdReturnsUndervoltage)
    {
        CellVoltageReader reader(2);
        BatteryMonitor monitor(reader);

        CellVoltageData cell;
        cell.voltage = 2999;
        cell.validity = CellMeasurementValidity::VALID;

        const auto status = monitor.check_cell_voltage(cell);

        EXPECT_EQ(status, CellVoltageStatus::UNDERVOLTAGE);
    }

    TEST(BatteryMonitorTest, VoltageAtLowerThresholdReturnsNormal)
    {
        CellVoltageReader reader(2);
        BatteryMonitor monitor(reader);

        CellVoltageData cell;
        cell.voltage = 3000 ;
        cell.validity = CellMeasurementValidity::VALID;

        const auto status = monitor.check_cell_voltage(cell);

        EXPECT_EQ(CellVoltageStatus::NORMAL, status);
    }

    TEST(BatteryMonitorTest, VoltageAtUpperThresholdReturnsNormal)
    {
        CellVoltageReader reader(2);
        BatteryMonitor monitor(reader);

        CellVoltageData cell;
        cell.voltage = 4200;
        cell.validity = CellMeasurementValidity::VALID;

        const auto status = monitor.check_cell_voltage(cell);

        EXPECT_EQ(CellVoltageStatus::NORMAL, status);
    }

    TEST(BatteryMonitorTest, VoltageAboveUpperThresholdReturnsOvervoltage)
    {
        CellVoltageReader reader(2);
        BatteryMonitor monitor(reader);

        CellVoltageData cell;
        cell.voltage = 4201;
        cell.validity = CellMeasurementValidity::VALID;

        const auto status = monitor.check_cell_voltage(cell);

        EXPECT_EQ(CellVoltageStatus::OVERVOLTAGE, status);
    }
}