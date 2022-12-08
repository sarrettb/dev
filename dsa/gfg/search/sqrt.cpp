#include <iostream> 
#include <vector>

/* Problem Description
    Given an integer x, 
    find the square root of x. If x is not a perfect square, then return floor(√x).
*/

/* f(x) = sqrt(x) is a monotonically increasing function
   Therefore, we can use binary search to find it's sqrt()
*/
long long int sqrt(long long int N) {
    if (N == 1)
        return 0; // base caes
    long long int low = 0;
    long long int high = N;
    long long int mid;
    long long int sqr;
    long long int res;
    while (low <= high) {
        mid = low + (high - low) / 2;
        sqr = mid * mid;
        if (sqr == N)
            return mid; // perfect square
        
        else if (sqr > N) 
            high = mid - 1;

        else {
            low = mid + 1;
            res = mid; // store floor
        }
    }
    return res;
}

int main() {
    std::vector<int> test_points = {1, 5, 25, 50};
    for (auto& t : test_points) {
        std::cout << sqrt(t) << " ";
    }
    return EXIT_SUCCESS;
}