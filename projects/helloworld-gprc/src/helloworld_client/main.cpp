#include "butility.h"
#include "helloworld_client.h"

int main(int argc, char* argv[]) {
    auto builder = HelloWorldClientBuilder(); 
    std::unordered_map<std::string, std::string> options = butility::parse_commandline(argc, argv);
    builder.set_address("10.0.2.15");
    builder.set_port(50052); 
    auto client = builder.build_client(); 
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Server Response: " << client->SayHello(name) << std::endl; 
    return 0;
}