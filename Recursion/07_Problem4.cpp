/*
Problem: Check if an array is sorted using recursion.
*/

#include<iostream>
using namespace std;

// Recursive function to check if the array is sorted
bool isSortedArray(int arr[], int n) {
    // Step 1: Base Case
    if (n <= 1) {
        return true; // An array with 0 or 1 element is always sorted
    }

    // Step 2: Work (Check if the last two elements are sorted)
    if (arr[n-2] > arr[n-1]) {
        return false; // If the last two elements are not sorted, return false
    }

    // Step 3: Recursive Call (Check the rest of the array)
    return isSortedArray(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr) / sizeof(int); 

    if (isSortedArray(arr, n)) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is NOT sorted" << endl;
    }

    // OUTPUT => Array is sorted
    return 0;
}