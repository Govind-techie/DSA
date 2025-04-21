/*
Insertion Sort : Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It works by taking each
element from the unsorted part of the array and inserting it into its correct position within the sorted part.

// Time Complexity : O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Outer loop starts from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int curr = arr[i];       // The current element to be inserted
        int prev = i - 1;        // The last element of the sorted portion

        // Move elements of the sorted portion that are greater than 'curr' to one position ahead
        while (prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]); // Shift elements to the right
            prev--;                      // Move to the previous element
        }
        
        // Insert the current element into its correct position
        arr[prev + 1] = curr;
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
    
    insertionSort(arr);
    printArray(arr);

    return 0;
}