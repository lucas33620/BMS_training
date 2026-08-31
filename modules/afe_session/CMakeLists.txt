add_library(afe_session)

target_sources(afe_session PRIVATE
    src/afe_session.cpp
)

target_include_directories(afe_session PUBLIC
    include
)

target_link_libraries(afe_session PUBLIC
    shared
)