#include <iostream>
#include "doubly_ll.h"

int main () {
    // Create a list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "================================================" << std::endl;

    // Traversal
    std::cout << "Testing the DLL Traversal" << std::endl;
    dllTraverse(head);

    std::cout << "------------------------------------------------" << std::endl;

    // Testing the insert at the head
    std::cout << "Testing the insertion at the head of the node!" << std::endl;
    dllInsertHead ('X', &head);
    dllTraverse (head);

    std::cout << "------------------------------------------------" << std::endl;

    // Testing the insert at the head
    std::cout << "Testing the insertion at the end!" << std::endl;
    dllInsertHead ('0', head);
    dllTraverse(head);

    std::cout << "------------------------------------------------" << std::endl;

    // Testing the general insert
    std::cout << "Testing the general insert!" << std::endl;
    dllGeneralInsert('0', head->next);
    dllTraverse(head);

    std::cout << "------------------------------------------------" << std::endl;

    // Testing the deletion of node
    std::cout << "Testing the deletion of node!" << std::endl;
    dllDeleteNode(head, '0');
    dllTraverse(head);

    std::cout << "================================================" << std::endl;
}