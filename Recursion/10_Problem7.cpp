/*
Problem: Calculate and Print x raised to the power n using Recursion.

Description:
- Given two integers x (base) and n (exponent), calculate x^n (x raised to the power n) using recursion.
- Assume n >= 0.

Output: 8 (2^3 = 2 * 2 * 2)

Example:
Input: x = 2, n = 3
Approach:
- This implementation uses the divide-and-conquer strategy to calculate x^n efficiently in O(log n) time.
- Instead of reducing n by 1 in each recursive call (which would take O(n) time), we divide n by 2 in each step.
- By storing the result of the recursive call (halfPow), we avoid redundant computations, ensuring the function is efficient.

Efficiency:
- The recursion depth is proportional to the number of times n can be divided by 2, which is log(n).
- This makes the time complexity O(log n).
*/

#include<iostream>
using namespace std;

// Recursive function to calculate x^n
int power(int x, int n) {
    // Base case: Any number raised to the power 0 is 1
    if (n == 0) return 1;

    // Recursive case: Divide the problem into smaller subproblems
    int halfPow = power(x, n / 2); // Compute power(x, n/2) once and reuse it

    // If n is even, result is halfPow * halfPow
    if (n % 2 == 0) {
        return halfPow * halfPow;
    }
    // If n is odd, multiply an extra x
    return x * halfPow * halfPow;
}

int main() {
    int x, n;

    // Input the base value
    cout << "Enter a base value  : ";
    cin >> x;

    // Input the exponent value
    cout << "Enter an index value : ";
    cin >> n;

    cout << power(x, n) << endl;

    return 0;
}

/*
Recurrence relation:
- power(x, n) = power(x, n/2) * power(x, n/2) if n is even
- power(x, n) = x * power(x, n/2) * power(x, n/2) if n is odd
- Base case: power(x, 0) = 1

Efficiency:
- Each recursive call reduces n by half, resulting in a recursion depth of log(n).
- The result of power(x, n/2) is stored in a variable (halfPow) to avoid redundant computations.
- Time complexity: O(log n)
- Space complexity: O(log n) (due to the recursion stack)
*/