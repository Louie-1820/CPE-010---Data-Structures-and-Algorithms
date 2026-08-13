#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList {
    public: 
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

// Creating a Node
template <typename T>
DoubleList<T> *CreateNewNode(T newData) {
    // Dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;
    // Store the data in the node
    newNode->data = newData;

    // Point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    // Return the address of the newly created node
    return newNode;
}   

template <typename T>
void dllTraverse(DoubleList<T>* currentNode) {

    DoubleList<T> *tail;
    // Check if the list is empty
    if (currentNode == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    // Move forward
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";  
        tail = currentNode;
        currentNode = currentNode->next;
    }

    // Adding a next line
    std::cout << std::endl;
    
    // Move backward
    while (tail != nullptr) {
        std::cout << tail->data << "";
        tail = tail->prev; 
    }
    std::cout << std::endl;
}

// Inserting at the head of the list
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead) {
    // Creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);
    
    // New node should point to the current head
    newNode->next = *currentHead;

    // Current Head should point back to the newNode
    (*currentHead) ->prev = newNode;

    // Update the pointer head
    *currentHead = newNode;
}

template <typename T>

void dllInsertHead(T newData, DoubleList<T>* currentHead) {
    // Create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // Traverse until we reach the last node
    while(currentHead->next != nullptr) {
        currentHead = currentHead->next;
    }

    // Connect the last node to the new node
    currentHead->next = newNode;

    // Connect the new node back to the last node
    newNode->prev = currentHead;

}

    // General Insert
template <typename T>

void dllGeneralInsert (T newData, DoubleList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be nullptr!" << std::endl;
        return;
    }
    DoubleList<T>* newNode = new DoubleList<T>;

    newNode->data = newData;

    newNode->next = prevNode->next;

    newNode->prev = prevNode;

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
}

// Delete a node
template <typename T> 

void dllDeleteNode (DoubleList<T>*& head, T findData) {
    DoubleList<T>* currNode = head;

    while (currNode != nullptr && currNode->data != findData) {
        currNode = currNode->next;
    }
    
    if(currNode == nullptr) {
        std::cout << "The data is not found" << std::endl;
        return;
    }

    if (head == currNode) {
        head = currNode->next;
    } 

    if (currNode->next != nullptr) {
        currNode->next->prev = currNode->prev;
    }

    if (currNode->prev != nullptr) {
        currNode->prev->next = currNode->next;
    }

    delete currNode;    
}

#endif