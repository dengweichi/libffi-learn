cmake_minimum_required(VERSION 3.5.1)
project(libffi_learn)

set(CMAKE_CXX_STANDARD 14)

include_directories(./libffi/include)
set(googleTestDir ./googletest)
add_subdirectory(${googleTestDir})
include_directories(${googleTestDir}/googletest/include)
include_directories(${googleTestDir}/googlemock/include)

add_executable(${PROJECT_NAME} main.cpp test/call.cpp test/closure.cpp)

# 链接libffi
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libffi/lib/release/libffi.a ${PROJECT_SOURCE_DIR}/libffi/lib/release/libffi_convenience.a)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libffi/lib/debug/libffi.a ${PROJECT_SOURCE_DIR}/libffi/lib/debug/libffi_convenience.a)
else()
    message(SEND_ERROR "only support Release/Debug mode")
endif()

# 操作系统判断，当前改项目只支持Linux系统
if(NOT(CMAKE_SYSTEM_NAME STREQUAL "Linux"))
    message(SEND_ERROR "only support Linux system")
endif()

# 链接google的测试库
target_link_libraries(${PROJECT_NAME}  gtest gtest_main)
target_link_libraries(${PROJECT_NAME}  gmock gmock)