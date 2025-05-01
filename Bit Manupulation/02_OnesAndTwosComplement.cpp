/*
1's Complement:
- 1's complement of a binary number is formed by flipping all the bits:
  - 0 becomes 1
  - 1 becomes 0
- It is an older method for representing negative numbers in binary.
- The range of numbers represented using 1's complement is not symmetrical (there are two representations of zero: +0 and -0).

Example:
Positive 5 = 00000101 (8-bit)
1's complement of 5 = 11111010

2's Complement:
- 2's complement is the modern and most widely used method for representing signed integers in binary.
- To get the 2's complement:
  1. Take the 1's complement (flip the bits)
  2. Add 1 to the result
- It allows easier arithmetic operations using the same hardware circuits for both positive and negative numbers.
- Only one representation for 0.

Example:
Positive 5 = 00000101
1's complement of 5 = 11111010
Add 1 => 11111010 + 1 = 11111011
2's complement = 11111011 => -5 in decimal

Most Significant Bit (MSB):
- The MSB is the leftmost bit in a binary number.
- In 2's complement representation, it indicates the sign of the number:
  - MSB = 0 means the number is positive
  - MSB = 1 means the number is negative
- For example:
  01111111 = +127 (MSB is 0)
  10000001 = -127 (MSB is 1)
- MSB helps distinguish between positive and negative numbers in signed binary representations.

Summary:
- 1's complement: flip all bits
- 2's complement: flip all bits, then add 1
- MSB: used to determine the sign in signed binary numbers

*/

#include <iostream>
using namespace std;

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
}

int main() {
    int num = 5;

    cout << "Original number (5) in binary:    ";
    printBinary(num);
    cout << endl;

    cout << "1's Complement of 5:              ";
    printBinary(~num);
    cout << " (Decimal: " << ~num << ")" << endl;

    int onesComp = ~num;
    int twosComp = onesComp + 1;
    cout << "2's Complement of 5:              ";
    printBinary(twosComp);
    cout << " (Decimal: " << twosComp << ")" << endl;

    int pos = 127;
    int neg = -127;
    cout << "Positive number 127 in binary:    ";
    printBinary(pos);
    cout << " (MSB: " << ((pos >> 7) & 1) << ")" << endl;

    cout << "Negative number -127 in binary:   ";
    printBinary(neg);
    cout << " (MSB: " << ((neg >> 7) & 1) << ")" << endl;

    return 0;
}
