# Executable
add_executable(battery_monitor_tests)

target_sources(battery_monitor_tests PRIVATE
    battery_monitor_test.cpp
)

# Linker libraries
target_link_libraries(battery_monitor_tests PRIVATE
    battery_monitor
    cell_voltage_reader
    GTest::gtest_main
)