#include <iostream>
#include "BinaryTree.h"

int main () {

    // Creating the root node
    BinaryTree<char>* root = new BinaryTree<char>('I');

    //Creating a child of root node I:
    root -> insertLeftChild('Y');
    root -> insertRightChild('A');

    // Insert a child to Node B:
    root -> getLeftChild() -> insertLeftChild('H');
    root -> getLeftChild() -> insertRightChild('I');

    // Insert a child to Node C:
    root -> getRightChild() -> insertLeftChild('Y');
    root -> getRightChild() -> insertRightChild('A');

    // Print the root node:
    std::cout << "Root: " << root -> getRootVal() << std::endl;

    // Children of the root node
    std::cout << "Root Left Child: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Root Right Child: " << root->getRightChild()->getRootVal() << std::endl;

    // Children of the sub trees B and C
    std::cout << "Root Left Child: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Root Right Child: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;

    root -> getLeftChild() -> getRightChild() -> setRootVal('E');

    return 0;
}