#include <iostream>
#include <string>
#include "stackList.h"

int main() {
    std::string expression;
    char choice;

    std::cout << "=====================================\n";
    std::cout << "        BALANCING OF SYMBOL           \n";
    std::cout << "=====================================\n";

    do {
        std::cout << "\nEnter an expression: ";
        std::getline(std::cin, expression);

        if (isBalanced(expression)) {
            std::cout << "Result: Expression is Balanced.\n";
        } else {
            std::cout << "Result: Expression is Unbalanced.\n";
        }
        std::cout << "==========================================" << std::endl;
        std::cout << "\nWould you like to continue? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(); // Clears the newline character

    } while (choice == 'Y' || choice == 'y');

    std::cout << "\nExiting the Program!\n";

    return 0;
}