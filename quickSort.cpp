#include <iostream>

using namespace std;

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;  // Index of smaller element

        for (int j = low; j < high; ++j) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                // Swap arr[i+1] and arr[j]
                swap(arr[++i], arr[j]);
            }
        }

        // Swap arr[i+1] and arr[high] (put the pivot in its correct place)
        swap(arr[i + 1], arr[high]);

        int pivotIndex = i + 1;

        // Recursively sort the subarrays on the left and right of the pivot
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
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
    quicksort(c, 0, size-1);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}
