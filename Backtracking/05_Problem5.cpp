/*
Problem Statement: Grid Ways Problem

Given a grid of size `m x n`, you are initially positioned at the top-left corner of the grid (0, 0). 
Your goal is to reach the bottom-right corner of the grid (m-1, n-1). 
You can only move either down or right at any point in time.

Write a program to calculate the total number of unique ways to reach the bottom-right corner of the grid.

Example:
Input: m = 3, n = 3
Output: 6

Explanation:
For a 3x3 grid, the possible paths are:
1. Right -> Right -> Down -> Down
2. Right -> Down -> Right -> Down
3. Right -> Down -> Down -> Right
4. Down -> Right -> Right -> Down
5. Down -> Right -> Down -> Right
6. Down -> Down -> Right -> Right

Note:
- The grid dimensions `m` and `n` will be positive integers.
- The output should be the total number of unique paths.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Function to calculate the number of ways to reach the bottom-right corner (m-1, n-1)
int gridWays(int i, int j, int m, int n , string ans) {
    // Base Case: If we have reached the bottom-right corner, return 1 (found a valid path)
    if (i == m - 1 && j == n - 1){
        cout << ans << endl;
        return 1;
    }

    // Boundary Case: If we go out of bounds (i >= m or j >= n), return 0 (invalid path)
    if (i >= m || j >= n) return 0;

    // Recursive Case: Move either right (i, j+1) or down (i+1, j)
    // Add the number of ways to reach the destination from both right and down directions
    return gridWays(i + 1, j, m, n, ans + "R") + gridWays(i, j + 1, m, n, ans+ "D"); 
}

int main() {
    // Define the grid dimensions m x n (3x3 in this case)
    int m = 3, n = 3;

    string ans = "";

    // Call the gridWays function to calculate the number of unique paths from top-left (0, 0) to bottom-right (m-1, n-1)
    int count = gridWays(0, 0, m, n,ans);
    
    // Output the total number of ways to reach the bottom-right corner of the grid
    cout << "No. of ways possible : " << count << endl;

    return 0;
}

// Time Complexity -> O(2^(n+m))
