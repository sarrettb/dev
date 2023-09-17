#include <iostream> 
#include "redtangle_app.h"

int main(int argc, char** argv) {
    try {
            redtangle_app::run(); 
    }
    catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl; 
        return EXIT_FAILURE; 
    }
    return EXIT_SUCCESS;  
}