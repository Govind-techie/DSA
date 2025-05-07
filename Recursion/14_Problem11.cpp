/*
Problem: Binary Strings Without Consecutive 1s (Paytm)

Description:
- Given a number n, print all binary strings of length n such that there are no consecutive 1s in the string.

Example:
Input: n = 3
Output:
- The binary strings of length 3 without consecutive 1s are:
  1. 000
  2. 001
  3. 010
  4. 100
  5. 101

Constraints:
- Assume n >= 1.

Note:
- This problem is frequently asked in technical interviews at companies like Paytm.
*/

#include<iostream>
#include<string>
using namespace std;

// Recursive function to generate binary strings without consecutive 1s
void BinaryStrings(int n, int lastPlace, string ans) {
    // Base Case: If the length of the string becomes 0, print the result
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    // Add '0' to the string and recurse
    BinaryStrings(n - 1, 0, ans + "0");
    
    // Add '1' to the string and recurse only if the last place is not '1'
    if (lastPlace != 1) {
        BinaryStrings(n - 1, 1, ans + "1");
    }

}

int main() {
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;

    cout << "The binary strings of length " << n << " without consecutive 1s are:" << endl;
    BinaryStrings(n, 0, ""); // Start with an empty string and lastPlace = 0

    return 0;
}

/*
Explanation of the Problem:
- The goal is to print all binary strings of length n such that there are no consecutive 1s.

Approach:
1. Base Case:
   - If n == 0, print the current string and return.

2. Recursive Case:
   - Add '0' to the string and recurse for the remaining length (n-1).
   - Add '1' to the string and recurse for the remaining length (n-1) only if the last digit is not '1'.

Example Walkthrough:
- Input: n = 3
- Output:
  000
  001
  010
  100
  101

Complexity:
1. Time Complexity: O(2^n) because each recursive call branches into two.
2. Space Complexity: O(n) due to the recursion stack.
*/