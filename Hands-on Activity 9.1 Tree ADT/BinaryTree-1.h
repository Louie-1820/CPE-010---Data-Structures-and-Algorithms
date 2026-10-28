#define BINARYTREE_h
#ifndef BINARYTREE_H

template <typename T>
class BinarySearchTree {
    private: 
        // Create a key
        T key;

        // Pointers for left and right
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;

    public:
        // Constructor
        BinarySearchTree(T value);
        void insert(T value);
    
        // Insert left and right

        // Traversing
        void preOrder();
        void inOrder();
        void postOrder();

        // Searching


};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    // Left or Right

    // Go left if < key insert to the left
    if (value < key) {
        if (left == nullptr) {
                left = new BinarySearchTree<T>(value);
        }else {
            left -> insert (value);
        }
    }

    // Go right if > key insert to the right
    else if (value > key) {
        if (right == nullptr) {
                right = new BinarySearchTree<T>(value);
        }else {
            right -> insert (value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder() {  // From root -> left -> right -> repeat
    std::cout << key << " ";
    if (left != nullptr) {
        left -> preOrder();
    }

    if (right != nullptr) {
        right -> preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder() { // From left -> root -> right -> repeat
    // Go to left
    if (left != nullptr) {
        left -> inOrder();
    }
    std::cout << key << " ";

    // Go to Right
    if (right != nullptr) {
        right -> inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder() { // From left -> right -> root -> repeat
    // Go to left
    if (left != nullptr) {
        left -> postOrder();
    }

    // Go to Right
    if (right != nullptr) {
        right -> postOrder();
    }
    std::cout << key << " ";
}

#endif
