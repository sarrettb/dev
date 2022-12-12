#ifndef SUPPORT_H
#define SUPPORT_H

/* Support Module contains helpful functions that can be used for
   debugging or commonly used in solving problems (such as printing a vector)
*/

#include <vector>

void print_vector(const std::vector<int>& v) {
    std::cout << "{"; 
    for (const auto& x : v) {
        std::cout << x << ", "; 
    }
    std::cout << "\n"; 
}

#endif 