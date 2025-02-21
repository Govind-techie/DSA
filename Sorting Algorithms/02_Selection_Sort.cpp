/*
Selection Sort : Selection Sort is a simple sorting algorithm that repeatedly selects the smallest (or largest) element from the unsorted
part of the array and swaps it with the first unsorted element. It continues this process until the entire array is sorted.

Time Complexity : O(n^2)

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) { // O(2^n)
    int n = arr.size();

    // Outer loop to go through the array
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i;
        
        // Inner loop to find the smallest element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestIdx]) {
                smallestIdx = j;
            }
        }

        // Swap the found smallest element with the element at i
        swap(arr[i], arr[smallestIdx]);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 1, 5, 2, 3};

    selectionSort(arr);
    printArray(arr);

    return 0;
}