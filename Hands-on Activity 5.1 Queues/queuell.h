#ifndef QUEUELL_H
#define QUEUELL_H

// Create a class node
template <typename T>
class qNode {
    public:
        T data; 
        qNode* next;
};

// New Node Creator
template <typename T>
qNode<T>* new_node (T newData) {
    // Allocate a space for the new node
    qNode<T>* newNode = new qNode<T>;

    // Store the newData to the newNode
    newNode -> data = newData;

    // Point the newNode to the next
    newNode -> next = nullptr;

    return newNode;
}

// Enqueue
template <typename T>
void enqueue (T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {
    // Create a New Node
    qNode<T>* newNode = new_node (newData);

    // Check if the queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode; // Links the current back to the new node
        (*backPtr) = newNode; // Assigns the backPtr to the new node
        return;
    }

    // If not then insert at the back
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
    
}

// Dequeue
template <typename T>
void dequeue (qNode<T>** frontPtr, qNode<T>** backPtr) {

    // Check if the queue is empty 
    if((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "The queue is empty!" << std::endl;
        return; 
    }

    // Create a temporary variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;

    // Assign the current front to the deleteTemp
    deleteTemp = (*frontPtr);

    // Check if the current front to the deleteTemp
    if((*frontPtr) -> next == nullptr && (*backPtr) -> next == nullptr) {
        // Means only 1 item is inside the qeuev
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr) -> next;
    deleteTemp->next = nullptr;

    // Delete a node
    delete deleteTemp;
}

// Display All
template <typename T>
void displayAll (qNode<T>* frontPtr) {
    if (frontPtr == nullptr) {
    std::cout << "Queue is Empty!" << std::endl;
    return;
}
    qNode<T>* current = frontPtr;
    std::cout << "Queue Elements: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// isEmpty
template <typename T>
bool isEmpty (qNode<T>* frontPtr) {
    return (frontPtr == nullptr);
}

#endif