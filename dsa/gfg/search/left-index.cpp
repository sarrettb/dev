#include <iostream> 
#include <vector> 

/* Problem Statement 
Given a sorted array of positive integers (elements may be repeated) and a number x. 
The task is to find the leftmost index of x in the given array.
*/

/* Algorithm: Find left most index that has value x. 
              Use binary search until we we find a value where the left is not equal to x. 
              Time Complexity: O(log(N))
              Space Complexity: O(1) */
int leftIndex(int N, int arr[], int X){
    int low = 0;
    int high = N - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == X) {
            if(mid != 0 && arr[mid-1] == X)
                high = mid - 1;
            else 
                return mid;
        }
        else if (arr[mid] < X)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> test_data = {{1,1,2,2,3,4,5,5,6,7}, 
                                                 {10,20,20,20,20,20,20}};
    std::vector<int> test_x = {1, 20}; 
    int i = 0;
    for (auto& t : test_data) {
         std::cout << leftIndex(t.size(), t.data(), test_x[i++]) << " ";
    }
    return EXIT_SUCCESS;
}