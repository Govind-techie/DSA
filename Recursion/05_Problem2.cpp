/*
Problem: Calculate the sum of n natural numbers using recursion.
*/

#include<iostream>
using namespace std;

// Recursive function to calculate the sum of n natural numbers
int sum(int n) {
    if (n == 1) return 1; // Base case: When n is 1, the sum is 1 (stopping condition)
    return n + sum(n - 1); // Recursive case: Add n to the sum of numbers from 1 to (n-1)
}

int main() {
    // Call the recursive function with n = 5 and print the result
    cout << "Sum = " << sum(5) << endl; // Output: Sum = 15
    return 0; // Exit the program
}