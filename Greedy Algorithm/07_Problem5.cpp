/*
Indian Coins Problem

Problem Statement:
Given a value V and an array of Indian coin denominations, find the minimum number of coins needed to make the value V. You can use as many coins of each denomination as needed.

Input:
- An array of coin denominations (for example: {1, 2, 5, 10, 20, 50, 100, 500, 2000})
- A value V

Output:
- Minimum number of coins needed to make value V

Example:
Input:
coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000}
V = 93

Output:
5

Explanation:
Coins used: 50, 20, 20, 2, 1 (total 5 coins)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to find the minimum number of coins needed to make the value V
int indianCoins(vector<int>coins , int V){
    int n = coins.size(); // Number of different coin denominations

    // Sort the coin denominations in ascending order.
    // This is important for the greedy approach to work.
    sort(coins.begin() , coins.end()); // (NOTE => For this problem we have considered the array is not sorted though it depends on problem to problem)

    int count = 0; // Initialize the count of coins used

    // Iterate through the coin denominations from largest to smallest
    for (int i = n-1 ; i >= 0 && V > 0 ; i--){
        // Check if the current coin denomination can be used (is less than or equal to the remaining value V)
        if(coins[i] <= V){
            // Use as many of the current coin as possible
            count += V / coins[i];  // Add the number of coins used
            V %= coins[i];       // Update the remaining value V
        }
    }
    return count; // Return the total number of coins used
}

int main(){
    // Example coin denominations
    vector<int>coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 1099; // The value we want to make using the coins

    cout << indianCoins(coins,V) << endl; // Output the result
    return 0;
}

/*
Greedy Approach:

1. Sort the coin denominations in ascending order.
2. Start from the largest coin and move towards the smallest.
3. For each coin:
   - While the coin value is less than or equal to V:
     - Subtract the coin value from V
     - Increment the coin count
4. Repeat until V becomes 0.
5. Return the total coin count.

Example:
Let V = 93 and available coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000}

Step-by-step:
- Use 50 (93 - 50 = 43) ➝ count = 1
- Use 20 (43 - 20 = 23) ➝ count = 2
- Use 20 (23 - 20 = 3) ➝ count = 3
- Use 2  (3 - 2 = 1)   ➝ count = 4
- Use 1  (1 - 1 = 0)   ➝ count = 5

Total coins used = 5 → [50, 20, 20, 2, 1]
*/