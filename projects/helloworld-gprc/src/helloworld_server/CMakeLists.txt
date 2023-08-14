add_executable(helloworld_server main.cpp helloworld_server.cpp)
target_link_libraries(helloworld_server PUBLIC grpc_helloworld)
target_include_directories(helloworld_server PUBLIC "${PROJECT_SOURCE_DIR}/generated")