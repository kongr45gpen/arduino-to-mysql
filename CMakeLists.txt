cmake_minimum_required(VERSION 3.8)
project(arduino_to_mysql)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.50 COMPONENTS system REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(arduino_to_mysql ${SOURCE_FILES})
target_link_libraries(arduino_to_mysql mysqlcppconn ${Boost_LIBRARIES})

set(CMAKE_VERBOSE_MAKEFILE ON)
