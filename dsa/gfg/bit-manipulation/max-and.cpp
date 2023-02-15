#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND(int arr[], int N)
    {
        int* max_idx = max_element(arr, arr + N);
        int max_and = INT_MIN;
        for (int i = 0; i < N; i++) {
            if (max_idx - arr != i)
                max_and = max(max_and, *max_idx & arr[i]);
        }
        return max_and;
    }
};
int main() {
    vector<vector<int>> test_points = {{4, 8, 12, 16},
                                       {4, 8, 16, 2}
                                      };
    for (auto& t : test_points) {
        Solution sol;
        cout << sol.maxAND(t.data(), t.size()) << " ";
    }
    return 0;
}