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

add_library(battery_monitor)

target_sources(battery_monitor PRIVATE
    src/battery_monitor.cpp
)

target_include_directories(battery_monitor PUBLIC
    include
)

add_executable(BMS_training)

target_sources(BMS_training PRIVATE
    app/main.cpp
    src/cell_voltage_reader.cpp
    src/afe_session.cpp
    src/battery_pack.cpp
)

target_link_libraries(BMS_training PRIVATE
    battery_monitor
)