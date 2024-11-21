cmake_minimum_required(VERSION 3.10)

project(camera_tests LANGUAGES CXX) 
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

add_executable(logitech_webcam ${CMAKE_SOURCE_DIR}/logitech_webcam/main.cpp)


