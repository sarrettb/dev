#include <iostream> 
#include "butility.h"

std::unordered_map<std::string, std::string> butility::parse_commandline(int argc, char* argv[]) { 
    std::unordered_map<std::string, std::string> options; 
    std::string key_delim = "--";
    std::string value_delim = "=";
    for (int i = 0; i < argc; i++) {
        std::string option = argv[i]; 
        int j = option.find(key_delim); 
        std::cout << "j=" << j << std::endl;
        int k = option.find(value_delim);
        std::cout << "k=" << k << std::endl;
        if (j != std::string::npos &&  k != std::string::npos) {
            std::string key = option.substr(j + key_delim.size(), k - (j + key_delim.size())); 
            std::string value = option.substr(k + value_delim.size()); 
            options[key] = value;
        }
    }
    return options; 
}
