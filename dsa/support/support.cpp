#include "support.h"

void print_vector(const std::vector<int>& v) {
    std::cout << "{"; 
    for (auto& x : v) {
        std::cout << x << ", "; 
    }
    std::cout << "\b\b}\n"; 
}