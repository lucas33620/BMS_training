cmake_minimum_required(VERSION 3.20)

project(
    BMS_training 
    VERSION 0.1.0
    DESCRIPTION "Battery Management System Training"
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(modules/cell_monitor_interface)
add_subdirectory(modules/afe_session)
add_subdirectory(modules/cell_voltage_reader)
add_subdirectory(modules/shared)
add_subdirectory(modules/battery_pack)
add_subdirectory(modules/battery_monitor)

add_executable(BMS_training)

target_sources(BMS_training PRIVATE
    app/main.cpp
)

target_link_libraries(BMS_training PRIVATE
    battery_monitor
    battery_pack
    afe_session
    cell_voltage_reader
)
