#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int xor_result = m ^ n;
        int pos = 0;
        while (xor_result) {
            if (xor_result & 1 != 0) {
                return pos + 1;
            }
            xor_result >>= 1;
            pos++;
        }
        return -1;
    }
};

int main() {
    vector<pair<int, int>> test_points = {{4, 1}, {4, 2}};
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.posOfRightMostDiffBit(t.first, t.second) << endl;
    }
    return 0;
}