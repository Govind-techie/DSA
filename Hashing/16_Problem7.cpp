/*
Problem: Largest Subarray with Sum Zero

Given an array of integers, find the length of the largest subarray whose sum is zero.

Input:
- An array of integers (can contain positive, negative, and zero values)

Output:
- An integer representing the length of the largest subarray with sum zero

Example:
Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The subarray [-2, 2, -8, 1, 7] has sum zero and length 5.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Function to find the length of the longest subarray with sum 0
int maxSubarray(vector<int>& arr) {
    unordered_map<int, int> m; // Map to store the first occurrence of each prefix sum
    int sum = 0;               // Variable to store the running (prefix) sum
    int maxLen = 0;            // To keep track of the maximum length found

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Add current element to prefix sum

        // Case 1: If sum becomes 0, subarray from index 0 to i has sum 0
        if (sum == 0) {
            maxLen = i + 1; // Length = i + 1 (from 0 to i)
        }

        // Case 2: If this sum has been seen before, we found a subarray with sum 0
        if (m.count(sum)) {
            int currLen = i - m[sum]; // Length between previous index and current
            maxLen = max(maxLen, currLen); // Update maxLen if this one is longer
        } else {
            // Store the first occurrence of this sum
            m[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxSubarray(arr) << endl; // Output: 5 (for subarray: -2, 2, -8, 1, 7)
    return 0;
}