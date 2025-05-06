/*
Problem: Find and print the Nth Fibonacci number using recursion.

Description:
- The Fibonacci sequence is defined as:
  F(0) = 0, F(1) = 1
  F(n) = F(n-1) + F(n-2) for n > 1 -> Recurrence relation
- Given an integer n, calculate and print the Nth Fibonacci number.
*/

#include<iostream>
using namespace std;

// Recursive function to calculate the Nth Fibonacci number
int fib(int n) {
    if (n == 0) return 0; // Base case: F(0) = 0
    if (n == 1) return 1; // Base case: F(1) = 1
    return fib(n - 1) + fib(n - 2); // Recursive case: F(n) = F(n-1) + F(n-2)
}

// NOTE -> In a recursive function it is possible to have 2 base case.

int main() {
    cout << fib(5) << endl; // Output: 5 (5th Fibonacci number)
    return 0;
}

/*
Recursion Tree for fib(5):

fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1) → 1 (Base case)
│   │   │   └── fib(0) → 0 (Base case)
│   │   └── fib(1) → 1 (Base case)
│   └── fib(2)
│       ├── fib(1) → 1 (Base case)
│       └── fib(0) → 0 (Base case)
└── fib(3)
    ├── fib(2)
    │   ├── fib(1) → 1 (Base case)
    │   └── fib(0) → 0 (Base case)
    └── fib(1) → 1 (Base case)

Result:
- fib(5) = fib(4) + fib(3)
- fib(4) = fib(3) + fib(2)
- fib(3) = fib(2) + fib(1)
- fib(2) = fib(1) + fib(0)

Final Calculation:
fib(5) = 5 (from fib(4)) + 3 (from fib(3)) = 8
*/