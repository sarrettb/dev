# SDL and SDL_image use CMake, so add the subdirectories to build 
add_subdirectory(SDL)
add_subdirectory(SDL_image)

set(SDL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SDL/include" CACHE INTERNAL "")
set(SDL_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SDL_image/include" CACHE INTERNAL "")
set(IMGUI_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui" "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends" CACHE INTERNAL "")

# Imgui does not use CMake, so specify a static library build 
file(GLOB IMGUI_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h")
file(GLOB IMGUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp"
                        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.cpp"
                        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdlrenderer2.cpp"
    )
add_library(imgui STATIC ${IMGUI_HEADERS} ${IMGUI_SOURCES})
include_directories(imgui ${IMGUI_INCLUDE_DIR} ${SDL_INCLUDE_DIR})