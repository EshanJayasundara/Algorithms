#include <iostream>

using namespace std;

void selectionSort(int array[], int size) {
    for (size_t i = 0; i < size-1; i++)
    {
        int min_index = i;
        for (size_t j = i; j < size; j++)
        {
            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
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
    selectionSort(c, size);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}