/*
Problem: Clear the Last i Bits

Given an integer 'n' and a number 'i', clear the last 'i' bits of 'n'.
Return the updated number after clearing the last 'i' bits.

Example:
Input: n = 29, i = 3
Output: 24

Explanation:
29 = 11101 in binary. After clearing the last 3 bits, we get 24 (11000 in binary).
*/

#include<iostream>
using namespace std;


// Function to clear the last i bits of a number 'n'
int clearlastBits(int n, int i){
    // Create a mask to clear the last 'i' bits by shifting ~0 to the right by 'i' positions
    return n & (~0 >> i);  // Efficiently clears the last 'i' bits using the mask
}

int main(){
    int n, i;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter the number of bits to clear: ";
    cin >> i;

    // Output the updated number after clearing the last 'i' bits
    cout << "Updated number after clearing last " << i << " bits: " << clearlastBits(n, i) << endl;

    return 0;
}

/*
Logic:
- To clear the last 'i' bits of a number:
    1. First, create a mask that keeps the upper bits of the number and sets the last 'i' bits to 0.
       - This is done by shifting `~0` (which is all 1s) to the right by 'i' positions: `~0 >> i`
    2. Use the AND operation to apply the mask to the number, clearing the last 'i' bits.
       - `n & (~0 >> i)` clears the last 'i' bits of 'n' and preserves the other bits.

    Example:
    n = 29 (Binary: 11101)
    i = 3

    Step 1: ~0 = 11111111, 11111111 >> 3 = 11111000 (mask)
    Step 2: n & mask = 11101 & 11111000 = 11000 (result is 24)

    Result: 24 (Binary: 11000)
*/