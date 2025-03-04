cmake_minimum_required(VERSION 3.10)
project(IoT_Project)

set(CMAKE_CXX_STANDARD 17)

# Thêm thư mục chứa file header
include_directories(${CMAKE_SOURCE_DIR}/include)

# Gọi CMakeLists.txt của src và backend
add_subdirectory(src)
add_subdirectory(backend)
