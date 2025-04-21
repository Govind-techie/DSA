/* 
Bubble Sort : Bubble Sort is a simple sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order.
This process continues until the array is fully sorted. It works by "swaping" the largest (or smallest) element to the correct position
in each pass.

Time Complexity : O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

// Bubble Sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Outer loop for each pass
    for (int i = 0; i < n - 1; i++) {
        swapped = false; // Flag to check if any swapping occurred

        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap if elements are in wrong order 
                swapped = true; // Set flag to true if a swap occurred
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
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


    bubbleSort(arr);
    printArray(arr);

    return 0;
}