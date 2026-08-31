add_library(battery_monitor)

target_sources(battery_monitor PRIVATE
    battery_monitor.cpp
)

target_include_directories(battery_monitor PUBLIC
    ../include
)