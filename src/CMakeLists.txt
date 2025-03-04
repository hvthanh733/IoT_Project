cmake_minimum_required(VERSION 3.10)
# Tìm các thư viện cần thiết
find_package(PkgConfig REQUIRED)
pkg_check_modules(MOSQUITTO REQUIRED libmosquitto)
pkg_check_modules(HIREDIS REQUIRED hiredis)

# Thêm thư mục chứa file header
include_directories(${MOSQUITTO_INCLUDE_DIRS} ${HIREDIS_INCLUDE_DIRS})

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
target_link_libraries(raspberry 
    ${MOSQUITTO_LIBRARIES}
    ${HIREDIS_LIBRARIES}
    wiringPi
)
