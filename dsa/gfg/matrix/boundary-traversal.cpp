#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> result;
        // First Row
        for (int i = 0; i < m; i++)
            result.push_back(matrix[0][i]);
        
        // Last Column
        for (int i = 1; i < n; i++)
            result.push_back(matrix[i][m-1]);
        
        // Last Row
        if (n > 1)
            for (int i = m - 2; i >= 0; i--)
                result.push_back(matrix[n-1][i]);
        
        // First Column
        if (m > 1)
            for (int i = n - 2; i > 0; i--)
                result.push_back(matrix[i][0]);
        
        return result;
    }
};

int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15,16}};                     
    Solution sol;
    auto res = sol.boundaryTraversal(mat, mat.size(), mat[0].size());
    for (auto& ele : res) {
        cout << ele << " ";
    }
    return 0;
}