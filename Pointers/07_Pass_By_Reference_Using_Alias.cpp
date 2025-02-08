// Pass-by-Reference Using Alias: Passing by reference using an alias (reference) means using an '&' in the function parameter. This allows direct modification of the original variable without using pointers.

#include <iostream>
using namespace std;

// Function to modify the value of 'a' using a reference (alias)
void changeA(int &b) { // // 'b' becomes an alias for the original variable, not a copy
    b = 20; // Directly modifies the original variable
}

int main() {
    int a = 10;

    changeA(a); // Pass 'a' directly because the function expects a reference, not a pointer.

    cout << "Value inside main function: " << a << endl; // Output: 20

    return 0;
}