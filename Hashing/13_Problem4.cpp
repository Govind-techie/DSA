/*
Problem: Count Distinct Elements

Given an array of integers, count and return the number of distinct (unique) elements in the array.

Input:
- An array of integers

Output:
- An integer representing the number of distinct elements in the array.

Example:
Input: arr = [1, 2, 2, 3, 4, 4, 4]
Output: 4

Input: arr = [5, 5, 5, 5]
Output: 1
*/

#include<iostream>
#include<unordered_set>
using namespace std;

// Function to count the number of distinct elements in the vector
int countDistinct(vector<int>& nums) { // Time Complexity: O(n), Space Complexity: O(n)
    unordered_set<int> s; // Set to store unique elements
    for (int i : nums) s.insert(i); // Insert each element (duplicates ignored)
    return s.size(); // Return number of unique elements
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 4, 4, 4};
    cout << "count = " << countDistinct(nums) << endl;
    return 0;
}