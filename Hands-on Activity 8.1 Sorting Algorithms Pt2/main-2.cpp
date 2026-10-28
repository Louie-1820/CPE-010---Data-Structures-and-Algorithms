#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Sorting.h"

int main() {
    srand(time(0));
    std::vector<int> original(100);
    for (int i = 0; i < 100; i++) {
        original[i] = rand() % 1000;
    }

    std::cout << "=========== Sorting Algorithms: Shell, Merge and Quick Sort  ============\n";
    std::cout << std::endl;
    printArray(original);

    // Shell Sort 
    std::vector<int> arrShell = original;
    shellSort(arrShell);
    std::cout << "\n=========== Shell Sort  ===========\n";
    std::cout << std::endl;
    printArray(arrShell);

    // Merge Sort 
    std::vector<int> arrMerge = original;
    mergeSort(arrMerge, 0, arrMerge.size() - 1);
    std::cout << "\n=========== Merge Sort  ===========\n";
    std::cout << std::endl;
    printArray(arrMerge);

    // Quick Sort 
    std::vector<int> arrQuick = original;
    quickSort(arrQuick, 0, arrQuick.size() - 1);
    std::cout << "\n=========== Quick Sort  ===========\n";
    std::cout << std::endl;
    printArray(arrQuick);

    std::cout << "=========== Supplementary Activity: Problem 1 ===========\n";
    
    std::vector<int> demoArray = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    
    std::cout << "Original Array:\n";
    printArray(demoArray);
    supplementaryActivity(demoArray, 0, demoArray.size() - 1);
    std::cout << "\nSorted Array:\n";
    printArray(demoArray);

    return 0;
}