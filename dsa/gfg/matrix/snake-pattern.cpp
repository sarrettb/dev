#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        vector<int> result;
        int r = 0;
        while (r < matrix.size()) {
            for (int i = 0; i < matrix[r].size(); i++) {
                result.push_back(matrix[r][i]);
            }
            r++;
            if (r < matrix.size()) {
                for (int i = matrix[r].size() - 1; i >=0; i--) {
                    result.push_back(matrix[r][i]);
                }
                r++;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> mat = {{45, 48, 54},
                               {21, 89, 87},
                               {70, 78, 15}};                      
    Solution sol;
    auto res = sol.snakePattern(mat);
    for (auto& ele : res) {
        cout << ele << " ";
    }
    return 0;
}