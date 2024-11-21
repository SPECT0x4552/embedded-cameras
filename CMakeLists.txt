cmake_minimum_required(VERSION 3.10)

project(camera_tests LANGUAGES CXX) 
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

add_executable(logitech_webcam ${CMAKE_SOURCE_DIR}/logitech_webcam/main.cpp)

add_executable(TriggerAVT ${CMAKE_SOURCE_DIR}/TriggerAVT/main.cpp)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV library : ${OpenCV_LIBS}, include : ${OpenCV_INCLUDE_DIRS}")

find_package(Boost COMPONENTS timer REQUIRED)
target_link_libraries(logitech_webcam ${OpenCV_LIBS})
target_link_libraries(TriggerAVT PUBLIC Boost::headers Boost::timer)
message("Boost library : ${Boost_LIBRARY_DIRS}, include : ${Boost_INCLUDE_DIRS}")
