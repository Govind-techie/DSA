/*
Problem: Find the Last Occurrence of an Element in an Array using Recursion.

Description:
- Given an array of integers and a target element, find the index of the last occurrence of the target element.
- If the target element is not present in the array, return -1.

Example:
Input: arr = {1, 2, 3, 4, 3, 5}, target = 3
Output: 4 (The last occurrence of 3 is at index 4)
*/

#include<iostream>
#include<vector>
using namespace std;

int lastOccurrence(vector<int> arr, int i, int target) {
    // Base case: If the index exceeds the array bounds, return -1
    if (i == arr.size()) return -1;

    // Recursive call to check the rest of the array
    int idx = lastOccurrence(arr, i + 1, target);

    // If the target is not found in the rest of the array, check the current element
    if (idx == -1 && (arr[i] == target)) {
        return i; // Return the current index if the target is found
    }

    // Otherwise, return the index found in the recursive call
    return idx;
}

// NOTE: This function first traverses the entire array to the end. 
// Then, as the recursion unwinds, it checks each element in reverse order to find the last occurrence of the target.

int main() {
    vector<int> arr = {1, 2, 3, 4, 3, 5}; 
    int target;
    cout << "Enter target value : ";
    cin >> target;

    cout << "Last Occurrence of " << target << " is : " << lastOccurrence(arr, 0, target) << endl;

    return 0;
}