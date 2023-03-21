#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{   
    public:
    //Function to reverse the columns of a matrix.
    void reverseCol(vector<vector<int> > &matrix)
    {
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};

int main() {
    vector<vector<int>> mat = {{ 1,  2,  3},
                               { 5,  6,  7},
                               {11, 10,  9},
                               {13, 14, 15}};                   
    Solution sol;
    sol.reverseCol(mat);
    for (auto& row : mat) {
        for (auto& ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}