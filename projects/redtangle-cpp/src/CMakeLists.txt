add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld PUBLIC
                      grpc_helloworld
                    )
target_include_directories(helloworld PUBLIC "${PROJECT_SOURCE_DIR}/generated")