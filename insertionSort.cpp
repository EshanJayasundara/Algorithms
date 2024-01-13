#include <iostream>

using namespace std;

void shiftArray(int array[], int size, int index1, int index2) {
    for (size_t i = index2; i > index1; i--)
    {
        array[i] = array[i-1];
    }
}

void insertionSort(int array[], int size) {
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(array[i] < array[j]) {
                int temp = array[i];
                shiftArray(array, size, j, i);
                array[j] = temp;
                break;
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
    insertionSort(c, size);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}
