#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // Hash Sets to store rows/columns that need to be set to 1
        unordered_set<int> rows;
        unordered_set<int> cols;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> mat = {{ 1, 0, 0},
                               { 1, 0, 0},
                               { 1, 0, 0},
                               { 0, 0, 0}};                  
    Solution sol;
    sol.booleanMatrix(mat);
    for (auto& row : mat) {
        for (auto& ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}