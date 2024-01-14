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


// depth first search algorithm for a tree -----------------
bool visited[15];

void dfs(Node* node) {
    if(!visited[node->index]) {
        cout << node->data << " ";
    }
    visited[node->index] = true;
    for (Node* n : node->children) {
        if (!visited[n->index]) {
            dfs(n);
        }
    }
}
// ---------------------------------------------------------

int main() {
    Node* root = createNode(0, 19);
    addChildren(root, 1, 18);
    addChildren(root, 2, 17);
    addChildren(root, 3, 16);
    addChildren(root->children[0], 4, 15);
    addChildren(root->children[0], 5, 14);
    addChildren(root->children[1], 6, 13);
    addChildren(root->children[1], 7, 12);
    addChildren(root->children[2], 8, 11);
    addChildren(root->children[2], 9, 10);
    
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

