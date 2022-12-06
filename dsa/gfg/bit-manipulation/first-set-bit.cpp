#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // n & ~(n-1) returns 2^k where k is the first set bit with 0-indexing
        // take log2() + 1 to find k with 1-indexing
        return log2(n & ~(n - 1)) + 1;
    }
};

int main() {
    vector<int> test_points = {18, 12};
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.getFirstSetBit(t) << " ";
    }
    return 0;
}