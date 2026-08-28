/**
 * @file    main.cpp
 * @brief   Application entry point for the project.
 * @author  Syloria, Lucas Baquey
 *
 * @copyright MIT License
 *
 * Summary: Permission is granted, free of charge, to any person obtaining a copy
 * of this software to deal in the Software without restriction, including the rights
 * to use, copy, modify, merge, publish, distribute, sublicense and/or sell copies.
 * The software is provided "as is", without warranty of any kind.
 */

#include <iostream>
#include "cell_voltage_reader.hpp"
#include "battery_monitor.hpp"
#include "afe_session.hpp"
#include "battery_pack.hpp"

/**
 * @brief   Main function of the application.
 * @return  Exit status code.
 */
int main()
{
    std::cout << "INFO : BMS training started" << std::endl;

    bms::CellVoltageReader reader(2);
    bms::BatteryMonitor monitor(reader);
    bms::BatteryPack battery_pack;

    {
        bms::AfeSession session;

        // Simulate acquisition of cell 2
        reader.read_cell_voltage();

        // Get acquired measurement
        const auto measurement = reader.get_measurement();

        // Store cell 2 measurement in BatteryPack
        constexpr std::size_t CELL_2_INDEX = 1;
        const auto result = battery_pack.set_cell(CELL_2_INDEX, measurement);

        if (result == bms::BatteryPackResult::OK)
        {
            const auto& cells = battery_pack.get_cells();
            const auto& cell_data = cells[CELL_2_INDEX];

            // Analyze only cell 2
            const auto status = monitor.check_cell_voltage(cell_data);

            std::cout
                << "Cell 2: Voltage = "
                << cell_data.voltage
                << " mV, Validity = "
                << (cell_data.validity == bms::CellMeasurementValidity::VALID
                        ? "VALID"
                        : "INVALID")
                << ", Status = "
                << (status == bms::CellVoltageStatus::NORMAL
                        ? "NORMAL"
                        : status == bms::CellVoltageStatus::UNDERVOLTAGE
                            ? "UNDERVOLTAGE"
                            : status == bms::CellVoltageStatus::OVERVOLTAGE
                                ? "OVERVOLTAGE"
                                : "INVALID")
                << '\n';
        }
    }

    return 0;
}