# Add SDL and SDL_image directories since they use CMake as the build system 
add_subdirectory(SDL)
add_subdirectory(SDL_image)

# Set library include directories in internal cache so they are accessible by other CMakeLists
set(SDL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SDL/include" CACHE INTERNAL "")
set(SDL_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SDL_image/include" CACHE INTERNAL "")
set(IMGUI_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui" "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends" CACHE INTERNAL "")

# Imgui does not use CMake so build source files into a static library 
file(GLOB IMGUI_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h")
file(GLOB IMGUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp"
                        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.cpp"
                        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdlrenderer2.cpp"
    )
add_library(imgui STATIC ${IMGUI_HEADERS} ${IMGUI_SOURCES})
include_directories(imgui ${IMGUI_INCLUDE_DIR} ${SDL_INCLUDE_DIR})

if(MSVC)
  add_definitions(-D_WIN32_WINNT=0x600)
endif()
find_package(Threads REQUIRED)

add_subdirectory(grpc)
message(STATUS "Using gRPC via add_subdirectory.")

# After using add_subdirectory, we can now use the grpc targets directly from
# this build.
set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_REFLECTION grpc++_reflection)
if(CMAKE_CROSSCOMPILING)
    find_program(_PROTOBUF_PROTOC protoc)
else()
    set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()
set(_GRPC_GRPCPP grpc++)
if(CMAKE_CROSSCOMPILING)
    find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
else()
    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
endif()