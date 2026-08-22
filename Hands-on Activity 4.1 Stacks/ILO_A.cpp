#include <iostream>
#include <stack>

int main () {

    // Testing ground of Stack
    std::stack<int> stack1;
    std::stack<int> stack2;
    std::cout<<"=========Testing the Stack STL===========" << std::endl;

    // isEmpty
    std::cout<<"Is the stack empty? " << stack1.empty() << std::endl;

    // Push
    std::cout << "=======Push Stack=======" << std::endl;
    stack1.push(10);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(9);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(8);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(7);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(6);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(5);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    std::cout << "The size of the stack is: " << stack1.size() << std::endl;
    std::cout << std::endl;

    // Pop
    stack1.pop(); 
    std::cout << "========Pop Stack========" << std::endl;
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    std::cout << "Is the stack empty? " << stack1.empty() << std::endl;
    std::cout << "The size of the stack is: " << stack1.size() << std::endl;

    // Emplace
    std::cout << "=========Emplace Stack=========" << std::endl;
    stack1.emplace(1); // Replaces the top value of the stack
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    std::cout << "The size of the stack is: " << stack1.size() << std::endl;

    // Swap
    stack2.push(4);
    stack2.push(3);
    stack2.push(2);
    stack1.swap(stack2); // Swaps the contents of stack1 and stack2

    //Swapped contents of stack 1 and stack 2
    std::cout << "==========Swap Stack==========" << std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() << std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;

    std::cout << "The size of the stack 1 is: " << stack1.size() << std::endl;
    std::cout << "The size of the stack 2 is: " << stack2.size() << std::endl;    
    return 0;
}

