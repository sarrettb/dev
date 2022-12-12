#include <iostream> 
#include <vector> 
#include <algorithm> 
#include "C:\repos\dev\dsa\debug\debug.h"
#include "C:\repos\dev\dsa\support\support.h"

/* Problem Statement 
Given an integer array representing the heights of N buildings, 
the task is to delete N-2 buildings such that the water that can be trapped between the remaining two building is maximum.
Note: The total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of the smaller building.
*/

/* Algorithm:  Use two pointer approach. 
               Start with maximum gap. 
               Search for maximum water by decreasing gap and possibly min(i, j) will create new maximum water amount.  
              Time Complexity: O(N)
              Space Complexity: O(1) */
int maxWater(int arr[], int N){
    int max_water = 0;
    int i = 0; 
    int j = N - 1;
    while (i < j) {
        max_water = std::max(max_water, (j - i - 1) * std::min(arr[i], arr[j])); 
        arr[i] <= arr[j] ? i++ : j--;
    }
    return max_water; 
}

int main() {
    std::vector<std::vector<int>> test_data = {{2,1,3,4,6,5},
                                               {2,1}}; 
    for (auto& t : test_data) {
         std::cout << maxWater(t.data(), t.size()) << " ";
    }
    
    return EXIT_SUCCESS;
}