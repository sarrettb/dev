#ifndef BUTILITY_H
#define BUTILITY_H

#include <string> 
#include <unordered_map> 

namespace butility {
    std::unordered_map<std::string, std::string> parse_commandline(int argc, char* argv[]); 
}

#endif 