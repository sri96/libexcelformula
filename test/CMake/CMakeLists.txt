cmake_minimum_required(VERSION 3.10.1)

project(ut)

message("Building ut with high levels of optimization, address and leak sanitization and high levels of warnings")
set(CMAKE_CXX_FLAGS "-std=c++1z -o3 -fsanitize=address -Wall -Wextra")

add_executable(ut ../unit_test_driver.cpp)