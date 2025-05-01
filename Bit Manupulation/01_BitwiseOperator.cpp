/*
Bitwise Operators:
Bitwise operators are used to perform operations at the binary level.
These operators work directly on the bits of integers and are commonly used
in low-level programming, optimization, and competitive coding.

Common bitwise operators include:
- AND (&)
- OR (|)
- XOR (^)
- NOT (~)
- Left Shift (<<)
- Right Shift (>>)
*/

#include<iostream>
using namespace std;

int main() {
    /*
    Bitwise AND (&) compares each bit of two numbers.
    It gives 1 only when both bits are 1.

    Bitwise AND rules:
    0 & 0 = 0
    0 & 1 = 0
    1 & 0 = 0
    1 & 1 = 1
    */

    /*
    Example: 3 & 5
    Convert 3 and 5 to binary:
        011
      & 101
      -----
        001 => 1 in decimal
    */

    cout << (3 & 5) << endl;  // Output: 1

    /*
    Bitwise OR (|) compares each bit of two numbers.
    It returns 1 if at least one of the corresponding bits is 1.

    Bitwise OR rules:
    0 | 0 = 0
    0 | 1 = 1
    1 | 0 = 1
    1 | 1 = 1
    */

    /*
    Example: 3 | 5
    Step 1: Convert to binary
    3 = 011
    5 = 101
    
        011
      | 101
      -----
        111 => 7 in decimal
    */

    cout << (3 | 5) << endl;  // Output: 7

    /*
    Bitwise XOR (^) compares each bit of two numbers.
    It returns 1 only if the corresponding bits are different.

    Bitwise XOR rules:
    0 ^ 0 = 0
    0 ^ 1 = 1
    1 ^ 0 = 1
    1 ^ 1 = 0
    */

    /*
    Example: 3 ^ 5
    Convert to binary:
    3 = 011
    5 = 101

        011
      ^ 101
      -----
        110 => 6 in decimal
    */

    cout << (3 ^ 5) << endl;  // Output: 6

    /*
    Bitwise NOT (~) flips all bits of a number.
    It changes 0 to 1 and 1 to 0.

    Example:
    If a number is 5 (binary: 00000101),
    ~5 will be (in binary): 11111010
    Note: This result is in 2's complement form (for negative numbers).

    For 32-bit integers:
    ~5 = -6
    */

    /*
    One's Complement:
    The NOT operator (~) inverts all the bits of a number, which is known as **One's Complement**. 
    It changes every 0 to 1 and every 1 to 0.

    Two's Complement:
    When working with signed integers in C++, the result of ~ (NOT) is interpreted using **Two's Complement** representation.
    - Two's Complement = One's Complement + 1
    - In Two's Complement, the leftmost bit (MSB) is used to indicate the sign:
        - 0 means positive
        - 1 means negative

    Example:
    Number: 5
    Step 1: 5 in 8-bit binary = 00000101
    Step 2: Apply ~ (One's Complement) => 11111010
    Step 3: Add 1 => 11111010 + 1 = 11111011

    Result: 11111011 (in Two's Complement) = -5 in decimal

    So, ~5 = -6 because:
    ~5 = One's Complement (11111010) → +1 → 11111011
    => This is -6 in decimal (based on Two's Complement interpretation)

    Note:
    The reason 11111011 is treated as a negative number is because the leftmost bit (MSB) is 1.
    In two's complement representation, an MSB of 1 indicates a negative number,
    and an MSB of 0 indicates a positive number.
    */

    cout << (~5) << endl;  // Output: -6

    /*
    Bitwise Left Shift (<<) shifts bits to the left and fills 0 on the right.
    Each left shift by 1 is equal to multiplying the number by 2.

    Example:
    3 << 1 means shift bits of 3 to the left by 1 position:
    3 = 00000011
    After shift = 00000110 => 6

    So, 3 << 1 = 6

    NOTE: Left Shift (<<) is the same as multiplying by 2^b → (a << b = a * 2^b)
    */

    cout << (3 << 1) << endl;  // Output: 6

    /*
    Bitwise Right Shift (>>) shifts bits to the right.
    Each right shift by 1 divides the number by 2 (ignoring remainder).

    Example:
    5 >> 1 means shift bits of 5 to the right by 1 position:
    5 = 00000101
    After shift = 00000010 => 2

    So, 5 >> 1 = 2
    NOTE: Right Shift (>>) is the same as dividing by 2^b → (a >> b = a / 2^b)
    */

    cout << (5 >> 1) << endl;  // Output: 2

    return 0;
}

