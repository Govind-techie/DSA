// Null Pointer : Null pointer is a pointer that doesn't point at any memory (address/location).

#include<iostream>
using namespace std;

int main(){
    int* pointer1;
    cout << pointer1 << endl; // It will return a (random/garbage) memory location which we didn't assign to the ponter. Output : 0x1eb8740a0 (garbage address).

    int* pointer2 = NULL; // It represent a null pointer which means pointer is not storing any random value and the value assign to it is null.
    cout<< pointer2 << endl; // Output : 0x0 (NULL MEMORY ADDRESS).

    cout << *pointer1 << endl; // If we dereference a pointer with garbage address it will return a garbage value stored at that memory location.

    // cout << *pointer2 << endl; // Throws an error : Segmentation fault.
    // Note : We cannot dereference a null pointer as it is not pointing at a specific memory location where some value is stored.

    return 0;
}
