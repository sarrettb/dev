#include <string> 
#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status; 

using helloworld::HelloWorld;
using helloworld::HelloRequest;
using helloworld::HelloResponse;

class HelloWorldService final : public helloworld::HelloWorld::Service {
  private:
    Status SayHello(ServerContext* context, const helloworld::HelloRequest* request, helloworld::HelloResponse* response) override; 

  public:
    void start_server(const std::string& ip, int port = 50052); 
    void start_server(const std::string&& ip, int port = 50052); 
};