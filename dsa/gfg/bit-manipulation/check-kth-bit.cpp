#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        return n & (1 << k);
    }
};

int main() {
    vector<pair<int, int>> test_points = {{4, 0}, {4, 2}};
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.checkKthBit(t.first, t.second) << endl;
    }
    return 0;
}