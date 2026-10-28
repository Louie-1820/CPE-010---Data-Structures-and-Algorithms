#include <iostream>
#include <vector>
#include <string>

struct Node {
    char data;
    std::vector<Node*> children;

    Node(char val) {
        data = val;
    }
};

// Task 3.2 Functions 

// Pre-order Function
void preOrder(Node* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    for (Node* child : root->children) {
        preOrder(child);
    }
}

// Post-order Function
void postOrder(Node* root) {
    if (root == nullptr) return;
    for (Node* child : root->children) {
        postOrder(child);
    }
    std::cout << root->data << " ";
}

// In-order Function
void inOrder(Node* root) {
    if (root == nullptr) return;
    if (!root->children.empty()) {
        inOrder(root->children[0]);
    }
    std::cout << root->data << " ";
    for (size_t i = 1; i < root->children.size(); ++i) {
        inOrder(root->children[i]);
    }
}

// Task 3.3: findData
// Pre-Order helper search
bool searchPreOrder(Node* root, char key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    for (Node* child : root->children) {
        if (searchPreOrder(child, key)) return true;
    }
    return false;
}

// Post-Order helper search
bool searchPostOrder(Node* root, char key) {
    if (root == nullptr) return false;
    for (Node* child : root->children) {
        if (searchPostOrder(child, key)) return true;
    }
    return (root->data == key);
}

// In-Order helper search
bool searchInOrder(Node* root, char key) {
    if (root == nullptr) return false;
    if (!root->children.empty()) {
        if (searchInOrder(root->children[0], key)) return true;
    }
    if (root->data == key) return true;
    for (size_t i = 1; i < root->children.size(); ++i) {
        if (searchInOrder(root->children[i], key)) return true;
    }
    return false;
}

void findData(Node* root, std::string CHOICE, char KEY) {
    bool found = false;
    if (CHOICE == "PRE") {
        found = searchPreOrder(root, KEY);
    } else if (CHOICE == "POST") {
        found = searchPostOrder(root, KEY);
    } else if (CHOICE == "IN") {
        found = searchInOrder(root, KEY);
    } else {
        std::cout << "Invalid traversal choice!" << std::endl;
        return;
    }

    if (found) {
        std::cout << KEY << " was found!" << std::endl;
    }
}

// Helper function 
Node* findNode(Node* root, char key) {
    if (root == nullptr) return nullptr;
    if (root->data == key) return root;
    for (Node* child : root->children) {
        Node* res = findNode(child, key);
        if (res != nullptr) return res;
    }
    return nullptr;
}

int main() {
    Node* root = new Node('A');
    Node* b = new Node('B');
    Node* c = new Node('C');
    Node* d = new Node('D');
    Node* e = new Node('E');
    Node* f = new Node('F');
    Node* g = new Node('G');

    root->children.push_back(b);
    root->children.push_back(c);
    root->children.push_back(d);
    root->children.push_back(e);
    root->children.push_back(f);
    root->children.push_back(g);

    Node* h = new Node('H');
    d->children.push_back(h);

    Node* i = new Node('I');
    Node* j = new Node('J');
    e->children.push_back(i);
    e->children.push_back(j);

    Node* p = new Node('P');
    Node* q = new Node('Q');
    j->children.push_back(p);
    j->children.push_back(q);

    Node* k = new Node('K');
    Node* l = new Node('L');
    Node* m = new Node('M');
    f->children.push_back(k);
    f->children.push_back(l);
    f->children.push_back(m);

    Node* n = new Node('N');
    g->children.push_back(n);

    std::cout << "======= Task 3.2 =======" << std::endl;
    std::cout << "Pre-order:  "; preOrder(root); std::cout << std::endl;
    std::cout << "Post-order: "; postOrder(root); std::cout << std::endl;
    std::cout << "In-order:   "; inOrder(root); std::cout << std::endl << std::endl;

    //  Task 3.3
    std::cout << "======= Task 3.3 =======" << std::endl;
    findData(root, "PRE", 'P');
    findData(root, "POST", 'Z'); // Non-existent key

    //  Task 3.4
    std::cout << "\n======= Task 3.4 =======" << std::endl;
    Node* nodeG = findNode(root, 'G');
    if (nodeG != nullptr) {
        nodeG->children.push_back(new Node('O'));
        std::cout << "Node fa'O' added as child of 'G'." << std::endl;
    }

    // Perform findData search after adding character 'O'
    findData(root, "PRE", 'O');

    return 0;
}