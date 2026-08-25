#include <iostream>
#include "queuell.h"

int main () {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "===============================" << std::endl;
    std::cout << "  Testing the Enqueue Operator " << std::endl;
    std::cout << "===============================" << std::endl;

    enqueue ('I', &front, &back);
    std::cout << front->data << " " << "back: " << back->data << std::endl;
    enqueue ('Y', &front, &back);
    std::cout << front->data << " " << "back: " << back->data << std::endl;
    enqueue ('A', &front, &back);
    std::cout << front->data << " " << "back: " << back->data << std::endl;

    std::cout << "===============================" << std::endl;
    std::cout << "  Testing the Dequeue Operator " << std::endl;
    std::cout << "===============================" << std::endl;

    dequeue(&front, &back);
    std::cout << front->data << " " << "back: " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << "back: " << back->data << std::endl;
    dequeue(&front, &back);    
    dequeue(&front, &back);

    std::cout << "===============================" << std::endl;
    std::cout << "      Display of Elements      " << std::endl;
    std::cout << "===============================" << std::endl;

    std::cout << "Elements: ";
    displayAll(front);


    return 0;
}
