#include <iostream>
#include <helloworld.grpc.pb.h>

int main() {
    helloworld::HelloRequest request; 
    request.set_message("Hello Request!");
    std::cout << "Hello World!" << std::endl;
    std::cout << "helloworld.pb.h included!" << std::endl;
    std::cout << "HelloRequest Message: " << request.message() << std::endl;
    return 0;
}