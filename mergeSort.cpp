#include <iostream>

using namespace std;

void merge(int array1[], int size1, int array2[], int size2, int array[]) {
    int i = 0; int j = 0; int k = 0;
    while(i < size1 && j < size2) {
        if(array1[i] < array2[j]) {
            array[k] = array1[i];
            i++;
        } else {
            array[k] = array2[j];
            j++;
        }
        k++;
    }
    while(i < size1) {
        array[k] = array1[i];
        i++;
        k++;
    }
    while(j < size2) {
        array[k] = array2[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int size) {
    if(size < 2) {
        return;
    }
    int mid = size/2;

    int size_of_left = mid;
    int size_of_right = size-mid;

    int left_sub_array[size_of_left];
    int right_sub_array[size_of_right];

    for (size_t i = 0; i < mid; i++)
    {
        left_sub_array[i] = array[i]; 
    }
    for (size_t i = mid; i < size; i++)
    {
        right_sub_array[i-mid] = array[i];
    }

    mergeSort(left_sub_array, size_of_left);
    mergeSort(right_sub_array, size_of_right);
    merge(left_sub_array, size_of_left, right_sub_array, size_of_right, array);
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
    mergeSort(c, size);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}
