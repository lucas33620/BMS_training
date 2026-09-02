cmake_minimum_required(VERSION 3.20)
project (BMS_training VERSION 0.1.0 LANGUAGES CXX)

# # Project modules (interfact -> low-level -> APP)
add_subdirectory(modules/cell_monitor_interface)
add_subdirectory(modules/shared)
add_subdirectory(modules/afe_session)
add_subdirectory(modules/battery_pack)
add_subdirectory(modules/cell_voltage_reader)
add_subdirectory(modules/battery_monitor)

# Executable
add_executable(BMS_training)

target_sources(BMS_training PRIVATE
    app/main.cpp
)

# Linker libraries
target_link_libraries(BMS_training PRIVATE
    battery_monitor
    battery_pack
    afe_session
    cell_voltage_reader
)

# Google Test
enable_testing()
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)
add_subdirectory(tests)