#include <iostream>

using namespace std;

void bubbleSort(int array[], int size) {
    // (size-j) x size swaps
     for (size_t j = 1; j <= size; j++)
     {
        // size-j swaps
        for (size_t i = 0; i < size-j; i++)
        {
            if(array[i] > array[i+1]) {
                int temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
        }
     }
}

int main() {
    // size of the array
    int size;
    cin >> size;

    // declaring the array
    int c[size];

    // initializing the array
    for (size_t i = 0; i < size; i++)
    {
        cin >> c[i];
    }

    // call bubbleSort function
    bubbleSort(c, size);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}
