// LeetCode Problem (53) : Maximum Subarray (medium).

// arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}

// Output: 6
// Explanation: The subarray [4, -1, 2, 1] has the largest sum, which is 6.

// Kadane Algorithm : Kadane’s Algorithm is a dynamic programming approach to find the maximum sum of a contiguous subarray in linear time,
// by iterating through the array while updating the current sum and the maximum sum encountered.

// Kadane's Algorithm Time Complexity : O(n)

#include<iostream>
using namespace std;

int maxSum(int arr[], int n) {
    int maxSum = INT_MIN;          // Initialize maxSum to 0 (handles all-negative arrays)
    int currentSum = 0;      // Start with a sum of 0 for the current subarray

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];  // Add the current element to currentSum
        maxSum = max(currentSum, maxSum);  // Update maxSum if currentSum is larger
        if (currentSum < 0) {  // Reset currentSum to 0 if it becomes negative
            currentSum = 0;
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {3,-4,5,4,-1,7,-8};
    int n = sizeof(arr)/sizeof(int);

    cout<<"The maximum subarray sum is : "<<maxSum(arr,n)<<endl;
    return 0;
}