#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int maxim = 0;
        int count = 0;
        while (N) {
            if (N & 1)
                maxim = max(maxim, ++count);
            
            else 
                count = 0;
            N >>= 1;
        }
        return maxim;
    }
};

int main() {
    vector<int> test_points = {14, 222};
    for (auto& t : test_points) {
        cout << Solution().maxConsecutiveOnes(t) << " ";
    }
    return 0;
}