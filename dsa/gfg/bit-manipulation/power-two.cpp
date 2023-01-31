#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        return (n & n - 1) == 0 && n != 0;
    }
};

int main() {
    vector<int> test_points = {128, 9, 0};
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.isPowerofTwo(t) << " ";
    }
    return 0;
}