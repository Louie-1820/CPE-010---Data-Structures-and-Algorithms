#include <iostream>
#include<cstdlib>
#include<ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {

    // Create a array with unsorted list with 100 maximum size
    int unsortedArr[maxSize];
    // Use time (0) as seed for random values
    srand(time(0));
    // Populate the array with random values
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand()%100;
    }
    // Display the randomly generated array
    std::cout << "Unsorted Array: \n";
    displayArr(unsortedArr);

    /*std::cout << "\nBubble Sort: \n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);*/

    /*std::cout << "\n Selection Sort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);*/

    std::cout << "\n Insertion Sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}