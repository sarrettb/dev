#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int upper = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                upper += matrix[i][j];
            }
        }

        int lower = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                lower += matrix[i][j];
            }
        }
        return {upper, lower};
    }
};

int main() {
    vector<vector<int>> mat = {{6, 5, 4},
                               {1, 2, 5},
                               {7, 9, 7}};                     
    Solution sol;
    auto res = sol.sumTriangles(mat, mat.size());
    for (auto& ele : res) {
        cout << ele << " ";
    }
    return 0;
}