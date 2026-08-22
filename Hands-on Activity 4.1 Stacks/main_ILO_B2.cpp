#include <iostream>
#include "stackList.h"

int main() {
    
    std::cout << "--- PUSHING 'C' 'P' 'E' ONTO THE STACK ---\n";

    // Pushing
    push('C');
    push('P');
    push('E');

    // Display the current top

    Top<char>; // Top should be 'E' 
    displayALL<char>();
    std::cout << "\n --- POPPIING ALL ELEMENT ---\n";

    while(!isEmpty<char>()) {
        std::cout<<"Popped: "<< pop<char>() <<std::endl;
    }

    std::cout << "\n --- TESTING THE UNDERFLOW --- \n";
    pop<char>();

    return 0;
}