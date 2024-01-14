#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

Node* createNode(int data);
void addChildren(Node* parent, int data);
void printNodes(Node* node);

int main() {
    
    Node* root = createNode(2);
    addChildren(root, 5);
    addChildren(root, 7);
    addChildren(root->children[0], 3);
    addChildren(root->children[0], 5);
    addChildren(root->children[1], 2);
    addChildren(root->children[1], 6);
    
    printNodes(root); // depth traversal in a binary tree

    return 0;
}

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    return newNode;
}

void addChildren(Node* parent, int data) {
    Node* child = new Node();
    child->data = data;
    parent->children.push_back(child);
}

// depth first traversal in a binary tree
void printNodes(Node* node) {
    cout << node->data << " ";
    if (size(node->children) == 0) {
        return;
    }
    printNodes(node->children[0]);
    printNodes(node->children[1]);
}
