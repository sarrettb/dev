set(REDTANGLE_GRPC_INCLUDES "${PROJECT_SOURCE_DIR}/include/grpc")
set(GENERATED_DIR ${REDTANGLE_GRPC_INCLUDES}/generated)

# Proto File
get_filename_component(REDTANGLE_PROTO "${REDTANGLE_GRPC_INCLUDES}/redtangle.proto" ABSOLUTE)
get_filename_component(REDTANGLE_PROTO_PATH "${REDTANGLE_PROTO}" PATH)

# Generate Sources
file(MAKE_DIRECTORY ${GENERATED_DIR})
set(REDTANGLE_PROTO_SOURCE "${GENERATED_DIR}/redtangle.pb.cc")
set(REDTANGLE_PROTO_HEADER "${GENERATED_DIR}/redtangle.pb.h")
set(REDTANGLE_GRPC_HEADER "${GENERATED_DIR}/redtangle.grpc.pb.cc")
set(REDTANGLE_GRPC_SOURCE "${GENERATED_DIR}/redtangle.grpc.pb.h")

add_custom_command(
      OUTPUT "${REDTANGLE_PROTO_SOURCE}" "${REDTANGLE_PROTO_HEADER}" "${REDTANGLE_GRPC_SOURCE}" "${REDTANGLE_GRPC_HEADER}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${GENERATED_DIR}"
        --cpp_out "${GENERATED_DIR}"
        -I "${REDTANGLE_PROTO_PATH}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${REDTANGLE_PROTO}"
      DEPENDS "${REDTANGLE_PROTO}")

# Create Static Library for Generated Code 
add_library(grpc_redtangle STATIC
            ${REDTANGLE_GRPC_SOURCE}
            ${REDTANGLE_GRPC_HEADER}
            ${REDTANGLE_PROTO_SOURCE}
            ${REDTANGLE_PROTO_HEADER}
          )
target_link_libraries(grpc_redtangle
                      ${_REFLECTION}
                      ${_GRPC_GRPCPP}
                      ${_PROTOBUF_LIBPROTOBUF}
                      )

# Create Library for gRPC Client
add_library(redtangle-client STATIC redtangle_client.cpp)
target_link_libraries(redtangle-client grpc_redtangle)

add_executable(redtangle_server "${PROJECT_SOURCE_DIR}/src/apps/redtangle_server_app.cpp"
                                "redtangle_server.cpp"
              )
target_link_libraries(redtangle_server
                      redtangle-lib
                      butility
                      grpc_redtangle
                      absl::flags
                      absl::flags_parse
                      ${_REFLECTION}
                      ${_GRPC_GRPCPP}
                      ${_PROTOBUF_LIBPROTOBUF}
                      ${REDTANGLE_LIB})
include_directories(redtangle_server ${GENERATED_DIR} 
                                     ${REDTANGLE_INCLUDES}
                                     ${REDTANGLE_GRPC_INCLUDES}
                                     ${PROJECT_SOURCE_DIR}/../butility
                    )