cmake_minimum_required(VERSION 3.5.1)
project(libffi_learn)

set(CMAKE_CXX_STANDARD 14)

include_directories(./libffi/include)
set(googleTestDir ./googletest)
add_subdirectory(${googleTestDir})
include_directories(${googleTestDir}/googletest/include)
include_directories(${googleTestDir}/googlemock/include)

add_executable(${PROJECT_NAME} main.cpp ./test/test.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libffi/lib/libffi.a ${PROJECT_SOURCE_DIR}/libffi/lib/libffi_convenience.a)

target_link_libraries(${PROJECT_NAME}  gtest gtest_main)
target_link_libraries(${PROJECT_NAME}  gmock gmock)