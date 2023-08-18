#include "helloworld_server.h"
#include "butility.h"

grpc::Status HelloWorldService::SayHello(grpc::ServerContext* context, const helloworld::HelloRequest* request, helloworld::HelloResponse* response) {
    std::cout << "Received Request: " << request->message() << std::endl; 
    response->set_message("Hello " + request->message());
    return grpc::Status::OK; 
}

HelloWorldServer::HelloWorldServer() {
    set_address("0.0.0.0"); 
    set_port(50052); 
    set_server_credentials(grpc::InsecureServerCredentials());
}

HelloWorldServer::~HelloWorldServer() {
    server_->Shutdown(); 
}

void HelloWorldServer::set_address(const std::string& ip) {
    ip_address_ = ip;  
}

void HelloWorldServer::set_address(const std::string&& ip) {
    set_address(ip); 
}

void HelloWorldServer::set_port(int port) {
    port_ = port; 
}

void HelloWorldServer::set_server_credentials(std::shared_ptr<grpc::ServerCredentials> creds) {
    creds_ = creds; 
}

void HelloWorldServer::start_server() {
    std::string address = ip_address_ + ':' + std::to_string(port_);  
    grpc::ServerBuilder builder;
    builder.AddListeningPort(address, creds_);
    builder.RegisterService(&helloworld_service_); 
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on port: " << address << std::endl;
}