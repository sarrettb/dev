#include <iostream>
#include <helloworld.grpc.pb.h>

int main() {
    helloworld::HelloRequest request; 
    helloworld::HelloResponse response;
    request.set_message("Hello Request!");
    response.set_message("Hello Response!"); 
    std::cout << "Hello World!" << std::endl;
    std::cout << "helloworld.pb.h included!" << std::endl;
    std::cout << "HelloRequest Message: " << request.message() << std::endl;
    std::cout << "HelloResponse Message: " << response.message() << std::endl;
    return 0;
}