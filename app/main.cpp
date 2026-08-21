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

/**
 * @brief   Main function of the application.
 * @return  Exit status code.
 */
int main()
{
    std::cout << "INFO : BMS training started" << std::endl;

    bms::CellVoltageReader reader(2);
    bms::BatteryMonitor monitor(reader);

    reader.read_cell_voltage();

    auto status = monitor.check_cell_voltage();

    std::cout << "Before scope\n";

    { // Scope

        bms::AfeSession session;
        std::cout << "Inside scope\n";

        /* Debug section */
        std::cout << "Cell voltage: "
                << "Voltage status: "
                << (status == bms::CellVoltageStatus::NORMAL ? "NORMAL\n" : (status == bms::CellVoltageStatus::UNDERVOLTAGE ? "UNDERVOLTAGE\n" : (status == bms::CellVoltageStatus::OVERVOLTAGE ? "OVERVOLTAGE\n" : "INVALID\n")))
                << std::endl;

    } // Destructor of AfeSession at the end of the scope

    std::cout << "After scope\n";

    return 0;
}