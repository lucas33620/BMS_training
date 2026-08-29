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

    const std::array<bms::CellVoltageData, 4> test_cells =
    {{
        {3650, bms::CellMeasurementValidity::VALID},
        {0, bms::CellMeasurementValidity::VALID},
        {3900, bms::CellMeasurementValidity::VALID},
        {4100, bms::CellMeasurementValidity::VALID}
    }};

    bms::CellVoltageReader reader(2);
    bms::BatteryMonitor monitor(reader);
    bms::BatteryPack battery_pack;

    {
        bms::AfeSession session;

        bool pack_initialized = true;

        for (std::size_t i = 0; i < test_cells.size(); ++i)
        {
            const auto result = battery_pack.set_cell(i, test_cells[i]);

            if (result != true)
            {
                pack_initialized = false;

                std::cerr
                    << "ERROR : Failed to set cell "
                    << i + 1
                    << " data."
                    << std::endl;
            }
        }

        if (pack_initialized)
        {

            // Simulate acquisition of cell 2
            reader.read_cell_voltage();

            // Get acquired measurement
            const auto measurement = reader.get_measurement();

            // Store cell 2 measurement in BatteryPack
            constexpr std::size_t CELL_2_INDEX = 1;
            const bool result = battery_pack.set_cell(CELL_2_INDEX, measurement);

            if (result == true)
            {
                const auto pack_status =
                monitor.check_battery_pack(battery_pack);

                std::cout
                    << "Pack status: "
                    << (pack_status.status == bms::CellVoltageStatus::NORMAL
                            ? "NORMAL"
                            : pack_status.status == bms::CellVoltageStatus::UNDERVOLTAGE
                                ? "UNDERVOLTAGE"
                                : pack_status.status == bms::CellVoltageStatus::OVERVOLTAGE
                                    ? "OVERVOLTAGE"
                                    : "INVALID")
                    << '\n';

                std::cout
                    << "Min voltage: "
                    << pack_status.voltage_min
                    << " mV\n";

                std::cout
                    << "Max voltage: "
                    << pack_status.voltage_max
                    << " mV\n";
            }
        }
    }   

    return 0;
}