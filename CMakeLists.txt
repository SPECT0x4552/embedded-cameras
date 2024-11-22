cmake_minimum_required(VERSION 3.10)

project(camera_tests LANGUAGES CXX) 
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

add_executable(Webcam ${CMAKE_SOURCE_DIR}/Webcam/main.cpp)
add_executable(TriggerAVT
${CMAKE_SOURCE_DIR}/TriggerAVT/main.cpp 
${CMAKE_SOURCE_DIR}/TriggerAVT/trigger_avt.cpp
)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV library : ${OpenCV_LIBS}, include : ${OpenCV_INCLUDE_DIRS}")

target_link_libraries(Webcam ${OpenCV_LIBS})



