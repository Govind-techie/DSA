/*
Problem: Get the i-th Bit

Given an integer 'n' and a bit position 'i', determine whether the i-th bit of 'n' is 1 or 0.
Bit positions are 0-indexed from the right (LSB = 0th bit).

This operation is commonly used in bitmasking, toggling, or checking specific binary flags.

Example:
Input:
n = 3  (Binary: 011)
i = 1

Output:
1

Explanation:
The 1st bit of 3 is 1 (counting from right, 0-based).
*/
#include<iostream>
using namespace std;

// Function to get the value of the i-th bit of number n
void getBit(int n, int i) {
    // Right shift n by i to bring the i-th bit to the LSB position
    // AND it with 1 to isolate that bit
    // If result is 1 => i-th bit is set, else => i-th bit is 0
    cout << "The " << i << " bit of " << n << " is: " << ((n >> i) & 1) << endl;
}

int main() {
    // Problem: Get the value of the i-th bit of a number using bitwise operator.
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter bit position: ";
    cin >> i;

    getBit(n, i);
    return 0;
}

/*
Logic:
- To get the i-th bit of a number:
    1. Right shift the number n by i positions: n >> i
       - This moves the i-th bit to the least significant bit (LSB) position.
    2. AND the result with 1: (n >> i) & 1
       - This gives 1 if the i-th bit was set (1), or 0 if it was not.

Example:
n = 3 (Binary: 011)
i = 1

Step 1: 011 >> 1 = 001
Step 2: 0001 & 0001 = 0001 → Result = 1

So, the 1st bit of 3 is 1.
*/