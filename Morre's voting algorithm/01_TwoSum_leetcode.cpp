// Leetcode Problem : 1. Two Sum (Easy)

// Description:

// Given an array of integers nums and a target integer target, find two numbers in the array that add up to the target. Return the indices of these two numbers.

// Each input will have exactly one solution, and you cannot use the same element twice.

// Example 1:

// Input:
// nums = [2, 7, 11, 15], target = 9

// Output:
// [0, 1]

// Explanation:
// The numbers at indices 0 and 1, 2 and 7, add up to 9, so we return [0, 1].

// Example 2:

// Input:
// nums = [3, 2, 4], target = 6

// Output:
// [1, 2]

#include<iostream>
#include<vector>
using namespace std;

// Function to find two indices whose sum equals the target
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    // Loop through each element and check for pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the sum of the current pair equals the target
            if (nums[i] + nums[j] == target) {
                return {i, j};  // Return the pair of indices
            }
        }
    }
    return {};  // Return an empty vector if no solution is found
}

int main() {
    // Example input array and target
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the twoSum function and store the result
    vector<int> result = twoSum(nums, target);

    // Check if the result is not empty and print the indices
    if (!result.empty()) {
        for (int i : result) {
            cout << i << " ";  // Print each index in the result
        }
        cout << endl;
    } else {
        cout << "No solution found" << endl;  // If no solution, print this message
    }

    return 0;
}