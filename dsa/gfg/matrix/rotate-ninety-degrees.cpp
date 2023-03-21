#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse Columns
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                swap(matrix[start][i], matrix[end][i]);
                start++;
                end--;
            }
        }
        
    } 
};


int main() {
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};                  
    Solution sol;
    sol.rotateby90(mat, mat.size());
    for (auto& row : mat) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}