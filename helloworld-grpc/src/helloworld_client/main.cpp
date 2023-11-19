#include "butility.h"
#include "helloworld_client.h"

int main(int argc, char* argv[]) {
    auto builder = HelloWorldClientBuilder(); 
    std::unordered_map<std::string, std::string> options = butility::parse_commandline(argc, argv);
    if (options.find("ip") != options.end()) {
        builder.set_address(options["ip"]); 
    }
    if (options.find("port") != options.end()) {
        builder.set_port(stoi(options["port"])); 
    }
    auto client = builder.build_client(); 
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Server Response: " << client->SayHello(name) << std::endl; 
    return 0;
}