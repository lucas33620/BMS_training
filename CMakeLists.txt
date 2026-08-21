cmake_minimum_required(VERSION 3.20)

project(BMS_training LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BMS_training 
    app/main.cpp
    src/cell_voltage_reader.cpp
    src/battery_monitor.cpp
    src/afe_session.cpp
)

target_include_directories(BMS_training PRIVATE
    include
)