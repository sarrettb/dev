#include <iostream> 
#include <vector> 

/* Problem Statement 
Given a sorted array arr[] of size N without duplicates, and given a value x. 
Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
Find the index of K(0-based indexing).
*/

/* Algorithm: Use binary search. 
              If arr[mid] is less than x and arr[mid + 1] is greater than x then the floor has been found 
              Otherwise search the left or right half
              Time Complexity: O(log(N))
              Space Complexity: O(1) */
int floor(int arr[], int N, int x) {
    int low = 0;
    int high = N - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] <= x && (mid == N - 1 || x < arr[mid + 1]))
            return mid;
        
        else if (arr[mid] < x)
            low = mid + 1;
        
        else 
            high = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> test_data = {{1,2,8,10,11,12,19}, 
                                               {1,2,8,10,11,12,19}};
    std::vector<int> test_x = {20, 5}; 
    int i = 0;
    for (auto& t : test_data) {
         std::cout << floor(t.data(), t.size(), test_x[i++]) << " ";
    }
    return EXIT_SUCCESS;
}