#include "butility.h" 
#include "helloworld_server.h"

int main(int argc, char* argv[]) {
    HelloWorldServer server; 
    auto options = butility::parse_commandline(argc, argv); 
    server.set_address("10.0.2.15");
    server.set_port(50052); 
    server.start_server(); 
    std::cout << "Press any key to stop..." << std::endl;
    std::cin.get();
    return 0;
}