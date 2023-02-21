#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        if (B.size() != A[0].size())
            return {};
        
        vector<vector<int>> result;
        for (int i = 0; i < A.size(); i++) {
            result.push_back({});
            for (int j = 0; j < B[0].size(); j++) {
                int val = 0;
                for (int k = 0; k < A[0].size(); k++) {
                    val += A[i][k] * B[k][j];
                }
                result[i].push_back(val);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> a = {{4, 8},
                             {0, 2},
                             {1, 6}};
    vector<vector<int>> b = {{5, 2},
                             {9, 4}};                           
    Solution sol;
    auto res = sol.multiplyMatrix(a, b);
    for (auto& row : res) {
        for (auto& col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}