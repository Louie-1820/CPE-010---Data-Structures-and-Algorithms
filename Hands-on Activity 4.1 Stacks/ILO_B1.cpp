#include <iostream>

    // Global Declarations
#define maxCap 10
    int choice;
    int stackArr [maxCap];
    int top = -1, newData; 

    // Prototype Functions
    void push();
    void pop();
    void Top();
    bool isEmpty();
    bool isFull();
    void displayStack();
    
int main() {
    
    // Main Driver
    while (true) {
        std::cout << "==========Stack Operations:==========" << std::endl;
        std::cout << "1. Push Stack" << std::endl;
        std::cout << "2. Pop Stack" << std::endl;
        std::cout << "3. Top Stack" << std::endl;
        std::cout << "4. isEmpty Stack" << std::endl;
        std::cout << "5. isFull Stack" << std::endl;
        std::cout << "6. Display the stack" << std::endl;
        std::cout << "7. Exit the program" << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cin >> choice;

        if (choice == 7) {
            std::cout << "Exiting the Program!" << std::endl;
            break;  
        }

        switch (choice) { 
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << "Is the stack empty? " << isEmpty() << std::endl;
            break;
            case 5: std::cout << "Is the stack full? " << isFull() << std::endl;
            break; 
            case 6: displayStack();
            break;
            default: std::cout << "Invalid Choice" << std::endl;
        }
    }

    return 0;
}

    // Function Definition 

    bool isEmpty() {
        // Error checking 
        if (top == -1) return true;
        return false;
    }

    bool isFull() {
    if (top == maxCap - 1) return true;
    return false;
}

    void push() {
    // Error checking 
    if (isFull()) {
        std::cout << "Stack Overflow" << std::endl;
        return; 
    }
    // Pushing to the stack
    std::cout << "Enter a new value: " << std::endl;
    std::cin >> newData;
    stackArr [++top] = newData;
}

    void pop() {
    // Error checking 
    if (isEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }

    // Displays the "popped" value of the stack
    std::cout << "Value Popped: " << stackArr[top] << std::endl;

    // Decrement the top value from the stack
    top--;
}

    void Top () {
    // Error Catching
    if (isEmpty()) {
        std::cout << "The stack is empty!" << std::endl;
        return;
    }

    // Checks the top value:
    std::cout << "Top Element: " << stackArr[top] << std::endl;
}

    //Displays the elements of the stack
    void displayStack() {
        if (isEmpty()) {
            std::cout << "The stack is empty!" << std::endl;
        }
        for (int i = top; i >= 0; i--) {
            std::cout << stackArr[i] << ",";
        }
        std::cout << std::endl;
    }