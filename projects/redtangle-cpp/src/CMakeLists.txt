# Build a library for just the redtangle game specific code 
# This library can be used by the gRPC Server or a local client (2-player/1 PC mode)
set (REDTANGLE_INCLUDES ${PROJECT_SOURCE_DIR}/include CACHE INTERNAL "")
file(GLOB_RECURSE REDTANGLE_LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/game/*.cpp")
add_library(redtangle-lib ${REDTANGLE_LIB_SOURCES})
include_directories(redtangle-lib ${REDTANGLE_LIB_INCLUDE})
target_link_libraries(redtangle-lib grpc_redtangle)

# Add gRPC subdirectory to created the auto-generated files and gRPC libraries  
add_subdirectory(grpc)

# Build Application 
file(GLOB_RECURSE REDTANGLE_APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.cpp")
list(APPEND REDTANGLE_APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/apps/redtangle_app.cpp")
list(APPEND REDTANGLE_APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/apps/redtangle_builder.cpp")

add_executable(redtangle ${REDTANGLE_APP_SOURCES} ) 
include_directories(redtangle ${REDTANGLE_INCLUDES} 
                              ${SDL_INCLUDE_DIR}
                              ${SDL_IMAGE_INCLUDE_DIR}
                              ${IMGUI_INCLUDE_DIR} 
                              ${GRPC_INCLUDE_DIR}
                   )
target_link_libraries(redtangle SDL2main 
                                SDL2-static
                                SDL2_image
                                imgui
                                redtangle-lib
                                redtangle-client
                     )

add_executable(debug main.cpp ) 
include_directories(debug ${REDTANGLE_INCLUDES} 
                            ${SDL_INCLUDE_DIR}
                            ${SDL_IMAGE_INCLUDE_DIR}
                            ${IMGUI_INCLUDE_DIR} 
                            ${GRPC_INCLUDE_DIR}
                )
target_link_libraries(debug SDL2main 
                                SDL2-static
                                SDL2_image
                                imgui
                                redtangle-lib
                                redtangle-client
                    )