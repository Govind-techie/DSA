// Pointers : Pointers are special variable that store addresses of other variable.

// Key Notes on Pointers:

// 	1.	Pointer Declaration (* Operator)
// 	•	We use the * (asterisk) operator to declare a pointer.
// 	•	A pointer stores the memory address of a variable.

// 	2.	Address-of Operator (&)
// 	•	We use the & (address-of operator) to get the memory address of a variable.

// 	3.	Pointer and Variable Must Have the Same Data Type
// 	•	Example: An int* pointer can only store the address of an int variable.

// 	4.	A Pointer Itself Has Its Own Memory Address
// 	•	The address of a pointer is different from the address it stores.

// 	5.	Pointer to Pointer (** Operator)
// 	•	A pointer can store the address of another pointer, which is called a double pointer.

#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int* pointer1 = &a; // We initailzed a pointer using (*) operator and store memory address of variable (a) using (&) operator.

    // Both datatype of variable a and pointer is same.

    float price = 99.99;
    float* pointer2 = &price; 

    // Pointer to Pointer : One pointer is used to store memory address of another pointer.
    int** pointer3 = &pointer1; // If we want to store a pointer address in another pointer we use (**) operator to initailize that pointer.

    // Here, too pointer3 have a different memory address.

    cout << pointer1 << endl;
    cout << pointer2 << endl;
    cout << &pointer1 << endl; // Prints memory address of pointer.
    return 0;
}
