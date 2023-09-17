# IMGUI include directory 
set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/libs/imgui")

find_package(SDL2 REQUIRED)
# Set all redtangle source files to be all .cpp files in the src folder and its subdirectories 
file(GLOB_RECURSE REDTANGLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Set all redtangle source files to be all .h files in the src folder and its subdirectories  
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
set(REDTANGLE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
foreach(child ${children})
    if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        list(APPEND REDTANGLE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    endif()
endforeach()

message("SDL2: " ${SDL2_LIBRARIES})
# Build EXE, add include dirs, link libraries 
add_executable(redtangle ${IMGUI_SOURCES} 
                         ${REDTANGLE_SOURCES}
              ) 
include_directories(redtangle ${REDTANGLE_INCLUDE_DIRS} 
                              ${SDL2_INCLUDE_DIRS}
                              ${IMGUI_INCLUDE_DIRS} 
                    )
target_link_libraries(redtangle ${SDL2_LIBRARIES} imgui)