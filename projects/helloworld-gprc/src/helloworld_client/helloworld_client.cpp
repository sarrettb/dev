#include "helloworld_client.h"


HelloWorldClient::HelloWorldClient(std::shared_ptr<grpc::Channel> channel) {
    stub_ = helloworld::HelloWorld::NewStub(channel); 
}

std::string HelloWorldClient::SayHello(const std::string& message) {
    helloworld::HelloRequest request; 
    request.set_message(message);
    helloworld::HelloResponse response;
    grpc::ClientContext context;
    grpc::Status status = stub_->SayHello(&context, request, &response);
    if (status.ok()) {
        return response.message();
    } 
    
    else {
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return "";
    }
}

HelloWorldClientBuilder::HelloWorldClientBuilder() {
    set_address("0.0.0.0"); 
    set_port(50052);
    set_channel_creds(grpc::InsecureChannelCredentials()); 
}

void HelloWorldClientBuilder::set_address(const std::string& ip) {
    ip_address_ = ip;
}

void HelloWorldClientBuilder::set_address(const std::string&& ip) {
    set_address(ip); 
}

void HelloWorldClientBuilder::set_port(int port) {
    port_ = port; 
}

void HelloWorldClientBuilder::set_channel_creds(std::shared_ptr<grpc::ChannelCredentials> creds) {
    creds_ = creds; 
}

std::shared_ptr<HelloWorldClient> HelloWorldClientBuilder::build_client() const {
    std::string address = ip_address_ + ':' + std::to_string(port_); 
    return std::make_shared<HelloWorldClient>(HelloWorldClient(grpc::CreateChannel(address, creds_))); 
}
