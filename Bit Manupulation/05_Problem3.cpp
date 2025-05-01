/*
Problem: Set the i-th Bit

Given an integer 'n' and a bit position 'i', set the i-th bit of 'n' to 1 
and return the new number. Bit positions are 0-indexed from the right.

This operation ensures that the bit at position 'i' becomes 1 regardless of its previous state.

Example:
Input:
n = 5  (Binary: 0101)
i = 1

Output:
7 (Binary: 0111)

Explanation:
The 1st bit of 5 is 0. Setting it to 1 results in binary 0111, which is 7 in decimal.
*/

#include<iostream>
using namespace std;

// Function to set the i-th bit of number 'n' to 1
void setBit(int n , int i){
    // Create a bitmask with 1 at i-th position
    // Example: if i = 1 → 00000010
    int bitMask = 1 << i;

    // Use bitwise OR to set the i-th bit
    // If i-th bit is 0, it becomes 1
    // If i-th bit is already 1, it remains 1
    int result = n | bitMask;

    // Output the result
    cout << "Result after setting the " << i << " bit: " << result << endl;
}

int main(){
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter bit position: ";
    cin >> i;

    // Call the setBit function
    setBit(n, i);

    return 0;
}

/*
Logic:
- To set the i-th bit of a number to 1:
    1. Create a bitmask with only the i-th bit set: (1 << i)
       Example: if i = 2 → bitmask = 00000100
    2. Perform bitwise OR with the original number: n | bitmask
       - If the i-th bit in 'n' is 0, it becomes 1.
       - If the i-th bit is already 1, it stays 1.

Example:
n = 5 (Binary: 0101)
i = 1

Step 1: bitmask = 1 << 1 = 00000010
Step 2: n | bitmask = 0101 | 0010 = 0111 → 7

So, the new number with the 1st bit set is 7.
*/