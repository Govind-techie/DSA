/*
RECURSION IN C++
Recursion is a process in which a function calls itself directly or indirectly.

Key Points:
1. Base Case: The condition under which the recursion ends.
2. Recursive Case: The part of the function where the recursion continues.

Example Explanation:
- Factorial of a number n (n!) is the product of all positive integers less than or equal to n.
- Recursive definition:
  factorial(n) = n * factorial(n-1)
  factorial(0) = 1 (base case)

Recurrence Relation:
- A recurrence relation expresses the value of a function in terms of its value at smaller inputs.
- For example, the factorial function has the recurrence relation:
  T(n) = T(n-1) + O(1)
- In general:
  T(n) = T(n - 1) + f(n) where f(n) is the work done at each step.
- Solving a recurrence helps determine the time complexity of recursive functions.

Notes:
- Every recursive function must have a base case to avoid infinite recursion.
- Recursive calls add a new layer to the call stack.
- After reaching the base case, the function returns and the stack unwinds.
*/

#include<iostream>
using namespace std;

/*
RECURSION -> It is a method of solving computational problems where the solution depends on solutions to smaller instances of the same problem.
*/

// Recursive Function: A function that calls itself is called a recursive function.
void func() {
    cout << "Function Call" << endl;
    func(); // The function calls itself repeatedly.
    // NOTE: Since there is no base case, this will lead to infinite recursion and eventually a segmentation fault (stack overflow).
}

int factorial(int n) {
    if (n == 0) return 1; // Base case: When n is 0, the recursion stops, and the result is 1.
    return n * factorial(n - 1); // Recursive case: Multiply n by the factorial of (n-1) until the base case is reached.
}

int main() {
    // func(); // Uncommenting this will cause a segmentation fault due to infinite recursion.

    cout << "Factorial = " << factorial(5) << endl; // OUTPUT: 120 (5! = 5 * 4 * 3 * 2 * 1)
    return 0;
}