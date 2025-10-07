/*
  Abstraction in C++

  ➤ Definition:
    Abstraction is the process of hiding complex internal details and showing only the necessary features of an object.
    It simplifies the interface for the user and reduces complexity.

  ➤ Real-world analogy:
    Think of a car: You use a steering wheel, accelerator, and brakes to drive it.
    You don’t need to know how the engine works or how the fuel gets to the engine.

  ➤ In programming:
    You can use classes and access specifiers to implement abstraction.
    - Public members: accessible to users
    - Private members: hidden implementation details

  ➤ Benefits of Abstraction:
    - Reduces code complexity
    - Increases reusability
    - Improves maintainability
    - Enhances security by exposing only essentials

  ➤ C++ Implementation:
    - Use access specifiers (`private`, `protected`, `public`).
    - Use abstract classes (with pure virtual functions) for full abstraction.
*/


#include<iostream>
#include<string>
using namespace std;

/*
Abstract Classes
• Abstract classes are used to provide a base class from which other classes can be derived.
• They cannot be instantiated and are meant to be inherited.
• Abstract classes are typically used to define an interface for derived classes.

NOTE: Abstract classes should have atleast 1 pure virtual function.
*/

/*
Pure Virtual Function:
A pure virtual function (or abstract function) is a virtual function with no definition/ logic.
It is declared by assigning O at the time of declaration.
*/

// Abstract Class 'Shape' is created as it contains at least one pure virtual function.
// This class provides an interface for all shapes to implement their own 'draw()' method.
class Shape{
  public:
    // Pure virtual function: Must be overridden in derived classes.
    // It enforces the contract that all derived shapes must define 'draw()'.
    virtual void draw() = 0; // => Pure virtual function (Abstract function)
};

// 'Circle' class inherits from 'Shape' and provides a specific implementation of 'draw()'.
// Since it implements all pure virtual functions, 'Circle' is a concrete class.
class Circle : public Shape { // => Abstract class is shape which is inherited by circle class.
  public:
    // Overriding the pure virtual function of base class to define how Circle is drawn.
    void draw(){
      cout << "Drawing Circle..." << endl;
    }
};

// 'Square' class also inherits from 'Shape' and defines its version of 'draw()'.
class Square : public Shape { // => Abstract class is shape which is inherited by square class.
  public:
    // Overriding the pure virtual function to provide Square-specific drawing logic.
    void draw(){
      cout << "Drawing Square..." << endl;
    }
};


int main(){

  Circle c1;
  c1.draw();

  Square sq1;
  sq1.draw();
  
  // Since Shape is an abstract class, we cannot create its object directly.
  // We can only use it as a base class reference or pointer.
    return 0;
}