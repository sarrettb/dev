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

# Build EXE, add include dirs, link libraries 
add_executable(redtangle ${REDTANGLE_SOURCES} ) 
include_directories(redtangle ${REDTANGLE_INCLUDE_DIRS} 
                              ${SDL_INCLUDE_DIR}
                              ${SDL_IMAGE_INCLUDE_DIR}
                              ${IMGUI_INCLUDE_DIR} 
                   )
target_link_libraries(redtangle SDL2main 
                                SDL2-static
                                SDL2_image
                                imgui
                                Kernel32
                     )