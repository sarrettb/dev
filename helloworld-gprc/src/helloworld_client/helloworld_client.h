#ifndef HELLOWORLD_CLIENT_H
#define HELLOWORLD_CLIENT_H

#include <string>
#include <memory> 
#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

class HelloWorldClient{
    private:
    std::unique_ptr<helloworld::HelloWorld::Stub> stub_;

    public:
    HelloWorldClient(std::shared_ptr<grpc::Channel> channel);
    std::string SayHello(const std::string& request); 
}; 

class HelloWorldClientBuilder {
    private:
    std::string ip_address_; 
    std::shared_ptr<grpc::ChannelCredentials> creds_;
    int port_; 

    public:
    HelloWorldClientBuilder(); 
    void set_address(const std::string& ip); 
    void set_address(const std::string&& ip);
    void set_port(int port); 
    void set_channel_creds(std::shared_ptr<grpc::ChannelCredentials> creds);
    std::shared_ptr<HelloWorldClient> build_client() const; 
};

#endif 