# Minimum CMake required
cmake_minimum_required(VERSION 3.15)

# Project
project(HELLO_WORLD)

# Protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${protobuf_VERSION}")

# gRPC
find_package(gRPC CONFIG REQUIRED)
set(_GRPC_GRPCPP gRPC::grpc++)
message(STATUS "Using gRPC ${gRPC_VERSION}")

add_subdirectory(src)
add_subdirectory(generated)