/*
Heap Sort

- Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure.
- It works in two main phases:
  1. Build a max-heap from the input data.
  2. Repeatedly extract the maximum element from the heap and move it to the end of the array, reducing the heap size each time.
- The process ensures the array is sorted in ascending order.

- Time Complexity: O(n log n) for all cases (best, average, worst).
- Space Complexity: O(1) (in-place sorting).
- Not a stable sort (relative order of equal elements may change).

- Steps:
  * Build a max-heap from the input array.
  * Swap the root (maximum) with the last element.
  * Reduce the heap size and heapify the root.
  * Repeat until the heap size is 1.

- Applications:
  * Sorting large datasets
  * Priority queue implementations
*/

#include <iostream>
#include <vector>
using namespace std;

// This function ensures the subtree rooted at index 'i' satisfies the max-heap property
void heapify(int i, vector<int>& heap, int n) { // {Time Complexity: O(logn)}
    int parent = i;
    int left = (2 * i) + 1; // Left child index
    int right = (2 * i) + 2; // Right child index

    // Find the largest among parent, left child and right child
    if (left < n && heap[left] > heap[parent]) {
        parent = left;
    }
    if (right < n && heap[right] > heap[parent]) {
        parent = right;
    }

    /*
    Note: change condition of parent and child comparison 
    from '>' to '<' in heapify() to sort in descending order.
    */

    // If parent is not the largest, swap and continue heapifying
    if (parent != i) {
        swap(heap[parent], heap[i]);
        heapify(parent, heap, n); // Recursively fix the affected subtree
    }
}

// Main heap sort function
void heapSort(vector<int>& arr) { // {Time Complexity: O(nlogn)}
    int n = arr.size();

    // STEP 1: Build a max-heap from the unsorted array
    // Start from the last non-leaf node and move up
    for (int i = (n / 2) - 1; i >= 0; i--) { // {Time Complexity: O(nlogn)}
        heapify(i, arr, n); // {Time Complexity: O(logn)}
    }

    // STEP 2: One by one, extract elements from the heap
    // Move the current root (maximum) to the end, reduce heap size, and heapify again
    for (int i = n - 1; i >= 0; i--) { // {Time Complexity: O(nlogn)}
        swap(arr[0], arr[i]); // Move current max to the end
        heapify(0, arr, i); // Rebuild max-heap for reduced heap {Time Complexity: O(logn)}
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    
    heapSort(arr); // Perform heap sort

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}