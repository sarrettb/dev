#include <iostream>
#include <vector>
using namespace std;

class Solution
{
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && key < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    vector<vector<int>> test_data = { { 4, 1, 3, 9, 7},
                                      {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
                                    };            
    for (auto& unsorted_data : test_data) 
    {
        Solution sol;
        sol.insertionSort(unsorted_data.data(), unsorted_data.size());
        for (auto ele : unsorted_data) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}