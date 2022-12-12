#ifndef DEBUG_H
#define DEBUG_H

#include <fstream> 
#include <vector> 
#include <string>

/* Debug file contains one line of text, space seperated */
std::vector<int> read_debug(const char* debug_path) {
   std::vector<int> debug_data;
   std::ifstream debug_file;
   std::string debug_string;
   debug_file.open(debug_path);
   if (debug_file.is_open()) {
        while (debug_file.peek() != EOF) {
            char c = debug_file.get();
            if (c == ' ') {
               debug_data.push_back(std::stoi(debug_string));
               debug_string.clear();
            }
            else
                debug_string.push_back(c);
        }
   }
   if (debug_string.length() > 0)
      debug_data.push_back(std::stoi(debug_string));
   return debug_data;
}
#endif 