#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

void push(int value);
int pop();
    
Node* head = NULL;

int main() {
    
    push(5);
    push(3);
    push(7);
    push(1);
    cout << pop() << std::endl;
    cout << pop() << std::endl;
    cout << pop() << std::endl;
    cout << pop() << std::endl;

    return 0;
}

void push(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

int pop() {
    Node* ret = head;
    head = head->next;
    return ret->value;
}