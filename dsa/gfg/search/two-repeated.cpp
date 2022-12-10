#include <iostream> 
#include <vector> 

/* Problem Statement 
You are given an array of N+2 integer elements. All elements of the array are in the range 1 to N. 
Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
*/

/* Algorithm: Traverse the array. 
              Tag the position of each element as visited by inverting the value
              If the position has already been tagged, then it is repeated. 
              Time Complexity: O(N)
              Space Complexity: O(1) */
std::vector<int> twoRepeated(int arr[], int N) {
    std::vector<int> result;
    for (int i = 0; i < N + 2; i++) {
        if (arr[abs(arr[i])] < 0)
            result.push_back(abs(arr[i]));
        else 
            arr[abs(arr[i])] *= -1;
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> test_points = { {1, 2, 6, 3, 4, 5, 6, 4}, 
                                                  {1,2,2,1},
                                                  {1,2,1,3,4,3} };
    for (auto& t : test_points) {
         auto res = twoRepeated(t.data(), t.size() - 2);
         std::cout << "[" << res[0] << "," << res[1] << "]\n";
    }
    return EXIT_SUCCESS;
}