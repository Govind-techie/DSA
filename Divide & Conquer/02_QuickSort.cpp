/*
Problem Statement:
Implement the Quick Sort algorithm to sort an array of integers in ascending order.
Quick Sort is a divide-and-conquer algorithm that selects a pivot element, partitions the array
around the pivot, and recursively sorts the subarrays.

Pivot Explanation:
The pivot is a key element used to partition the array. During partitioning:
1. All elements smaller than the pivot are moved to its left.
2. All elements greater than or equal to the pivot are moved to its right.

Example Explanation of Pivot:
Consider the array [10, 7, 8, 9, 1, 5] and choosing the last element (5) as the pivot:
- Initially: [10, 7, 8, 9, 1, 5]
- After partitioning:
    - Elements smaller than 5: [1]
    - Elements greater than or equal to 5: [10, 7, 8, 9]
    - Pivot (5) is placed in its correct position.
- Result after partitioning: [1, 5, 8, 9, 10, 7]

Input: An unsorted array of integers.
Output: A sorted array of integers in ascending order.

Example:
Input: [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

Constraints:
1. The array may contain duplicate elements.
2. The size of the array can range from 1 to 10^5.
*/

#include<iostream>
#include<vector>
using namespace std;

/*
The partition function rearranges the array such that:
1. All elements smaller than the pivot are moved to its left.
2. All elements greater than or equal to the pivot are moved to its right.
It returns the index of the pivot after placing it in its correct position.
*/
int partition(vector<int>& arr, int stIdx, int enIdx) {
    int pivot = arr[enIdx]; // Choose the last element as the pivot
    int i = stIdx - 1;      // Pointer for the smaller element (left partition)

    // Iterate through the array to rearrange elements
    for (int j = stIdx; j < enIdx; j++) {
        if (arr[j] <= pivot) { // If the current element is smaller than or equal to the pivot
            swap(arr[++i], arr[j]); // Move it to the left partition
        }
    }

    // Place the pivot in its correct position
    swap(arr[++i], arr[enIdx]);
    return i; // Return the index of the pivot
}

/*
The quickSort function implements the divide-and-conquer approach:
1. It partitions the array around a pivot.
2. Recursively sorts the left and right subarrays.
*/
void quickSort(vector<int>& arr, int stIdx, int enIdx) {
    if (stIdx >= enIdx) return; // Base case: array of size 1 or empty

    // Partition the array and get the pivot index
    int pivotIdx = partition(arr, stIdx, enIdx);

    // Recursively sort the left and right subarrays
    quickSort(arr, stIdx, pivotIdx - 1);  // Sort the left subarray
    quickSort(arr, pivotIdx + 1, enIdx); // Sort the right subarray
}

/*
The printArray function prints the elements of the array.
It is used to display the original and sorted arrays.
*/
void printArray1(vector<int> arr) {
    cout << "Original Array: ";
    for (int num : arr) { // => for each loop
        cout << num << " ";
    }
    cout << endl;
}

void printArray2(vector<int>arr){
    cout << "Sorted Array: ";
    for (int num : arr) { // => for each loop
        cout << num << " "; 
    }
    cout << endl;
}


int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5}; // Example unsorted array

    printArray1(arr); // Print the original array
    quickSort(arr, 0, arr.size() - 1); // Call Quick Sort
    printArray2(arr); // Print sorted array

    return 0;
}

/*
Average Time Complexity of Quick Sort:
- On average, Quick Sort has a time complexity of O(n log n).
- This happens when the pivot divides the array into two nearly equal halves at each step.
- Example:
    Input: [10, 7, 8, 9, 1, 5]
    Step 1: Pivot = 5
        Left: [1]
        Right: [10, 7, 8, 9]
        Result: [1, 5, 8, 9, 10, 7]
    Step 2: Recursively sort left and right subarrays.
    Step 3: Continue dividing until subarrays have one element.
    Final Sorted Array: [1, 5, 7, 8, 9, 10]
- The recurrence relation for this case is T(n) = 2T(n/2) + O(n), which solves to O(n log n).
- This makes Quick Sort efficient for most inputs.
*/

/*
Worst-Case Time Complexity of Quick Sort:
- In the worst case, Quick Sort has a time complexity of O(n^2).
- This happens when the pivot divides the array into highly unbalanced partitions.
- Example:
    Input: [1, 2, 3, 4, 5, 6] (already sorted)
    Step 1: Pivot = 6
        Left: [1, 2, 3, 4, 5]
        Right: []
        Result: [1, 2, 3, 4, 5, 6]
    Step 2: Recursively sort left subarray [1, 2, 3, 4, 5].
    Step 3: Continue dividing until subarrays have one element.
    Final Sorted Array: [1, 2, 3, 4, 5, 6]
- The recurrence relation for this case is T(n) = T(n-1) + O(n), which solves to O(n^2).
- This happens when the pivot is always the smallest or largest element (e.g., sorted or reverse-sorted input).

NOTE -> *This complexity occurs when repeatedly the smallest or the largest element of the array becomes the pivot
*/
