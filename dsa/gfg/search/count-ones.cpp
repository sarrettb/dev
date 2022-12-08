#include <iostream> 
#include <vector>

/* Problem Description
    Given a binary sorted non-increasing array of 1s and 0s. 
    You need to print the count of 1s in the binary array.
*/

/* Use binary search to find the index of the last occurance of 1 */
int countOnes(int arr[], int N) {
    int low = 0;
    int high = N - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == 1) {
            if (mid != N - 1 && arr[mid + 1] == 0)
                return mid + 1;
            low = mid + 1;
        }

        else
            high = mid - 1;
    }
    return arr[N - 1] == 1 ? N : 0;
}

int main() {
    std::vector<std::vector<int>> test_points = { {1,1,1,1,1,0,0,0},
                                                  {1,1,0,0,0,0,0,0} };
    for (auto& t : test_points) {
        std::cout << countOnes(t.data(), t.size()) << " ";
    }
}