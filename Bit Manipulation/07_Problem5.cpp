/*
Problem Statement: Problem: Check if a Number is a Power of 2

Given an integer 'n', determine whether it is a power of 2.
Return true if it is, otherwise return false.

A number is a power of 2 if it has exactly one bit set in its binary representation.

Example:
Input:
n = 8
Output:
true

Explanation:
8 in binary is 1000, which has only one set bit. So it is a power of 2.
*/

#include<iostream>
using namespace std;

// Function to check if a number is a power of 2
bool powerOf2(int n){
    // (n & (n - 1)) removes the lowest set bit
    // If the result is 0 and n is not 0, then n has only one set bit
    if (n != 0 && (n & (n - 1)) == 0){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (powerOf2(n)){
        cout << n << " is a power of 2\n";
    } else {
        cout << n << " is NOT a power of 2\n";
    }
    return 0;
}

/*
Logic:
- A power of 2 has exactly one '1' in its binary representation.
  Examples:
    1  → 0001
    2  → 0010
    4  → 0100
    8  → 1000

- When we subtract 1 from a power of 2:
  - It flips the only set bit to 0
  - And turns all bits to its right into 1s

  Example:
    n     = 8  → 1000
    n - 1 = 7  → 0111
    -----------------
    n & (n - 1) = 0000  → This means only one bit was set

- So, if (n & (n - 1)) == 0 and n != 0 → n is a power of 2
*/


