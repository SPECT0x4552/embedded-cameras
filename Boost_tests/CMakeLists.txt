cmake_minimum_required(VERSION 3.10)

set(Boost_USE_STATIC_LIBS OFF)
set(TriggerAVT_tests_src ${CMAKE_SOURCE_DIR}/TriggerAVT_tests)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})
message("Boost library : ${Boost_LIBRARY_DIRS}, include : ${Boost_INCLUDE_DIRS}")

add_executable (TriggerAVT_Boost_tests_run 
    ${TriggerAVT_tests_src}/Camera_tests.cpp
    ${TriggerAVT_tests_src}/Error_tests.cpp
    ${TriggerAVT_tests_src}/Integration_tests.cpp
    ${TriggerAVT_tests_src}/TriggerSignal_tests.cpp
)

target_link_libraries(TriggerAVT_Boost_tests_run ${Boost_LIBRARIES})