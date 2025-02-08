// Pass-by-Reference Using Pointers: Passing by reference using pointers means passing the memory address of a variable to a function instead of its value. This allows the function to directly modify the original variable, as it accesses the same memory location.

#include <iostream>
using namespace std;

// Function to modify the value of 'a' using a pointer
void changeA(int *a) {
    *a = 20; // Dereferencing the pointer to modify the actual value stored at the address
}

int main() {
    int a = 10;

    changeA(&a); // Passing the address of 'a' to the function

    // The value of 'a' is modified because the function changes the actual memory location
    cout << "Value inside main function : " << a << endl; // Output : 20

    return 0;
}