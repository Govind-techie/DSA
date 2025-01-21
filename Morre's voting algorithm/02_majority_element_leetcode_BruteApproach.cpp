// Problem: 169. Majority Element (Easy)

// Description:

// Given an array of integers nums, find the majority element. The majority element is the element that appears more than n / 2 times, where n is the size of the array.

// You may assume that the array is non-empty and that the majority element always exists in the array.

// Example 1:

// Input:
// nums = [3, 2, 3]

// Output:
// 3

// Explanation:
// The majority element is 3, which appears more than n / 2 times in the array.

// Example 2:

// Input:
// nums = [2, 2, 1, 1, 1, 2, 2]

// Output:
// 2


// Brute Force Approach : The brute force approach checks each element in the array and counting its occurrences, then returning the element
// that appears more than n/2 times.

#include<iostream>
#include<vector>
using namespace std;

// Function to find the majority element
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    
    // Brute-force: Check every element and count its occurrences
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;  // Increment count if elements are equal
            }
        }
        if (count > n / 2) {
            return nums[i];  // Return the majority element
        }
    }
    
    return -1;  // If no majority element found, return -1
}

int main() {
    // Example input array
    vector<int> nums = {3, 2, 3};

    // Call the majorityElement function and print the result
    int result = majorityElement(nums);

    if (result != -1) {
        cout << "Majority Element: " << result << endl;  // Print the majority element
    } else {
        cout << "No majority element found" << endl;  // If no majority element, print this message
    }

    return 0;
}