// Maximum Subarray Sum : Given an array of integers (both positive and negative), find the maximum sum of a contiguous subarray.

// Input:
// arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}

// Output: 6
// Explanation: The subarray [4, -1, 2, 1] has the largest sum, which is 6.

// Brute Force Approach : A brute force approach is a straightforward method to solve a problem by trying all possible solutions and selecting the best one. 

// Brute Force Time Complexity : O(n²)

#include<iostream>
using namespace std;

int maxSum(int arr[], int n){
    int maxSum = INT_MIN; // Initialize with a very small value.
    for(int st = 0 ; st < n ; st++){ 
        int currentSum = 0; // Start with sum 0 for each subarray.
        for(int end = st ; end < n ; end++){
            currentSum += arr[end]; // Add the current element to the sum.
            maxSum = max(currentSum , maxSum); // Update maxSum if currentSum is larger.
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