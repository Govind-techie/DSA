/*
    INHERITANCE IN C++
    
    - Inheritance is a fundamental concept in Object-Oriented Programming (OOP) where one class (derived class) acquires the properties and behaviors (methods) of another class (base class).
    
    Key Points:
    - The derived class inherits members (data and methods) from the base class, but can also have its own members.
    - Inheritance helps in code reuse and logical hierarchy. For example, a "Car" class can be a base class, and "BMW" can be a derived class that inherits from it.
    - In C++, inheritance is established using the `:` operator.
    
    Types of Inheritance:
    1. Single Inheritance: A class inherits from one base class.
    2. Multiple Inheritance: A class inherits from more than one base class.
    3. Multilevel Inheritance: A class inherits from a base class, and another class inherits from the derived class.
    4. Hierarchical Inheritance: Multiple classes inherit from a single base class.
    5. Hybrid Inheritance: Combination of two or more types of inheritance.
    
    Syntax:
    class DerivedClass : accessSpecifier BaseClass {
        // Derived class members
        };
        
        Access Specifiers in Inheritance:
        - `public`: Members of the base class remain accessible as public members in the derived class.
        - `protected`: Members of the base class are accessible as protected members in the derived class.
        - `private`: Members of the base class are inaccessible in the derived class.
        
        Example:
        - The derived class can call base class methods using the `BaseClass::method()` syntax, but it can also override them or add its own unique behavior.
        
        Destructor in Inheritance:
        - When a derived class object is deleted, the destructor of the derived class is called first, followed by the destructor of the base class.
        - The base class destructor should be virtual if you are working with pointers to ensure proper cleanup.
            
        MODE OF INHERITANCE
        
        Inheritance in C++ can be classified based on the visibility of the inherited members from the base class. 
        The mode of inheritance determines how the members of the base class are treated in the derived class:
        
        1. Public Inheritance:
            - In this mode, all public members of the base class are accessible as public members of the derived class, and all protected members of the base class are accessible as protected members in the derived class. Private members of the base class remain inaccessible.
            - This is the most common mode of inheritance and is used when the derived class "is a" type of the base class.
            
        2. Protected Inheritance:
            - In this mode, all public and protected members of the base class are inherited as protected members in the derived class. Private members of the base class remain inaccessible.
            - This mode is used when the derived class needs to restrict access to the inherited members.
            
        3. Private Inheritance:
            - In this mode, all public and protected members of the base class are inherited as private members in the derived class. Private members of the base class remain inaccessible.
            - This mode is used when the derived class needs to hide the base class interface completely.
        */

#include<iostream>
#include<string>
using namespace std;

// Base class - Animal
// The Animal class represents a generic animal with common properties and behaviors.
class Animal {
    public:
        string name;  // The name of the animal
        string colour;  // The color of the animal
        
        // Method to simulate eating behavior of the animal
        void eat(){
            cout << "Eating..." << endl;  // Output to indicate the animal is eating
        }

        // Method to simulate breathing behavior of the animal
        void breathe(){
            cout << "Breathing..." << endl;  // Output to indicate the animal is breathing
        }
};

// Derived class - Fish, inherits from Animal
// The Fish class represents a specific type of animal (Fish) and extends the Animal class.
class Fish : public Animal {
    public:
        int fins;  // The number of fins of the fish

        // Method to simulate swimming behavior specific to Fish
        void swim(){
            cout << "Swimming..." << endl;  // Output to indicate the fish is swimming
        }
};

int main(){
    Fish f1;  // Creating an object of the Fish class
    f1.fins = 3;
    cout << f1.fins << endl;  // Output => 3

    f1.swim();  // Swim method specific to the Fish class
    f1.eat(); // Inherited eat method from the Animal class
    f1.breathe(); // Inherited breathe method from the Animal class
    
    f1.colour = "Blue"; // Inherited colour property for the fish object
    cout << f1.colour << endl;  // Output => Blue

    return 0;
}