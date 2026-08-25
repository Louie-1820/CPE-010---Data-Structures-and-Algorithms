#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

//                                  ================ IMPLEMENTATION OF QUEUES ================ 
int main() {

    // Create an Object:
    std::queue<char> myQ;

    // Use the enqueue operation
    myQ.push('I');  
    myQ.push('Y');
    myQ.push('A');  

    // Prints the Front and Back of the queue
    std::cout << "========================" << std::endl;
    std::cout << "    QUEUE OPERATIONS    " << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "Current Front is: " << myQ.front() << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "Current Back is: " << myQ.back() << std::endl;
    std::cout << "========================" << std::endl;
    display(myQ);

    // Use the dequeue  operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    std::cout << "========================" << std::endl;

    // Check the queue if it is empty
    std::cout << "Is the queue empty? " << myQ.empty() << std::endl;
    std::cout << "========================" << std::endl;



    return 0;
}

// Only the member functions of the queue STL
void display (std::queue<char> copyQ) {
    // Create a copy of the queue
    std::queue <char> temp = copyQ;
    // Loop until empty
    while (!temp.empty()) {
        // Display the front
            std::cout << " " << temp.front() << " ";

        // Dequeue the front
            temp.pop();
    }

    // Add a new line
    std::cout << std::endl;
    
}