/*
    HIERARCHICAL INHERITANCE IN C++

    ➤ Definition:
      Hierarchical inheritance occurs when multiple derived (child) classes inherit from a single base (parent) class.
      Each child gets access to the base class's members and can also define its own unique features.

    ➤ Structure:
                BaseClass
               /        \
        DerivedClass1  DerivedClass2

    ➤ Real-world Analogy:
      - Animal: Defines general traits like "eat" and "breathe".
      - Fish: Inherits from Animal and adds the ability to "swim".
      - Bird: Inherits from Animal and adds the ability to "fly".

    ➤ Key Points:
      - Promotes reusability and clearer structure.
      - Derived classes get only public and protected members of the base class.
      - Base class constructor is always called before derived class constructor.

    ➤ Demonstration:
      - Animal is the base class.
      - Fish and Bird are derived classes with their own behaviors.
*/

#include <iostream>
using namespace std;

// Base class - Animal
// Defines general behaviors common to all animals.
class Animal {
public:
    // Common behavior for all animals
    void eat() {
        cout << "This animal eats food." << endl;
    }

    // Common behavior for all animals
    void breathe() {
        cout << "This animal breathes air." << endl;
    }
};

// Derived class - Fish
// Inherits from Animal and adds swimming ability.
class Fish : public Animal {
public:
    // Unique behavior for Fish
    void swim() {
        cout << "This fish can swim." << endl;
    }
};

// Derived class - Bird
// Inherits from Animal and adds flying ability.
class Bird : public Animal {
public:
    // Unique behavior for Bird
    void fly() {
        cout << "This bird can fly." << endl;
    }
};

int main() {
    // Create and demonstrate Fish object
    Fish fish;
    cout << "Fish behaviors:" << endl;

    // Inherited from Animal
    fish.eat();
    fish.breathe();

    // Unique to Fish
    fish.swim();

    cout << endl;

    // Create and demonstrate Bird object
    Bird bird;
    cout << "Bird behaviors:" << endl;

    // Inherited from Animal
    bird.eat();
    bird.breathe();

    // Unique to Bird
    bird.fly();

    return 0;
}

// Hierarchical inheritance: Fish and Bird share common traits from Animal