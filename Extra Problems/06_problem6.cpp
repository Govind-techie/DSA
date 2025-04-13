/*
Problem Statement: Maximum Subarray Sum

Given an array of integers (which may include positive, negative, or zero values), find the contiguous subarray (a portion of the array with consecutive elements) that has the largest sum and return that sum. If the array is empty, return 0.

Example:

Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4] Output: 6 (The subarray [4, -1, 2, 1] has the largest sum).
Input: [1] Output: 1
Input: [-1, -2, -3] Output: -1 (The subarray [-1] has the largest sum).
Input: [] Output: 0
Constraints:

The array can contain both positive and negative integers.
The array length is at least 0.
A single element is considered a valid subarray.
*/

#include <iostream>
#include <climits>
using namespace std;

// BRUTE FORCE: O(n³) approach
int maxSubarraySum1(int arr[], int n) {
    // Check for empty array: return 0 as per problem requirement
    if (n == 0) return 0;

    // Initialize maximum sum to smallest possible integer to handle negative sums
    int maxSum = INT_MIN;

    // Outer loop: iterate through all possible start indices (i)
    for (int i = 0; i < n; i++) {
        // Middle loop: iterate through all possible end indices (j) from i
        for (int j = i; j < n; j++) {
            // Initialize current subarray sum for range [i..j]
            int currSum = 0;
            // Inner loop: sum elements from index i to j
            for (int k = i; k <= j; k++) {
                currSum += arr[k];
            }
            // Update maxSum if current subarray sum is larger
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    
    return maxSum;
}

// OPTIMIZED: O(n²) approach
int maxSubarraySum2(int arr[], int n) {
    // Check for empty array: return 0 as per problem requirement
    if (n == 0) return 0;

    // Initialize maximum sum to smallest possible integer to handle negative sums
    int maxSum = INT_MIN;
    
    
    for (int i = 0; i < n; i++) {
        // Initialize running sum for subarrays to 0 at loop starting.
        int currSum = 0;
        // Inner loop: iterate through end indices (j) from i
        for (int j = i; j < n; j++) {
            // Add the next element to the running sum (extends subarray to j)
            currSum += arr[j];
            // Update maxSum if current subarray sum is larger
            maxSum = max(currSum, maxSum); // Max function is used to find the maximum value between 2 values and return max value.
        }
    }
    return maxSum;
}

int maxSubarraySum3(int arr[] , int n){
    int maxSum = INT_MIN;
    int currSum = 0;
    if (n == 0) return 0;

    for (int i = 0 ; i < n ; i++){
        currSum += arr[i];
        maxSum = max(currSum,maxSum);

        if (currSum < 0){
            currSum = 0;
        }

    }
    return maxSum;
}



int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    cout << "Maximum subarray sum = " << maxSubarraySum1(arr,n) << endl;
    cout << "Maximum subarray sum = " << maxSubarraySum2(arr,n) << endl;
    cout << "Maximum subarray sum = " << maxSubarraySum3(arr,n) << endl;
    return 0;
}