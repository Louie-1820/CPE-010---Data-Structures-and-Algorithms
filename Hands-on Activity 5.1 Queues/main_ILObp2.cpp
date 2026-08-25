#include <iostream>
#include "queueArr.h"

int main()
{
    // creating an object
    queueArr<int> q(5);

    // enqueue 10, 20, 30, 40, 50:
    q.enqueue(1);

    //                  ================ ARRAY - BASED IMPLEMENTATION ================

    std::cout << "==============================" << std::endl;
    std::cout << " ARRAY - BASED IMPLEMENTATION " << std::endl;
    std::cout << "==============================" << std::endl;    

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    std::cout << "==============================" << std::endl; 

    q.enqueue(2);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    std::cout << "==============================" << std::endl; 

    q.enqueue(3);

    q.enqueue(4);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    std::cout << "==============================" << std::endl; 

    q.enqueue(5);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    std::cout << "==============================" << std::endl; 

    q.enqueue(6);

    std::cout << "==============================";

    std::cout << "\nremoved: " << q.dequeue() << std::endl;
    std::cout << "removed: " << q.dequeue() << std::endl;

    std::cout << "==============================" << std::endl; 

    // testing the clear
    q.Clear();

    std::cout << "is the queue empty? "
              << (q.Empty() ? "yes" : "no")
              << std::endl;

    std::cout << "==============================" << std::endl; 

    return 0;
}