#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree{
    private:
        T key;
        // Pointers: 
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;
        
    public:

        // Constructor: 
        BinaryTree<T>(T rootObj);

        // Adding/Inserting a chile node:
        void insertLeftChild(T rootObj);
        void insertRightChild(T rootObj);

        // Pointer:
        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();

        T getRootVal();
        void setRootVal(T rootObj);
        bool isLeaf();
        
};

template <typename T>
BinaryTree<T>::BinaryTree(T rootObj) {   
    key = rootObj; 
    leftChild = nullptr;
    rightChild = nullptr;
}

template <typename T>
void BinaryTree<T>::insertLeftChild(T newNode) {
    if (leftChild == nullptr) {
        leftChild = new BinaryTree<T> (newNode);
    } else {
    // Creating a new node:
    BinaryTree<T> *newChild = new BinaryTree<T> (newNode);

    // Move the existing left child below the new node
    newChild -> leftChild = leftChild;
    leftChild = newChild;
    }
}

template <typename T>
void BinaryTree<T>::insertRightChild(T newNode) {
    if (rightChild == nullptr) {
        rightChild = new BinaryTree<T> (newNode);
    }
    else {
        // Create a new node:
        BinaryTree<T> *newChild = new BinaryTree<T> (newNode);

        // Move existing Right Child below to the new node
        newChild -> rightChild = rightChild;
        rightChild = newChild;
    }
}

template<typename T> 
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
    return leftChild;
}

template<typename T> 
BinaryTree<T>* BinaryTree<T>::getRightChild() {
    return rightChild;
}

template<typename T>
T BinaryTree<T>::getRootVal() {
    return key;
}

template<typename T>
void BinaryTree<T>::setRootVal(T obj) {
    key = obj;
}

template<typename T>
bool BinaryTree<T>::isLeaf() {
    return leftChild == nullptr && rightChild == nullptr;
}

#endif