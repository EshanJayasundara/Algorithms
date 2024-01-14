#include <iostream>
#define SIZE 100

using namespace std;

int stack[SIZE];
int in = 0;

void push(int data);
int pop();

int main() {

    push(5);
    push(3);
    cout << pop() << std::endl;
    push(7);
    push(1);
    cout << pop() << std::endl;
    cout << pop() << std::endl;
    push(3);
    push(4);
    push(8);
    push(2);
    cout << pop() << std::endl;
    cout << pop() << std::endl;
    cout << pop() << std::endl;
    cout << pop() << std::endl;
    cout << pop() << std::endl;

    return 0;
}

void push(int data) {
    if(in == SIZE) {
        in = 0;
    }
    stack[in] = data;
    in ++;
}

int pop() {
    in --;
    return stack[in];
}