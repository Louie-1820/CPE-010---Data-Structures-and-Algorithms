#include <iostream>
#include "SequentialSearch.h"
#include "BinarySearch.h"

int main() {
    int seqData[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int seqSize = sizeof(seqData) / sizeof(seqData[0]);

    std::cout << "========== Problem 1 ==========\n";
    countLinearArray(seqData, seqSize, 18);

    std::cout << "\n========== Problem 2 ==========\n";
    countOccurrencesArray(seqData, seqSize, 18);

    int binData[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int binSize = sizeof(binData) / sizeof(binData[0]);

    std::cout << "\n========== Problem 3 ==========\n";
    binarySearchIterative(binData, binSize, 8);

    std::cout << "\n========== Problem 4 ==========\n";
    binarySearchRecursive(binData, 0, binSize - 1, 8);

    return 0;
} 