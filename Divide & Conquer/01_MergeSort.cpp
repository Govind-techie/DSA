/*
Problem Statement:
Implement the Merge Sort algorithm to sort an array of integers in ascending order.
Merge Sort is a divide-and-conquer algorithm that divides the array into two halves,
recursively sorts them, and then merges the sorted halves.

Input: An unsorted array of integers.
Output: A sorted array of integers in ascending order.

Example:
Input: [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Time Complexity -> O(nlogn)
Space Complexity -> O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

/*
The merge function is responsible for merging two sorted halves of the array into a single sorted array.
It takes the array arr and the indices stIdx (start index) and enIdx (end index) as input.
*/
void merge(vector<int>& arr, int stIdx, int enIdx){ // -> O(n)
    // Calculate the middle index to divide the array into two halves
    int mid = stIdx + (enIdx - stIdx) / 2;

    // Temporary vector to store the merged sorted elements
    vector<int> temp;

    // Pointers for the left and right halves of the array
    int i = stIdx;     // Pointer for the left half
    int j = mid + 1;   // Pointer for the right half

    // Merge the two halves into the temp array in sorted order
    while (i <= mid && j <= enIdx) {
        if (arr[i] <= arr[j]) {
            // If the current element in the left half is smaller, add it to temp
            temp.push_back(arr[i++]);
        } else {
            // Otherwise, add the current element from the right half to temp
            temp.push_back(arr[j++]);
        }
    }

    // Handle remaining elements in the left half (if any)
    // These elements are already sorted, so we add them directly to temp
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Handle remaining elements in the right half (if any)
    // These elements are already sorted, so we add them directly to temp
    while (j <= enIdx) {
        temp.push_back(arr[j++]);
    }

    // Copy the sorted elements from `temp` back into the original array `arr`
    for (int idx = stIdx, k = 0; idx <= enIdx; idx++) {
        arr[idx] = temp[k++];
    }
}

/*
The mergeSort function implements the divide-and-conquer approach to sort the array.
It recursively divides the array into smaller subarrays, sorts them, and then merges them.
*/
void mergeSort(vector<int>& arr, int stIdx, int enIdx) { // O(logn)
    // Base case: If the array has one or no elements, it is already sorted
    if (stIdx >= enIdx) return;

    // Calculate the middle index to divide the array into two halves
    int mid = stIdx + (enIdx - stIdx) / 2;

    // Recursively sort the left half of the array
    mergeSort(arr, stIdx, mid);

    // Recursively sort the right half of the array
    mergeSort(arr, mid + 1, enIdx);

    // Merge the two sorted halves
    merge(arr, stIdx, enIdx);
}

/*
The printArray function prints the elements of the array.
It takes the array as input and iterates through it to display the elements.
*/
void printArray(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    // Initialize an unsorted array
    vector<int> arr = {2, 4, 3, 5, 1, 6};

    // Call the mergeSort function to sort the array
    mergeSort(arr, 0, arr.size() - 1);

    // Print the sorted array
    printArray(arr);

    return 0;
}
