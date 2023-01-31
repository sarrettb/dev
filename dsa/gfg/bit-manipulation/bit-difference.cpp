#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int xor_result = a ^ b;
        int count = 0;
        while (xor_result) {
            if (xor_result & 1) {
                count++;
            }
            xor_result >>= 1;
        }
        return count;
    }
};

int main() {
    vector<pair<int, int>> test_points = {{4, 0}, {4, 2}};
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.countBitsFlip(t.first, t.second) << endl;
    }
    return 0;
}