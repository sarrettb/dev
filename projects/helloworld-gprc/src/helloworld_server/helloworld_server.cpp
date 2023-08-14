#include "helloworld_server.h"

Status HelloWorldService::SayHello(ServerContext* context, const helloworld::HelloRequest* request, helloworld::HelloResponse* response) {
    response->set_message("Hello " + request->message());
    return Status::OK; 
}

void HelloWorldService::start_server(const std::string& ip, int port) {
    std::string address = ip + ":" + std::to_string(port); 

    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(this);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port: " << address << std::endl;

    server->Wait();
}

void HelloWorldService::start_server(const std::string&& ip, int port) {
    start_server(ip, port); 
}