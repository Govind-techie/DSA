/*
Problem Statement: Print Subarray

Subarray: A subarray is a contiguous portion of an array, consisting of consecutive elements from the original array.
For example, in the array [1, 2, 3, 4], the subarrays include [1], [1, 2], [2, 3], [1, 2, 3], and so on.

Time Complexity (Brute Force Approach): O(n^3)
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n]; // Declare array of size n

    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter values for array: ";
        cin >> arr[i];
    }

    // Generate and print all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "["; // Start subarray
            for (int k = i; k <= j; k++) {
                cout << arr[k];
                if (k < j) cout << ","; // Add comma between elements
            }
            cout << "]" << endl; // End subarray
        }
    }

    /*
    Output:
    [1]
    [1,2]
    [1,2,3]
    [1,2,3,4]
    [1,2,3,4,5]
    [2]
    [2,3]
    [2,3,4]
    [2,3,4,5]
    [3]
    [3,4]
    [3,4,5]
    [4]
    [4,5]
    [5]
    */



    return 0;
}