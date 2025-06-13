/*
Subarray Sums to K

Given an array of integers and an integer k, find the total number of continuous subarrays whose sum equals k.

Input:
- An array of integers (can contain positive, negative, and zero values)
- An integer k (the target sum)

Output:
- An integer representing the number of subarrays whose sum is equal to k

Example:
Input: arr = [1, 2, 3], k = 3
Output: 2
Explanation: The subarrays [1, 2] and [3] both sum to 3.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> m;
    m[0] = 1;  // Initialize map with sum 0 to handle subarrays starting from index 0

    int sum = 0; // Running prefix sum
    int count = 0; // Total count of subarrays with sum equal to k

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];  // Update the running sum

        // Check if (sum - k) exists in the map
        // If it does, it means there's a subarray ending at index i with sum = k
        if (m.find(sum - k) != m.end()) {
            count += m[sum - k];  // Add the number of such subarrays to count
        }

        // Add/update the frequency of the current prefix sum in the map
        m[sum]++;
    }

    return count;
}

int main(){
    vector<int>arr= {1, 2, 3};
    int k = 3;
    cout << subarraySum(arr,k) << endl;
    return 0;
}