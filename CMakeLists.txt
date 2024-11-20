cmake_minimum_required(VERSION 3.10)

project(opencv_learning LANGUAGES CXX) 
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

add_executable(logitech_webcam ${CMAKE_SOURCE_DIR}/logitech_webcam/main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(logitech_webcam ${OpenCV_LIBS})