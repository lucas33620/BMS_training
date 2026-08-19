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
/**
 * @brief   Main function of the application.
 * @return  Exit status code.
 */
int main()
{
    std::cout << "INFO : BMS training started" << std::endl;

    bms::CellVoltageReader reader(2);

    reader.read_cell_voltage();

    bms::CellVoltageData data = reader.get_measurement();

    std::cout << "Cell voltage: "
            << data.voltage
            << " mV\n"
            << "Measure validity : "
            << (data.validity == bms::CellMeasurementValidity::VALID ? "VALID" : "INVALID")
            << "\n";

    return 0;
}