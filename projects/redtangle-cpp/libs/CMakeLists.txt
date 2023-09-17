# Add SDL2
add_subdirectory(SDL)
set(SDL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/SDL3")

# Create IMGUI static library 
file(GLOB IMGUI_INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h")
list(APPEND IMGUI_INCLUDE_DIR "imgui_impl_sdl2.h" "imgui_impl_sdlrenderer2.h")
file(GLOB IMGUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp"
                        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.cpp"
                        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdlrenderer2.cpp"
    )
add_library(imgui STATIC ${IMGUI_SOURCES})
include_directories(imgui ${IMGUI_INCLUDE_DIR} ${SDL_INCLUDE_DIR})