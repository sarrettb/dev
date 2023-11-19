# Minimum CMake required
cmake_minimum_required(VERSION 3.15)

# Project
project(HELLO_WORLD)

# Required if using static libs
#set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>)

# Protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${protobuf_VERSION}")

# gRPC
find_package(gRPC CONFIG REQUIRED)
set(_GRPC_GRPCPP gRPC::grpc++)
message(STATUS "Using gRPC ${gRPC_VERSION}")

message("bin: ${CMAKE_BINARY_DIR}")
add_subdirectory("${PROJECT_SOURCE_DIR}/../butility" ${CMAKE_BINARY_DIR}/butility)
add_subdirectory(src)
add_subdirectory(generated)