#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    Node* root = new Node(27);

    root->left = new Node(14);
    root->right = new Node(35);

    root->left->left = new Node(10);
    root->left->right = new Node(19);
    root->right->left = new Node(31);
    root->right->right = new Node(42);

    std::cout << "Creation of Binary Tree is Successful!" << std::endl;

    return 0;
}

