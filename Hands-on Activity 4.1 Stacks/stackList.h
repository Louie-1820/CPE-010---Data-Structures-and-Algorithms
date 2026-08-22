#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

template <typename T>
class Node {
    public:
    T data; // VALUE WE NEED TO STORE
    Node* next; // POINTER TO THE NEXT NODE
};

// Global pointer for the top of the stack 
template <typename T>
Node<T>* head = nullptr;

                                    // --------- Operations for the stack -----------//

// Push
template <typename T>
void push(T newData) {
    // Create a new node and assign the newData
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;

    // New node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}

// Pop

template <typename T>
T pop() {
    // Check if the stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow" << std::endl;
        return T();
    }

    // Save the current top node
    Node<T>* temp = head<T>;
    // Store its data
    T tempVal = temp->data;

    // Move the top pointer to the next node
    head<T> = head<T>->next;

    // Free the removed node
    delete temp;

    // Return the removed value
    return tempVal;
}

// isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// Top
template <typename T>
void Top() {
    // Errot Catching:
    if (head<T> == nullptr) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    // Display the top element
    std::cout << "Top element: " << head<T>->data << std::endl;
}

// Display All
template <typename T>
void displayALL() {
    // Error Catching:
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow\n" << std::endl;
        return;
    }

    // Traverse the stack and display all elements
    Node<T>* temp = head<T>;
    std::cout << "Stack elements: \n";
    while (temp != nullptr) {
        std::cout << temp->data << " \n";
        temp = temp->next;
    }
    std::cout << std::endl;
}


                // ----------- Implementation of Functions in Supplementary Activity ----------- //

// Opening Symbol
inline bool isOpen(char c) {
    return (c == '(' || c == '[' || c == '{');
}

// Closing Symbol
inline bool isClose(char c) {
    return (c == ')' || c == ']' || c == '}');
}

// Symbols Matched
inline bool isMatched(char openChar, char closeChar) {
    switch (openChar) {
        case '(': return closeChar == ')';
        case '[': return closeChar == ']';
        case '{': return closeChar == '}';
        default:  return false;
    }
}

// Symbols Balanced
inline bool isBalanced(const std::string& expression) {
    // Reset global stack state
    while (!isEmpty<char>()) {
        pop<char>();
    }

    for (size_t i = 0; i < expression.length(); ++i) {
        char currentChar = expression[i];

        if (isOpen(currentChar)) {
            push<char>(currentChar);
        } 
        else if (isClose(currentChar)) {
            // Unmatched closing symbol found when stack is empty
            if (isEmpty<char>()) {
                return false;
            }

            char lastOpened = pop<char>();
            if (!isMatched(lastOpened, currentChar)) {
                return false;
            }
        }
    }

    return isEmpty<char>();
}

#endif