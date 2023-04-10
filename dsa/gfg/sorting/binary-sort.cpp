#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public: 
    // Function to sort binary array
    void binarySort(vector<int>& arr)
    {
       int zero_window = -1;
       for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                swap(arr[i], arr[++zero_window]);
            }
       }
    }
};


int main() {
    vector<vector<int>> test_data = { { 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
                                      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } 
                                    };            
    for (auto& data : test_data) 
    {
        Solution sol;
        sol.binarySort(data);
        for (auto ele : data) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}