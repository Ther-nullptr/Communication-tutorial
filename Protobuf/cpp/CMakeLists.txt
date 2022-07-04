cmake_minimum_required(VERSION 3.5)

project(protobuf_test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

add_executable(protobuf_test test.cpp test.pb.cc)
target_link_libraries(protobuf_test ${_PROTOBUF_LIBPROTOBUF})



