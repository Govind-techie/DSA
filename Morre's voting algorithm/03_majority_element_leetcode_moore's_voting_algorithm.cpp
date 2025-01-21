// Moore's Voting Algorithm : Moore’s Voting Algorithm is an efficient approach to find the majority element by iterating through the array
// and maintaining a candidate with a counter that is adjusted based on element comparisons.

#include<iostream>
#include<vector>
using namespace std;

// Function to find the majority element using Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int value = 0;  // Candidate for majority element
    int count = 0;  // Count to track occurrences of the candidate

    // Iterate through the array
    for(int i = 0; i < n; i++) {
        if (count == 0) {
            value = nums[i];  // Set new candidate
        }
        // If current element matches the candidate, increment count
        if (value == nums[i]) {
            count++;
        } else {
            count--;  // Decrement count if it's a different element
        }
    }

    return value;  // Return the majority element
}

int main() {
    vector<int> nums = {3, 2, 3};  // Example input array
    int result = majorityElement(nums);  // Call the function to find majority element

    cout << "Majority Element: " << result << endl;  // Print the majority element

    return 0;
}