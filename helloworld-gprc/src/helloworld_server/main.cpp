#include "butility.h" 
#include "helloworld_server.h"

int main(int argc, char* argv[]) {
    HelloWorldServer server; 
    auto options = butility::parse_commandline(argc, argv); 
    if (options.find("ip") != options.end()) {
        server.set_address(options["ip"]); 
    }
    if (options.find("port") != options.end()) {
        server.set_port(stoi(options["port"])); 
    }
    server.start_server(); 
    std::cout << "Press any key to stop..." << std::endl;
    std::cin.get();
    return 0;
}