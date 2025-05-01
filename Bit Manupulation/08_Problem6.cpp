/*
Problem: Update the i-th Bit

Given an integer 'n', a bit position 'i', and a binary value 'val' (0 or 1),
update the i-th bit of 'n' to the given value.

Return the new number with the updated bit.

Bit positions are 0-indexed from the right.

Example 1:
Input: n = 5, i = 1, val = 1
Output: 7
Explanation: 5 = 0101 → set 1st bit → 0111 = 7

Example 2:
Input: n = 7, i = 2, val = 0
Output: 3
Explanation: 7 = 0111 → clear 2nd bit → 0011 = 3
*/

#include<iostream>
using namespace std;

int updateBit(int n , int i , int val){

    // Step 1: Create a bitmask with 0 at the i-th position and 1s elsewhere
    int bitMask = ~(1 << i);

    // Step 2: Clear the i-th bit of n by ANDing with bitMask
    n = (n & bitMask); // clear ith bit.

    // Step 3: Shift 'val' to the i-th position and OR it with n to set the bit
    return n | (val << i);
}

int main(){
    int n,i,val;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter a position: ";
    cin >> i;

    cout << "Enter value as 0 or 1: ";
    cin >> val;

    cout << updateBit(n,i,val) << endl;
    return 0;
}

/*
Logic:
To update the i-th bit of a number 'n' with a value 'val' (0 or 1):

1. Clear the i-th bit of n using:
   n & ~(1 << i)
   This ensures the bit at position i is 0.

2. Set the i-th bit to 'val' by:
   val << i
   This places the value at the correct position.

3. Combine both steps with OR:
   (n & ~(1 << i)) | (val << i)

This guarantees that the i-th bit becomes exactly what you want, whether 0 or 1.
*/