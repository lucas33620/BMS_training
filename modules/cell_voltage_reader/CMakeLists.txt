# Library
add_library(cell_voltage_reader)

target_sources(cell_voltage_reader PRIVATE
    src/cell_voltage_reader.cpp
)

target_include_directories(cell_voltage_reader PUBLIC
    include
)

# Linker libraries
target_link_libraries(cell_voltage_reader PUBLIC
    cell_monitor_interface
    shared
)