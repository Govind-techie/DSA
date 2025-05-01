/*
Problem: Fast Exponentiation (Exponentiation by Squaring)

Given an integer 'a' and an integer 'b', efficiently compute a^b (a raised to the power of b) using **Fast Exponentiation**.

Instead of computing powers linearly, we increase the power of 'a' exponentially and use the binary representation of 'b' to decide when to multiply the result.

Binary representation of 'b' guides the computation:
- Each bit represents whether to include the corresponding power of 'a'.

Example:
Compute 3^5
Binary of 5 = 101

We compute:
- 3^1 = 3 → (used because rightmost bit is 1)
- 3^2 = 9 → (skipped because middle bit is 0)
- 3^4 = 81 → (used because leftmost bit is 1)

Result = 3^1 * 3^4 = 3 * 81 = 243
*/

#include <iostream>
using namespace std;

// Function to compute a^b using fast exponentiation based on binary of b
int fastExponentiation(int a, int b) {
    int result = 1;

    while (b > 0) {
        // If the current bit of b is set (1), multiply result by current 'a'
        if (b & 1) {
            result *= a;  // Include this power of a
        }

        // Square a for the next bit (i.e., increase power exponentially)
        a *= a;

        // Shift b right by 1 to process the next bit
        b >>= 1;
    }

    return result;
}

int main() {
    int a, b;
    
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (b): ";
    cin >> b;
    
    cout << "Result of a^b: " << fastExponentiation(a, b) << endl;
    
    return 0;
}

/*
Logic:
- Use binary representation of b to compute a^b efficiently.
- Each bit in b determines whether to include the corresponding power of a in the result.
- a is squared each time as b is right shifted.

Example:
a = 3, b = 5
Binary of b = 101

Step-by-step:
b = 101 (binary)
- bit 0 (rightmost) = 1 → result *= 3 (3^1)
- bit 1 = 0 → skip multiplying result
- bit 2 = 1 → result *= 81 (3^4)

Final result = 3 * 81 = 243
*/
