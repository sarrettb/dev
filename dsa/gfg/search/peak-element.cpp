#include <iostream> 
#include <vector> 

/* Problem Statement 
An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, Return the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 
*/

/* Algorithm: Use binary search. 
              if mid is a peak return it
              else search left or right half whichever element is greater (possibly both are greater) but we only need 1 answer 
              Time Complexity: O(log(N))
              Space Complexity: O(1) */
int peakElement(int arr[], int N){
    int low = 0;
    int high = N - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid- 1] <= arr[mid]) &&
            (mid == N - 1 || arr[mid+1] <= arr[mid]))
                return mid;
        else if (mid != 0 && (arr[mid - 1] > arr[mid]))
            high = mid -1;
        else
            low = mid + 1;
    }
}

int main() {
    std::vector<std::vector<int>> test_data = {{1,2,3}, 
                                               {3,4}};
    for (auto& t : test_data) {
         std::cout << peakElement(t.data(), t.size()) << " ";
    }
    return EXIT_SUCCESS;
}