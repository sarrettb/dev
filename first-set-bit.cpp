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
       return log2(n & ~(n - 1)) + 1;
    }
};

int main() {
    vector<int> test_points = {12, 18};
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.getFirstSetBit(t) << " ";
    }
    return 0;
}