add_library(battery_pack)

target_sources(battery_pack PRIVATE
    src/battery_pack.cpp
)

target_include_directories(battery_pack PUBLIC
    include
)

target_link_libraries(battery_pack PUBLIC
    shared
)