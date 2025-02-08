// Dereference Operator (*) : Dereference Operator is used to fetch a value stored at specific memory address.

#include <iostream>
using namespace std;

int main() {
    int a = 10;  

    // Printing the value stored at the memory address of 'a' using the dereference operator
    cout << "Value stored at memory address " << &a << " is: " << *(&a) << endl;

    // Declaring a pointer that stores the address of 'a'
    int* pointer = &a;

    // Accessing the value using the pointer
    cout << "Value accessed using pointer: " << *pointer << endl; // Output : 10 

    // Using a pointer to a pointer (double pointer)
    cout << "Value accessed using pointer to pointer: " << **(&pointer) << endl; // Output : 10 {Double Dereference (**)}

    // Printing the memory address stored in 'pointer' (which is the address of 'a')
    cout << "Memory address of variable 'a' accessed via pointer: " << *(&pointer) << endl; // Output : 0x16b9cb1e8 {memory address of variable (a)}

    return 0;
}