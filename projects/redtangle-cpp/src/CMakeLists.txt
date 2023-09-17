# SDL2 include directory 
set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/libs/SDL/include")

# IMGUI include directory 
set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/libs/imgui")

# Redtangle include directories are all .h files in the src folder and its subdirectories  
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
set(REDTANGLE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
foreach(child ${children})
    if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        list(APPEND REDTANGLE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    endif()
endforeach()

# Redtangle source files are all .cpp files in the src folder and its subdirectories 
file(GLOB_RECURSE REDTANGLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

message("${SDL2_LIBRARIES}")
# Build EXE, add include dirs, link libraries 
add_executable(redtangle ${IMGUI_SOURCES} 
                         ${REDTANGLE_SOURCES}
              ) 
include_directories(redtangle ${REDTANGLE_INCLUDE_DIRS} 
                              ${SDL2_INCLUDE_DIR}
                              ${IMGUI_INCLUDE_DIR} 
                    )
target_link_libraries(redtangle SDL2main 
                                SDL2
                                imgui
                    )
