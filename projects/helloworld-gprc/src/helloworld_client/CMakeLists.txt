add_executable(helloworld_client main.cpp helloworld_client.cpp)
target_link_libraries(helloworld_client PUBLIC grpc_helloworld butility)
target_include_directories(helloworld_client 
                           PUBLIC "${PROJECT_SOURCE_DIR}/generated"
                           PUBLIC "${PROJECT_SOURCE_DIR}/../butility")