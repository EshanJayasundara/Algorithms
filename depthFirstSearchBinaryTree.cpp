#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int index;
    int data;
    vector<Node*> children;
};

Node* createNode(int index, int data);
void addChildren(Node* parent, int index, int data);


// depth first search algorithm for a binary tree -----------------
bool visited[15];

void dfs(Node* node) {
    visited[node->index] = true;
    cout << node->data << " ";
    for (Node* n : node->children) {
        if (!visited[n->index]) {
            dfs(n);
        }
    }
}
// ----------------------------------------------------------------

int main() {
    Node* root = createNode(0, 2);
    addChildren(root, 1, 5);
    addChildren(root, 2, 7);
    addChildren(root->children[0], 3, 3);
    addChildren(root->children[0], 4, 5);
    addChildren(root->children[1], 5, 2);
    addChildren(root->children[1], 6, 6);
    
    dfs(root);

    return 0;
}

Node* createNode(int index, int data) {
    Node* newNode = new Node();
    newNode->index = index;
    newNode->data = data;
    return newNode;
}

void addChildren(Node* parent, int index, int data) {
    Node* child = new Node();
    child->data = data;
    child->index = index;
    parent->children.push_back(child);
}

