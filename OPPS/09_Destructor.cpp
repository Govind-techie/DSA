/*
    DESTRUCTOR IN C++

    - A destructor is a special member function that is automatically called when an object goes out of scope or is deleted.
    - It is used to free resources that were allocated to the object (like memory, files, network connections etc).
    - In C++, the destructor has the same name as the class but is preceded by a tilde (~).

    Syntax:
    ~ClassName() {
        // cleanup code
    }

    Key Points:
    - A class can have only one destructor.
    - It cannot be overloaded or take any parameters.
    - If you don't define a destructor, the compiler provides a default one.
    - Especially important when your class uses dynamic memory (like new).

    Example Use:
    - Releasing heap memory allocated via new.
    - Closing files or database connections when object is destroyed.

    Note:
    - Destructor is automatically called in reverse order of construction when an object goes out of scope, especially in the case of multiple objects or local variables.
*/

#include<iostream>
#include<string>
using namespace std;

class Car {
    public:
        string name;
        string colour;
        int* mileage;

        // Constructor to initialize car with a name, colour, and mileage.
        // Allocates memory for 'mileage' on the heap.
        Car(string carName, string carColour){
            name = carName;
            colour = carColour;
            mileage = new int;  // Dynamically allocate memory for mileage
            *mileage = 12;      // Initialize mileage with 12
            cout << "Car " << name << " created!" << endl;
        }

        // Copy constructor (deep copy): Allocates new memory for 'mileage',
        // and copies the value from the original object.
        // This ensures that both objects have their own independent memory for 'mileage'.
        Car (const Car &c1){
            cout << "Deep copying..." << endl;
            name = c1.name;
            colour = c1.colour;
            mileage = new int;   // Allocate new memory for mileage
            *mileage = *c1.mileage;  // Copy the value of mileage from c1
        }

        // Destructor: Automatically called when the object goes out of scope or is deleted.
        // It deallocates the dynamically allocated memory for 'mileage' to prevent memory leaks.
        // Using 'delete' ensures that memory allocated with 'new' is properly freed when the object is destroyed.
        ~Car(){
            cout << "Object deletion.." << endl;

            // Ensure 'mileage' points to valid memory before deallocating to avoid potential issues.
            if (mileage != nullptr){
                delete mileage;  // Free the memory allocated for 'mileage'
                mileage = NULL;  // Set 'mileage' to NULL to avoid dangling pointer issues (ensure it's not used after deletion).
                cout << "Destructor called for " << name << ". Memory deallocated." << endl;
            }
        }
};

int main(){
    Car c1 ("BMW", "White");  // Create object c1

    // Create object c2 by copying c1 using the deep copy constructor
    Car c2(c1);

    cout << c2.name << endl;   // Output: BMW
    cout << c2.colour << endl; // Output: White
    cout << *c2.mileage << endl;  // Output: 12

    *c2.mileage = 10;  // Change c2's mileage

    // Display mileage for both c1 and c2 after modification
    cout << "After modifying c2.mileage:" << endl;
    cout << "c1.mileage = " << *c1.mileage << endl;  // c1's mileage (independent memory)
    cout << "c2.mileage = " << *c2.mileage << endl;  // c2's mileage (modified)

    // NOTE: Destructor will be called for both c1 and c2 when they go out of scope at the end of main.
    return 0;
}