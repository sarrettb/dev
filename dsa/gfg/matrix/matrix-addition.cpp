#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:
    //Function to add two matrices.
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        if (A.size() != B.size() || A[0].size() != B[0].size())
            return vector<vector<int>>();
        
        vector<vector<int>> result(A.size(), vector<int>(A[0].size()));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                result[i][j] = A[i][j] + B[i][j];
            }
        }
        return result;
    }   
};

int main() {
    vector<vector<int>> a = {{1, 2, 3},
                             {4, 5, 6}};
    vector<vector<int>> b = {{1, 3, 3},
                             {2, 3, 3}};                           
    Solution sol;
    auto res = sol.sumMatrix(a, b);
    for (auto& row : res) {
        for (auto& col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}