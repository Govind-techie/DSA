/*
  CONSTRUCTOR (in C++):

  A constructor is a special member function of a class that is automatically called 
  when an object of the class is created. It has the same name as the class and does not have a return type.

  Key Points:
  - Automatically invoked when an object is created.
  - Used to initialize objects.
  - Can be default, parameterized, or copy constructor.
  - Can be overloaded (multiple constructors with different parameters).

  NOTE:
• Same name as class for constructor and defined in public.
• Constructor doesn't have a return type.
• Only called once (automatically), at object creation.
• Memory allocation happens when constructor is called.



  Syntax:
  class ClassName {
  public:
      ClassName() {
          // constructor body
      }
  };
*/

/*
  'this' Pointer (in C++):

  The 'this' pointer is an implicit pointer available inside all non-static member functions.
  It points to the object that invoked the function.

  Key Points:
  - Used to refer to the calling object's members (especially when parameter names conflict).
  - Helpful in returning the current object from a method.
  - It’s a pointer, so we use '->' to access members through it (e.g., this->name).

  Example Use:
  In constructors or setters, if parameter names match the member variables,
  'this' pointer is used to differentiate:
  this->name = name; // 'this->name' refers to the class member, 'name' is the parameter.
*/

#include<iostream>
#include<string>
using namespace std;

class Car {
    string name;
    string colour;

    public:

        Car(){ // => Non Parameterized Constructor
            cout << "Constructor without parameters" << endl;
        }

        // Constructor
        Car (string name, string colour){ // => Parameterized Constructor
            // Message to show constructor execution
            cout << "An object has been created. Constructor is called." << endl;
            
            // 'this->name' refers to the member variable, 'name' is the parameter
            this->name = name;
            // 'this->colour' refers to the member variable, 'colour' is the parameter
            this->colour = colour;
        }

        // NOTE: Constructor overloading means we can create multiple constructors in the same class with different parameters. 
        // The compiler automatically decides which one to use based on the arguments passed while creating the object.

        void start(){
            cout << "Starting Car" << endl;
        }

        void stop(){
            cout << "Stopping Car" << endl;
        }

        //GETTER
        string getName(){
            return name;
        }

        string getColour(){
            return colour;
        }
};

int main(){
    Car c1("BMW","White");  // -> Calling parameterized constructor
    // We don’t call the constructor manually — it runs automatically when the object is created and we can use it as a function to assign value.
    // OUTPUT : An object has been created. Constructor is called.

    // We have already initialised the value of private variable through constructor and create a getter to access it.
    cout << c1.getName() << endl;
    cout << c1.getColour() << endl;

    Car c2; // -> Calling non-parameterized constructor


    return 0;
}