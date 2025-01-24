// O(n!) Time Complexity:  O(n!) means the time it takes grows factorially with the input size, often seen in problems involving permutations, combinations, or backtracking.

// Graph of O(n!):
// Number of Operations
//   ^
//   |
//   |          *
//   |         *
//   |        *
//   |       *
//   |      *
//   |     *
//   |    *
//   |   *
//   | *
//   +---------------------------------------------------> Input size (n)

// Example: Generating Permutations (Recursive)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to print a permutation
void printPermutation(const vector<int>& permutation) {
    for (int num : permutation)
        cout << num << " ";
    cout << endl;
}

// Recursive function to generate all permutations
void generatePermutations(vector<int>& nums, int start) {
    // Base case: If we reach the end of the array, print the permutation
    if (start == nums.size()) {
        printPermutation(nums);
        return;
    }

    // Recursive case: Swap the current element with each subsequent element
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);                // Swap to create a new permutation
        generatePermutations(nums, start + 1);    // Recursive call for the next index
        swap(nums[start], nums[i]);                // Backtrack to restore original order
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Initialize the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    // Generate all permutations
    cout << "All permutations of the array:" << endl;
    generatePermutations(nums, 0);

    return 0;
}

// Time Complexity Explanation:
// - The function generates all permutations of the array, which is n! (factorial of n).
// - At each recursive level, the function makes multiple swaps and recursive calls, 
//   resulting in (n * (n-1) * (n-2) * ... * 1) operations.
// - Hence, the time complexity is O(n!), as the number of operations grows factorially 
//   with the input size.