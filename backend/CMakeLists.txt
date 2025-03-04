cmake_minimum_required(VERSION 3.10)

set(SOURCES
    server.cpp
    mqtt_handler.cpp
    database.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(backend ${SOURCES})

