#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(int arr[], int n) {
    const int numBuckets = 10; // Assuming 10 buckets for simplicity
    vector<int> buckets[numBuckets]; // array of vector<int>

    // Place elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = arr[i] / numBuckets;
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < numBuckets; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate sorted buckets to get the final sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
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
    bucketSort(c, size);

    // print sorted array
    for (size_t i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
}