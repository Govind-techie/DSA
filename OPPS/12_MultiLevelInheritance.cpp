/*
    MULTILEVEL INHERITANCE IN C++

    - Multilevel inheritance refers to a class derived from another derived class.
    - It forms a chain-like hierarchy.

    Structure:
        BaseClass → DerivedClass1 → DerivedClass2

    - The last derived class inherits properties and behaviors from all its parent classes.

    Real-life Analogy:
    - Animal: Base class with general traits like name and behaviors like eat and breathe.
    - Fish: Inherits from Animal, adds traits like fins and behaviors like swim.
    - Shark: Inherits from Fish, adds traits like sharpTeeth and behaviors like hunt.

    Syntax:
        class A {
            // base class members
        };

        class B : public A {
            // derived from A
        };

        class C : public B {
            // derived from B (also inherits from A)
        };

    Key Concepts:
    - Public inheritance retains public and protected access.
    - Private members are not directly accessible in derived classes.
    - Constructor calls follow base → derived order.
    - Destructor calls follow reverse: derived → base.

    This program demonstrates multilevel inheritance using:
        Animal → Fish → Shark
*/

#include<iostream>
#include<string>
using namespace std;

// Base class - Animal
// Defines general properties and behaviors common to all animals.
class Animal {
    public:
        string name;    // Name of the animal
        string colour;  // Colour of the animal

        // Method representing the animal's eating behavior
        void eat() {
            cout << "Eating..." << endl;
        }

        // Method representing the animal's breathing behavior
        void breathe() {
            cout << "Breathing..." << endl;
        }
};

// Intermediate class - Fish
// Inherits from Animal and adds fish-specific characteristics.
class Fish : public Animal {
    public:
        int fins;  // Number of fins the fish has

        // Method representing the fish's swimming behavior
        void swim() {
            cout << "Swimming..." << endl;
        }
};

// Derived class - Shark
// Inherits from Fish and adds shark-specific traits.
class Shark : public Fish {
    public:
        int sharpTeeth;  // Number of sharp teeth the shark has

        // Method representing the shark's hunting behavior
        void hunt() {
            cout << "Hunting with sharp teeth..." << endl;
        }
};

int main() {
    // Create an instance of Shark, which inherits properties from Fish and Animal
    Shark s1;  // Create an object of Shark which inherits from Fish and Animal

    // Inherited from Animal
    s1.name = "Great White";   // Setting the name of the shark
    s1.colour = "Grey";        // Setting the colour of the shark

    // Inherited from Fish
    s1.fins = 5;               // Setting the number of fins

    // Specific to Shark
    s1.sharpTeeth = 300;       // Setting the number of sharp teeth

    // Displaying all properties of the shark object
    cout << "Name: " << s1.name << endl;
    cout << "Colour: " << s1.colour << endl;
    cout << "Fins: " << s1.fins << endl;
    cout << "Teeth: " << s1.sharpTeeth << endl;

    s1.eat();     // Calling inherited method from Animal class
    s1.breathe(); // Calling inherited method from Animal class
    s1.swim();    // Calling inherited method from Fish class
    s1.hunt();    // Calling method defined in Shark class

    return 0; 
}

// Multilevel inheritance: Shark → Fish → Animal