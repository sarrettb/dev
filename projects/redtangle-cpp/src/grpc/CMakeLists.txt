set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)

# Proto File
get_filename_component(REDTANGLE_PROTO "${PROJECT_SOURCE_DIR}/proto/redtangle.proto" ABSOLUTE)
get_filename_component(REDTANGLE_PROTO_PATH "${REDTANGLE_PROTO}" PATH)

# Generate Sources
set(REDTANGLE_PROTO_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/generated/redtangle.pb.cc")
set(REDTANGLE_PROTO_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/generated/redtangle.pb.h")
set(REDTANGLE_GRPC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/generated/redtangle.grpc.pb.cc")
set(REDTANGLE_GRPC_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/generated/redtangle.grpc.pb.h")

add_custom_command(
      OUTPUT "${REDTANGLE_PROTO_SOURCE}" "${REDTANGLE_PROTO_HEADER}" "${REDTANGLE_GRPC_SOURCE}" "${REDTANGLE_GRPC_HEADER}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}"
        -I "${REDTANGLE_PROTO_PATH}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${REDTANGLE_PROTO}"
      DEPENDS "${REDTANGLE_PROTO}")

# Create Static Library
add_library(grpc_redtangle STATIC "${REDTANGLE_PROTO_SOURCE}" "${REDTANGLE_PROTO_HEADER}" "${REDTANGLE_GRPC_SOURCE}" "${REDTANGLE_GRPC_HEADER}")
target_link_libraries(grpc_redtangle PUBLIC 
                      gRPC::grpc++
                      gRPC::grpc
                      gRPC::gpr
                      protobuf::libprotoc 
                      protobuf::libprotobuf
                      protobuf::libprotobuf-lite
                      gRPC::grpc++_reflection
                    )