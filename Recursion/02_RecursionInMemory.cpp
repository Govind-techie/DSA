/*
  RECURSION IN MEMORY:

  - Every recursive function call is stored in a stack (call stack).
  - When a function is called, memory is allocated in the stack for:
    -> Parameters
    -> Local variables
    -> Return address (to know where to return after function ends)
  - Each recursive call adds a new frame to the call stack.
  - Once the base case is reached, the function starts returning, and stack frames are removed one by one.
  - This stack grows with each recursive call and shrinks as functions return.
  - The Last In First Out (LIFO) nature of the stack is what makes recursion work.
  - Excessive recursion can lead to stack overflow if the base case is not reached or recursion is too deep.

  Example trace of recursion:
  - fun(3)
    └─ fun(2)
       └─ fun(1)
          └─ fun(0) ← base case reached
  - Now, returns happen in reverse:
    fun(0) returns to fun(1),
    fun(1) returns to fun(2),
    fun(2) returns to fun(3),
    and finally fun(3) completes.
*/

#include<iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial(0) = 1
    }
    return n * factorial(n - 1); // Recursive case: n * factorial(n-1)
}

int main() {
    int n = 5; 
    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    /*
      Explanation of recursion in memory for factorial(5):
      - Each recursive call pushes a new frame onto the call stack:
        factorial(5) → factorial(4) → factorial(3) → factorial(2) → factorial(1) → factorial(0) (base case)
      - Once the base case is reached (factorial(0) = 1), the stack starts unwinding:
        factorial(1) = 1 * 1 = 1
        factorial(2) = 2 * 1 = 2
        factorial(3) = 3 * 2 = 6
        factorial(4) = 4 * 6 = 24
        factorial(5) = 5 * 24 = 120
      - The stack grows during the recursive calls and shrinks as the function returns.

      Diagram of the call stack during recursion:
      
      Call Stack (grows downward):
      -------------------------
      | factorial(0) = 1      | ← Base case
      -------------------------
      | factorial(1) = 1 * 1  |
      -------------------------
      | factorial(2) = 2 * 1  |
      -------------------------
      | factorial(3) = 3 * 2  |
      -------------------------
      | factorial(4) = 4 * 6  |
      -------------------------
      | factorial(5) = 5 * 24 | ← Initial call
      -------------------------
    */

    return 0;
}