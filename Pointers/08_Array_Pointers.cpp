#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << arr << endl;  // Prints the memory address of the first element (index 0).
    cout << *arr << endl; // Dereferences 'arr' to print the value at index 0 (i.e., 1).

    /*
    Note:
    - 'arr' is a special pointer (constant pointer) that stores the address of the first element (index 0).
    - Since 'arr' is a constant pointer, its memory address cannot be changed.
    */

    // Example: Trying to change 'arr' to point to another memory location
    int a = 10;
    // arr = &a;  // ERROR: 'arr' is a constant pointer and cannot be modified.

    return 0;
}