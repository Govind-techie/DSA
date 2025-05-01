/*
Problem: Clear the i-th Bit

Given an integer 'n' and a bit position 'i', clear (set to 0) the i-th bit of 'n'
and return the new number. Bit positions are 0-indexed from the right.

Clearing a bit means forcing it to 0, regardless of its previous state.

Example:
Input:
n = 7  (Binary: 0111)
i = 1

Output:
5 (Binary: 0101)

Explanation:
The 1st bit of 7 is 1. Clearing it results in binary 0101, which is 5 in decimal.
*/

#include<iostream>
using namespace std;

// Function to clear the i-th bit of number 'n'
int clearBit(int n, int i) {
    // Create a bitmask with all bits 1 except the i-th bit as 0
    // Example: if i = 1 → bitmask = ~(1 << 1) = 11111101
    int bitMask = ~(1 << i);
    // Use bitwise AND to clear the i-th bit
    return (n & bitMask);
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter bit position: ";
    cin >> i;

    int result = clearBit(n, i);
    cout << "Result after clearing the " << i << " bit: " << result << endl;

    return 0;
}

/*
Logic:
- To clear the i-th bit of a number:
    1. Create a mask with all bits set to 1 except the i-th bit: ~(1 << i)
    2. AND the original number with this mask: n & ~(1 << i)
       - This sets the i-th bit to 0, all other bits remain unchanged.

Example:
n = 7 (Binary: 0111)
i = 1

Step 1: 1 << 1 = 00000010
Step 2: ~(00000010) = 11111101
Step 3: 0111 & 11111101 = 0101 → 5

So, the new number with the 1st bit cleared is 5.
*/