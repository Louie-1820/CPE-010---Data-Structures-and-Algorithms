#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>

class UniqueArray {
private:
    std::vector<int> array;

public:
    // Constructor
    UniqueArray(const std::vector<int>& arr) : array(arr) {}

    // Check if all elements in the array are unique
    bool Unique_Array() const;

    // Checking the Array and displaying its contents
    static void checkArray(int size);
};

bool UniqueArray::Unique_Array() const {
    int n = array.size();
    // Check for duplicate elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Return False if a duplicate element is found in the array
            if (array[i] == array[j]) {
                return false;
            }
        }

        // Creates a copy of the array and sorts the array
        std::vector<int> sorted_arr = array;
        std::sort(sorted_arr.begin(), sorted_arr.end());
        // Checks adjacent elements to identify whether they are a duplicate
        for (size_t i = 0; i < sorted_arr.size() - 1; i++) {
            // Return false if a duplicate element is found
            if (sorted_arr[i] == sorted_arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // Return true if the array is empty or no duplicates were detected
    return true;
}


void UniqueArray::checkArray(int size) {
    // Add elements in the the array
    std::vector<int> Array(size);
    for (int i = 0; i < size; i++) {
        Array[i] = i;
    }

    UniqueArray checker(Array);

    // Measures the starting time
    auto begin = std::chrono::steady_clock::now();
    // Calls the Unique_Array function
    bool result = checker.Unique_Array();
    // Ends the timer
    auto end = std::chrono::steady_clock::now();

    // Calculates the time to search using microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    // Display the data that were recorded in the begin - end timer
    std::cout << "Array Size: " << size 
              << " | Time: " << duration << " microseconds"
              << " \nUnique: " << (result ? "true" : "false") << std::endl;
}

int main () {
    // Testing Values
    UniqueArray::checkArray(1000);
    UniqueArray::checkArray(10000);
    UniqueArray::checkArray(100000);

    return 0;
}
