/*
Pair Sum Problem

Given an array of integers and a target sum, find if there exists a pair of elements in the array whose sum is equal to the target.

Input:
- An array of integers (can contain positive and negative numbers)
- An integer target sum

Output:
- Return true if such a pair exists, otherwise return false.

Example:
Input: arr = [2, 7, 11, 15], target = 9
Output: true
Explanation: 2 + 7 = 9

Input: arr = [1, 2, 3, 4], target = 8
Output: false
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Function to find the indices of two elements that sum up to the target
pair<int,int> pairSum(vector<int> arr, int target) { // Time Complexity : O(n)
    unordered_map<int, int> m;  // Map to store value -> index

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        int comp = target - arr[i];  // Calculate the complement needed

        // Check if the complement is already in the map
        if (m.count(comp)) {
            // If found, return the indices (index of complement, current index)
            return {m[comp], i};
        }

        // Store the current value with its index in the map
        m[arr[i]] = i;
    }

    // If no such pair is found, return {-1, -1}
    return {-1, -1};
}

int main() {
    vector<int> arr = {1, 2, 7, 10, 11, 15};
    int target = 9;
    pair<int, int> index = pairSum(arr, target);

    cout << "Index : " << index.first << "," << index.second << endl;

    return 0;
}