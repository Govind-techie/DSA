#include<iostream>
using namespace std;

// Function to check if a number is odd or even using bitwise operator
void oddOrEven(int n) {
    // Using bitwise AND with 1 to check the Least Significant Bit (LSB) or right most bit
    // If LSB is 1 => odd number, else => even number
    if ((n & 1) == 1) {
        cout << n << " is an odd number" << endl;
    } else {
        cout << n << " is an even number" << endl;
    }
}

int main() {
    // Problem: Check whether a number is odd or even using bitwise operator.
    int n;
    cout << "Enter a number: ";
    cin >> n;
    oddOrEven(n);
    return 0;
}

/*
Logic:
- The Least Significant Bit (LSB) determines if a number is odd or even.
- In binary:
    - Even numbers end in 0 (LSB = 0)
    - Odd numbers end in 1 (LSB = 1)

Example:
Entered number: 3
Binary of 3 = 011
n & 1 = 011 & 001
        -------
          001 => 1 (non-zero result means odd)

Thus, n & 1:
- Returns 1 if the number is odd
- Returns 0 if the number is even
*/