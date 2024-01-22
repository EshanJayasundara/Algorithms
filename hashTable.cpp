#include <iostream>
#include <string>

using namespace std;

struct node {
    int key;
    string name;
    node* next = NULL;
};

node* arr[10];

void addNode(int key, string name) {
    node* n = new node();
    n->key = key;
    n->name = name;
    n->next = arr[key % 10];
    arr[key % 10] = n;
}

int main() {
    addNode(1, "Alice");
    addNode(2, "Bob");
    addNode(4, "Charlie");
    addNode(3, "Eshan");
    addNode(5, "Gayanga");
    addNode(6, "Jayasundara");
    addNode(8, "Kamal");
    addNode(9, "Udaya");
    addNode(7, "Siripala");
    addNode(17, "Pumudu");
    addNode(11, "Nadun");
    addNode(10, "Lakshitha");
    addNode(12, "Chamanga");
    addNode(14, "Isira");
    addNode(13, "Pavithra");
    addNode(15, "Kusum");
    addNode(16, "Nipun");
    addNode(18, "Rajitha");
    addNode(19, "Pasan");
    addNode(20, "Mewan");

    int key = 21;
    node* index_node = arr[key%10];
    while(index_node != NULL && index_node->key != key) {
        index_node = index_node->next;
    }
    if(index_node != NULL) {
        cout << "Key: " << index_node->key << ", Name: " << index_node->name << endl;
    } else {
        cout << "node with key " << key << " not found" << endl;
    }
    return 0;
}
