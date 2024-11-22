cmake_minimum_required(VERSION 3.10)

project(camera_tests LANGUAGES CXX) 
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(src_path ${CMAKE_SOURCE_DIR}/src)
set(TriggerAVT_src ${src_path}/TriggerAVT)
set(Webcam_src ${src_path}/Webcam)



add_executable(Webcam ${Webcam_src}/main.cpp)
add_executable(TriggerAVT
${TriggerAVT_src}/main.cpp
${TriggerAVT_src}/trigger_avt.cpp
)

add_subdirectory(Boost_tests)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV library : ${OpenCV_LIBS}, include : ${OpenCV_INCLUDE_DIRS}")
target_link_libraries(Webcam ${OpenCV_LIBS})
target_link_libraries(TriggerAVT ${OpenCV_LIBS})



