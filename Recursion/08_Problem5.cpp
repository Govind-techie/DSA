/*
Problem: Find the First Occurrence of an Element in an Array using Recursion.

Description:
- Given an array of integers and a target element, find the index of the first occurrence of the target element.
- If the target element is not present in the array, return -1.

Example:
Input: arr = {1, 2, 3, 4, 2}, target = 2
Output: 1 (The first occurrence of 2 is at index 1)
*/

#include<iostream>
#include<vector>
using namespace std;

// Recursive function to find the first occurrence of the target element
int firstOccurrence(vector<int> arr, int n, int i, int target) {
    // Base case: If the current index exceeds the array bounds, return -1
    if (i == n) return -1;

    // Check if the current element matches the target
    if (arr[i] == target) {
        return i; // Return the current index if the target is found
    }

    // Recursive call
    return firstOccurrence(arr, n, i + 1, target);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 2}; 
    int target;
    cout << "Enter target value : ";
    cin >> target; 
    cout << "First Occurence of " << target << " is : " << firstOccurrence(arr, arr.size(), 0, target) << endl;
    return 0;
}


