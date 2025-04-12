/*
📌 Pointer Arithmetic in C++

Pointer arithmetic allows us to move through elements in memory using pointers.
It works based on the size of the data type the pointer is pointing to.
For example, if int is 4 bytes:
→ ptr + 1 will move 4 bytes ahead (i.e., next int).
*/

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // ptr points to the first element of the array (arr[0])
    int n = sizeof(arr)/sizeof(int);

    // Accessing elements using pointer
    cout << *ptr << endl;       // Output: 10 → dereferencing ptr gives value at index 0

    // Adding a constant to a pointer moves it to the next element
    cout << *(ptr + 1) << endl; // Output: 20 → moves to index 1 (ptr now points to arr[1])
    cout << *(ptr + 2) << endl; // Output: 30 → moves to index 2

    // Loop to print all elements of the array using pointer arithmetic
    for (int i = 0; i < n; i++) {
    cout << *(arr + i) << " "; // *(arr + i) accesses the element at index i (just like arr[i]) when we add i it shifts the 
    // index with each iterations.
    } cout << endl; // Moves to the next line after printing all elements

    // Another way: use pointer like an array
    cout << ptr[3] << endl;     // Output: 40 → same as *(ptr + 3)

    // We can move the pointer itself
    ptr++;                      // Now ptr points to arr[1]
    cout << *ptr << endl;       // Output: 20

    ptr += 2;                   // Now ptr points to arr[3]
    cout << *ptr << endl;       // Output: 40

    // Pointer subtraction (distance between two addresses in terms of elements)
    int* start = arr;           // start points to arr[0]
    int* end = arr + 4;         // end points to arr[4]

    // Subtracting pointers gives the number of elements between them
    int diff = end - start;
    cout << "Elements between arr[0] and arr[4]: " << diff << endl; // Output: 4

    // Address demonstration
    cout << "Address of arr[0]: " << &arr[0] << endl;
    cout << "Value of ptr:      " << ptr << endl;

    return 0;
}

/*
Quick Notes for Revision:

- *(ptr + i) → Access element at index i
- ptr++ / ptr-- → Move pointer to next/previous element
- ptr[i] → Same as *(ptr + i), treat pointer like an array
- ptr1 - ptr2 → Gives number of elements between two pointers
- &arr[i] == ptr + i → True, both give same address
- arr++ (Not allowed) → Array name is a constant pointer
- *ptr → Value stored at the address the pointer is pointing to

REMEMBER:
- Pointer arithmetic works based on data type size.
- This concept is useful in arrays, dynamic memory, and working with functions.
*/