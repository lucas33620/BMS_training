# Library
add_library(battery_monitor)

target_sources(battery_monitor PRIVATE
    src/battery_monitor.cpp
)

target_include_directories(battery_monitor PUBLIC
    include
)

# Linker libraries
target_link_libraries(battery_monitor PUBLIC
    cell_monitor_interface
    battery_pack
    shared
)

