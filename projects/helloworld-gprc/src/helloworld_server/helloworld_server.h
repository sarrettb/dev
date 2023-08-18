#ifndef HELLOWORLD_SERVER_H
#define HELLOWORLD_SERVER_H

#include <string> 
#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

class HelloWorldService final : public helloworld::HelloWorld::Service {
    private:
    std::unordered_map<std::string, int> requests; 
    grpc::Status SayHello(grpc::ServerContext* context, const helloworld::HelloRequest* request, helloworld::HelloResponse* response) override; 
};

class HelloWorldServer {
  private:
    int port_; 
    std::string ip_address_; 
    HelloWorldService helloworld_service_; 
    std::shared_ptr<grpc::ServerCredentials> creds_; 
    std::unique_ptr<grpc::Server> server_;

  public:
    HelloWorldServer(); 
    ~HelloWorldServer(); 
    void set_address(const std::string& ip); 
    void set_address(const std::string&& ip); 
    void set_port(int p); 
    void set_server_credentials(std::shared_ptr<grpc::ServerCredentials> creds);
    void start_server(); 
};

#endif 