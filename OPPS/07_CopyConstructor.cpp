/*
 COPY CONSTRUCTOR:
 A copy constructor is a special constructor in a class used to create a new object
 that is a copy of an existing object. The copy constructor is invoked when:
 - A new object is created from an existing object (e.g., passing an object by value to a function).
 - An object is returned from a function by value.
 - When an object is explicitly copied using the assignment operator.
 
 Syntax:
 ClassName (const ClassName &object) {
     // Code to copy the data from 'object' to the new object
 }
 
 This ensures that the new object is a copy of the original, with all member variables 
 properly copied over. The default copy constructor performs a shallow copy (i.e., only copies 
 the values of primitive data types and references). A deep copy might be needed for complex types 
 like dynamic arrays, pointers, etc.

 NOTE: Special Constructor (default) used to copy properties of one object into another.
 */


#include<iostream>
#include<string>
using namespace std;

class Car {
    public:
        string name;
        string colour;

        // ORIGINAL CONSTRUCTOR
        Car(string carName, string carColour){
            name = carName;
            colour = carColour;
        }

        // CUSTOM COPY CONSTRUCTOR
        Car (Car &c1){
            cout << "Copying.." << endl;
            name = c1.name;
            colour = c1.colour;
        }

};

int main(){

    Car c1("BMW","White");

    // COPY CONSTRUCTOR
    Car c2(c1); // This invokes the copy constructor to create a new object (c2) as a copy of c1. 

    cout << c2.name << endl; // OUTPUT => BMW
    cout << c2.colour << endl; // OUTPUT => White

    return 0;
}