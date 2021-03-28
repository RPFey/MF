cmake_minimum_required(VERSION 3.10)
project(Serial)

set(CMAKE_CXX_STANDARD 11)
add_library(SerialDevice serial.c Device.cpp pwm.cpp)
target_link_libraries(SerialDevice wiringPi)

add_executable(Serial main.cpp)
target_link_libraries(Serial SerialDevice)

add_executable(pwm pwm.cpp)
target_link_libraries(pwm wiringPi pthread)