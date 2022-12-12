#include <iostream> 
#include <vector> 
#include <algorithm>

/* Problem Statement 
You are given heights of consecutive buildings. 
You can move from the roof of a building to the roof of next adjacent building. 
You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.
*/

/* Algorithm: Traverse the array. 
              Keep count of the max steps, if a step does not increase altitude reset curr_steps 
              Time Complexity: O(N)
              Space Complexity: O(1) */
int maxStep(int arr[], int N) {
    int max_steps = 0;
    int curr_steps = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i - 1] < arr[i])
            curr_steps++;
        else {
            max_steps = std::max(max_steps, curr_steps);
            curr_steps = 0;
        }
    }
    return std::max(max_steps, curr_steps);
}

int main() {
    std::vector<std::vector<int>> test_points = { {1,2,2,3,2}, 
                                                  {1,2,3,4} };
    for (auto& t : test_points) {
         std::cout << maxStep(t.data(), t.size()) << " ";
    }
    return EXIT_SUCCESS;
}