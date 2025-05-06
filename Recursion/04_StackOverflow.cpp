/*
Stack Overflow in Recursion

- Stack overflow occurs when the call stack exceeds its memory limit.
- Common causes:
  1. Infinite recursion (no base case).
  2. Excessively deep recursion (large input without optimization).

Example: Demonstrating stack overflow with infinite recursion.
*/

#include<iostream>
using namespace std;

// Recursive function without a base case cause infinite recursion
void infiniteRecursion() {
    cout << "Calling function..." << endl;
    infiniteRecursion(); // Recursive call with no stopping condition
}

int main() {
    // This will cause a stack overflow
    infiniteRecursion(); // The program will keep running until a stack overflow or segmentation fault occurs.
    return 0;
}

/*
Expected Behavior:
- The function `infiniteRecursion()` will keep calling itself indefinitely.
- Each recursive call adds a new frame to the call stack.
- Eventually, the call stack exceeds its memory limit, causing a stack overflow or segmentation fault.

Key Takeaway:
- Always include a base case in recursive functions to prevent infinite recursion.
- Properly handle recursion depth to avoid stack overflow for large inputs.
*/