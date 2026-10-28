#include <cstddef>
#include <iostream>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template<typename T>
void bubbleSort(T arr[], size_t arrSize) {
    // Step 1: for i = 0 to N - 1 repeat inner loop
    for (int i = 0; i < arrSize; i++) {
        // Step 2: Inner loop that forK = i + 1 to N - 1 repeat
        for (int j = i + 1; j < arrSize; j++) {
            // Step 3: Swap if the arr[j] > arr [i]
            if (arr[i] < arr[j]) { 
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template<typename T>
// Array, current Position, Size of Array
int routineSmallest(T arr[], int K, const int arrSize) {
    int position;
    T smallestElem = arr[K];

    for (int j = K+1; j<arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass;
    for (int i=0; i < arrSize; i++) {
        POS = routineSmallest(arr, i, arrSize);
        // Swapping: 
        temp = arr[i];

        arr[i] = arr[POS];
        arr[POS] = temp;
        // For verification and counting of number of passes that was done
        pass++;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize) {
    int K = 0, J, temp;

    while (K < arrSize) {
        temp = arr[K];
        J=K-1;

        while (temp <= arr[J]) {
            arr[J+1] = arr[J];
            J--;
        }

        arr[J+1] = temp;
        K++;
    }
}

#endif
