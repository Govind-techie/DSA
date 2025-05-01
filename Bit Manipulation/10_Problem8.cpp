/*
Problem: Count the Number of Set Bits

Given an integer 'n', count and return the number of set bits (1s) in its binary representation.

Example:
Input: n = 7 (binary: 0111)
Output: 3 (There are three 1s in the binary representation of 7)
*/

#include<iostream>
using namespace std;

// Function to count the number of set bits (1s) in the binary representation of 'n'
int countSetBits(int n){
    int count = 0;

    // Loop through all bits of 'n'
    while (n > 0){
        count += n & 1;  // If the last bit is 1, increment the count
        n = n >> 1;    // Right shift 'n' to check the next bit
    }

    return count;  // Return the total count of set bits
}

int main(){
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of set bits: " << countSetBits(n) << endl;

    return 0;
}

/*
Logic:
- To count the number of set bits in a number:
    1. Use the bitwise AND operation (n & 1) to check if the last bit is 1.
    2. Right shift the number (n = n >> 1) to examine the next bit.
    3. Continue until all bits are processed (until 'n' becomes 0).
    
Example:
For n = 7 (binary 0111):
    Iteration 1: n & 1 = 1, sum = 1, n = 3
    Iteration 2: n & 1 = 1, sum = 2, n = 1
    Iteration 3: n & 1 = 1, sum = 3, n = 0
    Final result: 3 set bits in total
*/