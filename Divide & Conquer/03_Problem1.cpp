/*
LeetCode Problem: 33. Search in Rotated Sorted Array
Difficulty: Medium

DESCRIPTION:

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

#include<iostream>
#include<vector>
using namespace std;

/*
The binarySearch function performs a modified binary search on the rotated sorted array.
It determines whether the target lies in the left or right half of the array and recursively searches in the appropriate half.
*/
int binarySearch(vector<int>& arr, int target, int stIdx , int enIdx) {
    if (stIdx > enIdx) return -1; // Base case: If the range is invalid, the target is not found.

    int mid = stIdx + (enIdx - stIdx) / 2; // Calculate the middle index to avoid overflow.

    if (arr[mid] == target) return mid; // If the middle element is the target, return its index.

    // Check if the left half is sorted
    if (arr[stIdx] <= arr[mid]) { 
        // If the target lies within the sorted left half, search in the left half.
        if (arr[stIdx] <= target && target < arr[mid]) {
            return binarySearch(arr, target, stIdx, mid - 1);
        } else { 
            // Otherwise, search in the right half.
            return binarySearch(arr, target, mid + 1, enIdx);
        }
    } else { 
        // If the left half is not sorted, the right half must be sorted.
        if (arr[mid] < target && target <= arr[enIdx]) {
            // If the target lies within the sorted right half, search in the right half.
            return binarySearch(arr, target, mid + 1, enIdx);
        } else {
            // Otherwise, search in the left half.
            return binarySearch(arr, target, stIdx, mid - 1);
        }
    }
}

/*
The search function is the entry point for searching the target in the rotated sorted array.
It calls the binarySearch function with the full range of the array.
*/
int search(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size() - 1);
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int target = 2; // Target to search for
    cout << search(arr, target) << endl; // Output the index of the target (or -1 if not found)
    return 0;
}