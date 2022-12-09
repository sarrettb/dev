#include <iostream> 
#include <vector> 

/* Problem Statement 
Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an element that appears more than N/2 times in the array.
*/

/* Algorithm: Find maximum occuring element
              Then check if the number of occurances is > N/2
              Time Complexity: O(N)
              Space Complexity: O(1) */
int majorityElement(int a[], int size) {
    int i = 0; // pointer to maximum element
    int count = 1;
    for (int j = 1; j < size; j++) {
        a[i] == a[j] ? count++ : count--;
        if (count == 0) {
            count = 1;
            i = j;
        }
    }
    count = 0;
    for (int j = 0; j < size; j++) {
        if (a[i] == a[j])
            count++;
    }
    return count > size / 2 ? a[i] : -1;
}

int main() {
    std::vector<std::vector<int>> test_points = {{1,2,3}, 
                                                 {3,1,3,3,2}};
    for (auto& t : test_points) {
         std::cout << majorityElement(t.data(), t.size()) << " ";
    }
    return EXIT_SUCCESS;
}