/*
Problem: Friend Pairing Problem (Goldman Sachs)

Description:
- You are given n friends. Each friend can either remain single or be paired with another friend.
- Your task is to find the total number of ways in which these n friends can remain single or be paired up.

Example:
Input: n = 3
Output: 4
Explanation:
- There are 4 ways for 3 friends:
  1. All three friends remain single: {1}, {2}, {3}.
  2. Friend 1 pairs with Friend 2, and Friend 3 remains single: {1, 2}, {3}.
  3. Friend 1 pairs with Friend 3, and Friend 2 remains single: {1, 3}, {2}.
  4. Friend 2 pairs with Friend 3, and Friend 1 remains single: {2, 3}, {1}.

Constraints:
- Assume n >= 1.

Note:
- This problem is frequently asked in technical interviews at companies like Goldman Sachs.
*/

#include<iostream>
using namespace std;

int friendPairing(int n) {
    // Base cases:
    // If there are no friends, there are 0 ways to pair them
    if (n == 0) return 0;
    
    // If there is only 1 friend, they can only remain single
    if (n == 1) return 1;
    
    // If there are 2 friends, they can either remain single or pair up
    if (n == 2) return 2;
    
    // Recursive case:
    // 1. The first friend remains single: friendPairing(n-1)
    // 2. The first friend pairs with any of the (n-1) remaining friends: (n-1) * friendPairing(n-2)
    return friendPairing(n-1) + (n-1) * friendPairing(n-2);
}

int main() {
    // Input: Number of friends
    int n;
    cout << "Enter the number of friends: ";
    cin >> n;
    
    // Output: Total number of ways to pair the friends
    cout << "Total number of ways to pair " << n << " friends: " << friendPairing(n) << endl;
    
    return 0;
}

/*
Recurrence Relation:

The recurrence relation for the Friend Pairing Problem is:
friendPairing(n) = friendPairing(n-1) + (n-1) * friendPairing(n-2)

Explanation:
1. friendPairing(n-1):
   - This represents the case where the first friend remains single.
   - The problem then reduces to finding the number of ways to pair the remaining n-1 friends.

2. (n-1) * friendPairing(n-2):
   - This represents the case where the first friend pairs with any of the remaining n-1 friends.
   - After pairing the first friend, the problem reduces to finding the number of ways to pair the remaining n-2 friends.
   - Since the first friend can pair with any of the n-1 friends, we multiply by (n-1).

Combining these two cases gives the total number of ways to pair n friends:
friendPairing(n) = friendPairing(n-1) + (n-1) * friendPairing(n-2)

Example Walkthrough:
Input: n = 4
friendPairing(4) = friendPairing(3) + 3 * friendPairing(2)
friendPairing(3) = friendPairing(2) + 2 * friendPairing(1)
friendPairing(2) = 2 (base case)
friendPairing(1) = 1 (base case)

Substitute values:
friendPairing(3) = 2 + 2 * 1 = 4
friendPairing(4) = 4 + 3 * 2 = 10

Thus, the total number of ways to pair 4 friends is 10.
*/