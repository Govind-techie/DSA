// Linear Search : Linear Search is a simple algorithm used to find a specific element in a list or array. It checks each element one by one 
// from the start to the end until the target element is found or the whole list has been searched.

// Time Complexity : Linear Search Time Complexity is O(n).

#include<iostream>
using namespace std;

// Problem : create a function that find whether a given value is present in array or not. If present return its index and if not return -1 as index.

int linearSearch(int arr[], int size, int n) {
    // Loop through the array to search for the target value 'n'.
    for (int i = 0; i < size; i++) {
        // If the current element matches the target value, return its index.
        if (arr[i] == n) {
            return i;
        }
    }
    // If the target value is not found in the array, return -1.
    return -1;
}

int main() {
    // Input: The value to search for in the array.
    int n;
    cout << "Enter a value : ";
    cin >> n;

    // Initialize the array with some values.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Calculate the size of the array.
    int size = sizeof(arr) / sizeof(int);

    // Call the search function and print the result.
    // If the value is found, its index is printed; otherwise, -1 is printed.
    cout << linearSearch(arr, size, n) << endl;

    return 0;
}