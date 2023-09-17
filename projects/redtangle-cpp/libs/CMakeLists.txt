# Add SDL2
find_package(SDL2 REQUIRED)

# Create IMGUI static library 
file(GLOB IMGUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h")
add_library(imgui STATIC ${IMGUI_SOURCES})