/*
    SINGLE INHERITANCE IN C++

    - Single inheritance means a derived class inherits from a single base class.
    - It allows reusability of code and promotes a hierarchical classification.
    - Syntax:
        class DerivedClass : accessSpecifier BaseClass {
            // Members of DerivedClass
        };

    Example:
        A "Fish" class inherits from an "Animal" class.
        - Animal is the base (general) class.
        - Fish is the derived (specific) class.

    Access Specifier Rules:
    - public inheritance:
        Base class's public members → remain public in derived class
        Base class's protected members → remain protected
    - private and protected members of base class are not accessible directly in the derived class

    Advantages:
    - Promotes code reuse
    - Models real-world relationships
*/

#include<iostream>
#include<string>
using namespace std;

// Base class - Animal
// Represents general characteristics and behaviors of animals
class Animal {
    private:
        int age = 2;  // Private member, not accessible in derived class
    public:
        string name;     // Animal's name
        string colour;   // Animal's color

        // Method to simulate eating behavior
        void eat(){
            cout << "Eating..." << endl;
        }

        // Method to simulate breathing behavior
        void breathe(){
            cout << "Breathing..." << endl;
        }
};

// Derived class - Fish
// Inherits properties and methods from Animal
class Fish : public Animal {
    public:
        int fins;  // Additional property specific to Fish

        // Method to simulate swimming behavior
        void swim(){
            cout << "Swimming..." << endl;
        }
};

int main(){
    Fish f1;
    f1.fins = 3;

    // Set properties inherited from Animal
    f1.name = "Goldfish";     // Inherited property
    f1.colour = "Blue";       // Inherited property

    // f1.age = 5; // Error: 'age' is private in base class Animal

    // Output values
    cout << "Name: " << f1.name << endl;
    cout << "Fins: " << f1.fins << endl;
    cout << "Colour: " << f1.colour << endl;

    // cout << "Accessing name using this->: " << f1.this->name << endl; // also valid

    // Call inherited and own methods
    f1.swim();      // Fish class method
    f1.eat();       // Inherited from Animal
    f1.breathe();   // Inherited from Animal

    // Demonstrating inheritance of methods

    return 0;
}
