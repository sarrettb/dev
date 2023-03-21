#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int>>& matrix, int n)
    { 
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        } 
    }
};

int main() {
    vector<vector<int>> mat = {{1, 1, 1, 1},
                               {2, 2, 2, 2},
                               {3, 3, 3, 3},
                               {4, 4, 4, 4}};                     
    Solution sol;
    sol.transpose(mat, mat.size());
    for (auto& row : mat) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}