# Minimum CMake required
cmake_minimum_required(VERSION 3.15)

# Project
project(REDTANGLE)

# Add SDL2
find_package(SDL2 REQUIRED)

# Build Source
add_subdirectory(src)