#include <iostream> 
#include <vector> 

/* Problem Statement 
Given an array of distinct elements which was initially sorted. 
This array is rotated at some unknown point. 
The task is to find the minimum element in the given sorted and rotated array.
*/

/* Algorithm: Use binary search. 
              Search until arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]
              This is the first element in the array before being rotated. 
              Time Complexity: O(log(N))
              Space Complexity: O(1) */
int minNumber(int arr[], int N) {
    int low = 0;
    int high = N - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid] < arr[mid - 1]) && (mid == N - 1 || arr[mid] < arr[mid + 1]))
            return arr[mid]; 
        else if (arr[mid] > arr[0])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[0];
}

int main() {
    std::vector<std::vector<int>> test_points = { {2,3,4,5,6,7,8,9,10,1}, 
                                                  {3,4,5,1,2},
                                                  {6, 11, 24, 37, 42 } };
    for (auto& t : test_points) {
         std::cout << minNumber(t.data(), t.size()) << " ";
    }
    return EXIT_SUCCESS;
}