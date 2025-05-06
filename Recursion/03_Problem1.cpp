/*
Problem: Print numbers in decreasing order from n to 1
*/

#include<iostream>
using namespace std;

// Recursive function to print numbers in decreasing order
void print(int n) {
    if (n == 0) return; // Base case: Stop recursion when n reaches 0
    cout << n << " ";   // Print the current number
    print(n - 1);       // Recursive call with n-1
}

/*
Note => In recursion, the base case acts as the stopping condition,
similar to a loop, and ensures the function terminates without returning
a value when performing actions like printing.
*/


int main() {
    print(5); // Start printing numbers from 5 to 1.
    cout << endl; 
    return 0;
}

/*
Call Stack Diagram for print(5) -> (DRY RUN)

1. Initial call from main():
   print(5)
   -------------------------
   | print(5)             | ← Initial call
   -------------------------

2. Recursive calls (stack grows):
   -------------------------
   | print(0)             | ← Base case (stops recursion)
   -------------------------
   | print(1)             |
   -------------------------
   | print(2)             |
   -------------------------
   | print(3)             |
   -------------------------
   | print(4)             |
   -------------------------
   | print(5)             | ← Initial call
   -------------------------

3. Stack unwinds (returns in reverse order):
   - print(0) returns to print(1)
   - print(1) returns to print(2)
   - print(2) returns to print(3)
   - print(3) returns to print(4)
   - print(4) returns to print(5)
   - print(5) completes and returns to main()
*/