#include <iostream>

using namespace std;

string circularLeftShift(string array) {
    char temp = array[0];
    for (size_t i = 1; i < array.length(); i++)
    {
        array[i-1] = array[i];
    }
    array[27] = temp;
    return array;
}


int main() {
    char arr[] = "9123456789012345678901234567";
    cout << circularLeftShift(arr) << endl;
    return 0;
}