// O(2^n) Time Complexity: O(2^n) means the time it takes grows exponentially with the input size, often due to recursion where each function call generates multiple subproblems 

// (e.g., in the Fibonacci sequence).

// Graph of O(2^n):
// Number of Operations
//   ^
//   |
//   |            *    
//   |           *    
//   |          *  
//   |         *  
//   |        *  
//   |       *  
//   |      *  
//   |    *  
//   | *  
//   +---------------------------------------------------> Input size (n)

// Example: Fibonacci Sequence (Recursive)

#include<iostream>
using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    // Base case: Fibonacci of 0 is 0, and Fibonacci of 1 is 1
    if (n <= 1)
        return n;

    // Recursive case: Fibonacci of n is the sum of Fibonacci of (n-1) and (n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter a number to find the Fibonacci number: ";
    cin >> n;

    // Call the recursive function and display the result
    cout << "Fibonacci of " << n << " is : " << fibonacci(n) << endl;

    return 0;
}

// Time Complexity Explanation:
// - Each recursive call to `fibonacci(n)` generates two further calls: 
//   `fibonacci(n-1)` and `fibonacci(n-2)`.
// - This creates a binary recursion tree, where the number of calls doubles 
//   with each increase in n, leading to exponential growth. Hence, the time 
//   complexity is O(2^n).