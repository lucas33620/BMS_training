add_library(battery_monitor)

target_sources(battery_monitor PRIVATE
    src/battery_monitor.cpp
)

target_include_directories(battery_monitor PUBLIC
    include
)

target_link_libraries(battery_monitor PUBLIC
    cell_monitor_interface
)

target_link_libraries(battery_monitor PUBLIC
    shared
)

target_link_libraries(battery_monitor PUBLIC
    battery_pack
)