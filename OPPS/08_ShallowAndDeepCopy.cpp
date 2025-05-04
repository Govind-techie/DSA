/*
    SHALLOW AND DEEP COPY

    In Object-Oriented Programming, when we copy one object to another, two types of copy mechanisms are used:
    
    1. Shallow Copy: 
        - A shallow copy creates a new object but doesn't create copies of objects that the original object references. 
        - Instead, it copies the references to those objects, meaning both the original and the copied object point to the same memory location for reference-type members.
        - Downside: If the referenced objects are modified, both the original and copied object are affected.

    2. Deep Copy:
        - A deep copy creates a new object and also makes copies of the objects that the original object references.
        - The original object and the copied object are completely independent, so modifying one object does not affect the other.
        - Downside: It is more memory-intensive and slower, as it involves creating new instances of referenced objects.

    Key Points:
    - Shallow Copy: Simple and faster but shares references.
    - Deep Copy: Safer and independent but more resource-heavy.

    When to Use:
    - Use Shallow Copy when you want to save memory and both objects should share common references.
    - Use Deep Copy when you want to ensure complete independence between the objects and avoid unintentional side effects.

    Example of Shallow and Deep Copy in C++:
    - Shallow copy is usually done via the default copy constructor.
    - For deep copy, you need to manually implement a copy constructor that creates independent copies of referenced objects.

    NOTE:

    -> Shallow copy copies references to original array. But array remains same.
    -> Deep copy created a brand new copy of the array.

    -> Compiler generally creates a shallow copy for array.

    -> We need to define own copy constructor when deep copy is needed i.e. when class contains pointers to dynamically allocated memory.
*/

#include<iostream>
#include<string>
using namespace std;

class Car {
    public:
        string name;
        string colour;
        int* mileage;

        // ORIGINAL CONSTRUCTOR
        Car(string carName, string carColour){
            name = carName;
            colour = carColour;
            mileage = new int;
            *mileage = 12;
        }

        // CUSTOM COPY CONSTRUCTOR (Shallow Copy -> Points at same memory)
        // Creates a new object, but copies the address of 'mileage'.
        // Both objects point to the same memory — changes in one affect the other.
    
        Car (Car &c1){
            cout << "Copying.." << endl;
            name = c1.name;
            colour = c1.colour;
            mileage = c1.mileage; // This performs a shallow copy: both objects will share the same memory address for 'mileage'.
            // Any change to 'mileage' through one object will affect the other, since they point to the same memory location.
        }

        // CUSTOM COPY CONSTRUCTOR (Deep Copy -> allocates separate memory)
        // Allocates separate memory for 'mileage' and copies the value.
        // Ensures both objects are fully independent.
        
        Car (Car &c1){
            cout << "Deep copying..." << endl;
            name = c1.name;
            colour = c1.colour;
            mileage = new int; // Allocates new memory on the heap
            *mileage = *c1.mileage; // Copies the value from c1's mileage to the new memory
        }

};

int main(){
    Car c1 ("BMW","White");

    Car c2(c1);
    cout << c2.name << endl; // Output: BMW
    cout << c2.colour << endl; // Output: White
    cout << *c2.mileage << endl; // Output: 12

    *c2.mileage = 10; // Changing c2's mileage won't affect c1 if using deep copy, as they have separate memory.

    cout << "After modifying c2.mileage:" << endl;
    cout << "c1.mileage = " << *c1.mileage << endl;
    cout << "c2.mileage = " << *c2.mileage << endl;

    // NOTE: The compiler-generated default copy constructor performs a shallow copy.
    // It copies pointer addresses, not the data they point to.

    return 0;
}

/*
SHALLOW COPY:
- In a shallow copy, the copied object points to the same memory address in the heap as the original.
- This means changes in one object will reflect in the other since both share the same resource.

Diagram:
c1.mileage ──┐
             ▼
           [ 12 ] ←── Shared memory in heap
c2.mileage ──┘

DEEP COPY:
- In a deep copy, a new memory block is allocated and the same value is copied over.
- The objects become completely independent.

Diagram:
c1.mileage ──▶ [ 12 ]   ← Separate memory
c2.mileage ──▶ [ 12 ]   ← Different address with same value
*/

