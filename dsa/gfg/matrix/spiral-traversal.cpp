#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> result;
        for (int j = 0; j < r / 2; j++) {
            for (int i = j; i < c - j; i++) {
                result.push_back(matrix[j][i]);
            }

            for (int i = j + 1; i < r - j; i++) {
                result.push_back(matrix[i][c - 1 - j]);
            }

            for (int i = c - 2 - j; i >= j; i--) {
                result.push_back(matrix[r - 1 - j][i]);
            }

            for (int i = r - 2 - j; i > j; i--) {
                result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};


int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15,16}};              
    Solution sol;
    auto res = sol.spirallyTraverse(mat, mat.size(), mat[0].size());
    for (auto ele : res) {
        cout << ele << " ";
    }
    return 0;
}