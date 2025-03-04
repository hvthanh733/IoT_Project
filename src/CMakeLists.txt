cmake_minimum_required(VERSION 3.10)

set(SOURCES
    main.cpp
    hu_temp_sensor.cpp
    fire_sensor.cpp
    mqtt_publisher.cpp
    gpio_control.cpp
    Saver.cpp
    BusinessHandler.cpp
)

add_executable(raspberry ${SOURCES})

# Nếu sử dụng thư viện WiringPi, MQTT
target_link_libraries(raspberry wiringPi)
