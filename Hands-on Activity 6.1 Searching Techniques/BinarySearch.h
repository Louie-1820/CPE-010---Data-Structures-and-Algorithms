#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>

// ================= Problem 3 =================
template<typename T>
void binarySearchIterative(T arr[], int size, T searchVal) {
    int lowIndex = 0;
    int highIndex = size - 1;

    while (lowIndex <= highIndex) {
        int midIndex = lowIndex + (highIndex - lowIndex) / 2;

        if (arr[midIndex] == searchVal) {
            std::cout << "Key " << searchVal << " located at position " << midIndex << ".\n";
            return;
        }
        if (searchVal < arr[midIndex]) {
            highIndex = midIndex - 1;
        } else {
            lowIndex = midIndex + 1;
        }
    }
    std::cout << "Key " << searchVal << " could not be found.\n";
}

// ================= Problem 4 =================
template<typename T>
void binarySearchRecursive(T arr[], int low, int high, T targetVal) {
    if (low > high) {
        std::cout << "Item absent from array.\n";
        return;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == targetVal) {
        std::cout << "Item identified at index: " << mid << "\n";
        return;
    }

    if (targetVal < arr[mid]) {
        binarySearchRecursive(arr, low, mid - 1, targetVal);
    } else {
        binarySearchRecursive(arr, mid + 1, high, targetVal);
    }
}

#endif