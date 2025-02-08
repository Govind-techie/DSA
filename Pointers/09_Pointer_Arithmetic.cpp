#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int* ptr1 = &a;
    int* ptr2 = &a;
    int* ptr3 = &a;
    int* ptr4 = &a;

    // Increment in Pointers: Increasing a pointer moves it to the next memory location based on the data type size.

    cout << ptr1 <<endl;
    ptr1++;
    cout << ptr1 <<endl; // => 0x16dd3f248 + 4 (integer space 4 bytes) = 0x16dd3f24c
    cout << *ptr1 << endl; // Undefined behavior: accessing memory outside 'a' returns garbage value.
    
    
    // Decrement in Pointers: Decreasing a pointer moves it to the previous memory location based on the data type size.
    
    cout << ptr2 <<endl;
    ptr2--;
    cout << ptr2 <<endl; // => 0x16dd3f248 - 4 (integer space 4 bytes) = 0x16d4e3244
    cout << *ptr2 << endl; // Undefined behavior: accessing memory outside 'a' returns garbage value.
    
    // Note: Incrementing or decrementing a pointer changes the memory address stored in the pointer (by moving to the next or previous 
    // memory location based on the data type size) but does not modify the value stored at that address.
    
    // Note: Pointer increment and decrement depend on the data type and the memory size it occupies.
    

    // Addition on Pointers: Adding a value to a pointer moves it forward in memory by that value multiplied by the size of the data type. 
    // It changes the pointer’s address but not the actual stored value.

    cout << ptr3 <<endl;
    ptr3 = (ptr3 + 2); // => 0x16dd3f248 + 2 int (2 integer space 8 bytes) = 0x16b27b250
    cout << ptr3 <<endl; 
    cout << *ptr3 << endl; // Undefined behavior: accessing memory outside 'a' returns garbage value.


    // Subtraction on Pointers: Subtracting a value from a pointer moves it backward in memory by that value multiplied by the data type
    // size, changing the pointer’s address but not the stored value.

    cout << ptr3 << endl;
    ptr3 = (ptr3 - 2); // => 0x16dd3f248 - 2 int (2 integer space 8 bytes) = 0x16b27b240
    cout << ptr3 << endl; 
    cout << *ptr3 << endl; // Undefined behavior: accessing memory outside 'a' returns garbage value.

    // Use Cases in Arrays :

    int arr[] = {1, 2, 3, 4, 5};

    cout << arr << endl;  // Prints the memory address of the first element (index 0).
    cout << *(arr) << endl; // Output : 1
    cout << *(arr + 1) << endl; // It increases the value by 1 integer space. Output : 2
    cout << *(arr + 2) << endl; // It increases the value by 2 integer space. Output : 3
    cout << *(arr + 3) << endl; // It increases the value by 3 integer space. Output : 4
    cout << *(arr + 4) << endl; // It increases the value by 4 integer space. Output : 5

    // Note: In an integer array, each index differs by 4 bytes, so incrementing the pointer (arr) moves to the next element.


    // Subtratction (pointer to pointer) : In subtraction of pointer to pointer we can get the amount of space present between 2 memory address of 2 pointers.

    int* pointer1;
    int* pointer2 = pointer1 + 2;

    cout << pointer2 - pointer1 << endl; // It will return answer in total integer space left which is 2

    // Comparison (pointer to pointer) : In pointer to pointer comparison we compare the memory addresses of 2 pointer by using relational operators

    int* p1;
    int* p2;

    p1 = p2;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << (p1 > p2) << endl; // We are comparing the memory address of 2 pointers. Output : 0 (false)
    cout << (p1 == p2) << endl; // Output : 1 (true)

    // Note : We can apply any relational operator.

    return 0;
}