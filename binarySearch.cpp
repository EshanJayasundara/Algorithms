#include <iostream>
#include <algorithm>

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

int binarySearch(int array[], int key, int high, int low) {
    int mid = low + (high-low)/2;
    if(array[mid] == key) {
        return mid;
    } else if(array[mid] < key) {
        return binarySearch(array, key, high, mid+1);
    } else {
        return binarySearch(array, key, low, mid-1);
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

    bubbleSort(c, size);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }

    int result = binarySearch(c, 5, size-1, 0);
    cout << "\n" << result;
}