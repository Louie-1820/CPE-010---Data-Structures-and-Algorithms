#include <iostream>
#include "BinaryTree.h"


int main () {
    // Create the root node
    BinarySearchTree<int> tree(2);

    std::cout << "========== BINARY SEARCH TREE ==========" << std::endl;
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);    
    
    std::cout << "Pre Order: ";
    tree.preOrder();
    std::cout << std::endl;

    std::cout << "In Order: ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "Post Order: ";
    tree.postOrder();
    std::cout << std::endl;
    std::cout << "========================================";

    return 0;
}