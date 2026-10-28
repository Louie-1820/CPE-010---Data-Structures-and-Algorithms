#ifndef SEQUENTIAL_SEARCH_H
#define SEQUENTIAL_SEARCH_H

#include <iostream>

template <typename T>
struct Node {
    T val;
    Node* next;
    Node(T v) : val(v), next(nullptr) {}
};

// ================= Problem 1 =================
template<typename T>
void countLinearArray(T list[], int length, T targetKey) {
    int totalChecks = 0;
    for (int i = 0; i < length; ++i) {
        totalChecks++;
        std::cout << "Check #" << totalChecks << " performed.\n";
        if (list[i] == targetKey) {
            std::cout << "Found target at index " << i << ".\n";
            return;
        }
    }
    std::cout << "Key not found.\n";
}

template<typename T>
void countLinearLL(Node<T>* head, T targetKey) {
    int totalChecks = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        totalChecks++;
        std::cout << "Check #" << totalChecks << " performed.\n";
        if (temp->val == targetKey) {
            std::cout << "Found target in list.\n";
            return;
        }
        temp = temp->next;
    }
    std::cout << "Key not found in list.\n";
}

// ================= Problem 2 =================
template<typename T>
void countOccurrencesArray(T list[], int n, T element) {
    int matchCount = 0;
    for (int index = 0; index < n; ++index) {
        if (list[index] == element) {
            matchCount++;
            std::cout << "Match #" << matchCount << " at index " << index << "\n";
        }
    }
    if (matchCount == 0) {
        std::cout << "Element not found.\n";
    } else {
        std::cout << "Total instances detected: " << matchCount << "\n";
    }
}

#endif