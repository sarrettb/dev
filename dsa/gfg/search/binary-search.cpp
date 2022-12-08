#include <iostream>
#include <vector>

int search(int arr[], int N, int X) {
    int low = 0;
    int high = N - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == X)
            return mid;
        
        if (arr[mid] < X)
            low = mid + 1;
        
        else 
            high = mid - 1;
    }
    return -1;
}

int main() {
    // more test cases are provided in gfg course
    std::vector<std::vector<int>> test_points = { {1, 2, 3, 4, 5},
                                                  {5, 6, 7, 8, 9} } ;
    for (auto& t : test_points) {
        std::cout << "Index=" << search(t.data(), t.size(), 4) << std::endl;
    }
    return EXIT_SUCCESS;
}