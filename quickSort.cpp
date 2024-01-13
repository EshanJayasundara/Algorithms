#include <iostream>

using namespace std;

void quickSort(int array[], int low, int high) {
    if (low >= high) {
        return;
    }
    
    // choose middle element as the pivot
    int pivot_index = high;
    int x = low + (high-low)/2;
    int pivot = array[x];
    array[x] = array[pivot_index];
    array[pivot_index] = pivot;

    int i = low;
    int j = high - 1;
    
    while (i <= j) {
        if (array[i] <= array[pivot_index]) {
            i++;
        }
        if (array[j] > array[pivot_index]) {
            j--;
        }
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    
    // Swap pivot to its final position
    int temp = array[i];
    array[i] = array[pivot_index];
    array[pivot_index] = temp;
    
    quickSort(array, low, i - 1);
    quickSort(array, i + 1, high);
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
    quickSort(c, 0, size-1);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}
