/*
    POLYMORPHISM IN C++

    Definition:
      Polymorphism is the ability of a function, object, or operator to behave differently based on the context.
      It allows objects of different classes to be treated as objects of a common base class.

    Types of Polymorphism:
      1. Compile-time Polymorphism (also known as Static Polymorphism):
         - This occurs when the method that is called is determined at compile time.
         - Examples: Function Overloading, Operator Overloading.

      2. Run-time Polymorphism (also known as Dynamic Polymorphism):
         - This occurs when the method that is called is determined at runtime.
         - Example: Virtual Functions and Inheritance (method overriding).

    Key Concepts:
      - Function Overloading: Multiple functions can have the same name but different parameters.
      - Operator Overloading: Allows the use of operators with user-defined data types.
      - Virtual Functions: In base classes, virtual functions allow derived class methods to override them.
      - Dynamic Binding: The method call is resolved at runtime using a virtual function.

    Advantages of Polymorphism:
      - Increases flexibility and maintainability of code.
      - Allows the same function or operator to be used with different types of data.
      - Enables cleaner and more concise code.

    Example in this file:
      - Demonstrates function overloading and method overriding in a simple C++ program.

    Constructor/Destructor Behavior:
      - When polymorphism is used, constructors/destructors in base and derived classes are involved.
      - Base class constructors are called first, followed by derived class constructors.
      - In case of destruction, derived class destructors are called first, followed by base class destructors.

    Important Notes:
      - Use virtual keyword in the base class to enable run-time polymorphism.
      - The destructor of a base class should be virtual if derived classes are involved in polymorphic behavior.  
      - Function overloading improves code readability and organization by allowing multiple functions with the same name to handle different data types.
      - The function signature (i.e., function name + parameter list) must be different for each overloaded version.
      - Return type alone is not enough to distinguish overloaded functions.
      - Function overloading cannot be done by changing only the return type.
      - Compile-time polymorphism increases performance since the function to be called is known at compile time.

    (Definition) -> Polymorphism is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used.
*/


#include<iostream>
#include<string>
using namespace std;


/*
    Compile-Time Polymorphism in C++

    Definition:
    Compile-time polymorphism (also known as static polymorphism) refers to the ability of a function or operator
    to behave differently based on the type or number of arguments, with the decision made at compile time.

    Common Forms:
    1. Function Overloading:
       - Multiple functions with the same name but different parameter lists.
       - The compiler selects the appropriate function based on the arguments used during the call.
       - Example: Printing different data types using the same function name.

    2. Operator Overloading:
       - Redefining how operators work for user-defined types like classes.
       - Improves code readability by allowing intuitive use of operators (e.g., +, -, ==) with objects.
       - Example: Adding two complex number objects using the '+' operator.

    Advantages:
    - Enhances code readability and reusability.
    - Allows the same function/operator to work with multiple types.
    - Increases performance as decisions are resolved at compile time.

    This program demonstrates:
    - Function overloading: 'show()' function behaves differently based on input type.
    - Operator overloading: '+' operator is overloaded to add two complex numbers.
*/

class Print {
    public:

        // Compile-Time Polymorphism -> (FUNCTION OVERLOADING)

        // Overloaded function to handle integer input
        void show(int a){
            cout << "Printing Integer.. " << a << endl;
        }

        // Overloaded function to handle string input
        void show(string b){
            cout << "Printing String.. " << b << endl;
        }

};


class ComplexNumbers {
    int real; // Real part of the complex number
    int img;  // Imaginary part of the complex number

    public:
        // Constructor to initialize real and imaginary parts
        ComplexNumbers(int real , int img){
            this->real = real;
            this->img = img;
        }

        // Display the complex number in a + bi format
        void showNum(){
            cout << real << " + " << img << "i" << endl;
        }

        // Compile-Time Polymorphism -> (OPERATOR OVERLOADING)

        // Overloading the '+' operator to add two complex numbers
        void operator + (ComplexNumbers &c2){
            // Indicate that addition is happening
            cout << "Adding.." << endl;
            int resReal = this->real + c2.real; // Add real parts of the two complex numbers
            int resImg = this->img + c2.img;   // Add imaginary parts of the two complex numbers
            ComplexNumbers c3(resReal, resImg); // Create a new complex number with the result
            cout << "RESULT : ";
            c3.showNum(); // Display the result
            cout << endl;
        }
};

/*
    Run-Time Polymorphism in C++

    Definition:
    Run-time polymorphism (also known as dynamic polymorphism) occurs when the method that gets called
    is determined during program execution, typically through inheritance and virtual functions.

    Key Mechanism:
    - Achieved using **virtual functions** in a base class and **method overriding** in derived classes.
    - Function calls are resolved at **runtime** using **dynamic binding** (via vtable).

    Requirements:
    - A base class with at least one virtual function.
    - A derived class that overrides the base class's virtual function.
    - A base class pointer or reference used to call the overridden method.

    Advantages:
    - Enables flexibility by allowing behavior to be determined at runtime.
    - Promotes the use of interfaces and abstract design.
    - Supports the **"open/closed principle"** in object-oriented design.

    Important Notes:
    - Destructors should be declared virtual in base classes when using polymorphism to ensure proper cleanup.
    - Virtual functions cannot be static.
    - Only member functions can be virtual.

    Example Use Case:
    - A base class `Animal` with a virtual `speak()` function.
    - Derived classes like `Dog` and `Cat` override `speak()` with their own implementations.
    - A base class pointer can call `speak()` on any derived object, and the correct version is invoked at runtime.
*/

/*
• Function Overriding:
-> Parent & Child both contain the same function with different implementation.
-> The parent class function is said to be overriden.
*/

// Base class defines a method 'show()'
// This method will be overridden by the derived class
class Parent {
  public:
    void show(){
      cout << "parent class show" << endl; // Original method in base class
    }

    // This is a virtual function
    // Marking it 'virtual' tells the compiler to support run-time polymorphism
    // When accessed through a base class pointer, C++ will look at the actual (derived) object and call the overridden version
    virtual void hello(){ // => In this case the name of function is same but the work is different
      cout << "Parent Hello" << endl;
    }
};

// Derived class inherits from Parent and defines its own 'show()' method
// This overrides the base class version (function overriding)
class Child : public Parent {
  public:
    void show(){
      cout << "child class show" << endl; // Overridden method in derived class
    }

    // This overrides the Parent's virtual function
    // Because 'hello()' is virtual in the base class, this version will be called when accessed via a base pointer
    void hello(){  // => In this case the name of function is same but the work is different
      cout << "Child Hello" << endl;
    }
};

/*
• Virtual Functions:
A virtual function is a member function that you expect to be redefined in derived classes.

KEY NOTES:
• Virtual functions are Dynamic in nature.
• Defined by the keyword "virtual" inside a base class and are always declared with a base
  class and overridden in a child class.
• A virtual function is called during runtime.
*/



int main(){

  // FUNCTION OVERLOADING -> (COMPILE-TIME POLYMORPHISM)
    Print obj1;
    obj1.show("Hello"); // Calls the show() function that accepts a string argument
    obj1.show(12);      // Calls the show() function that accepts an integer argument
    
    // NOTE: The compiler chooses the appropriate overloaded function at compile time based on argument type.

  // OPERATOR OVERLOADING -> (COMPILE-TIME POLYMORPHISM)

    // Creating first complex number: 1 + 2i
    ComplexNumbers c1(1, 2);
    cout << "First Complex Number: ";
    c1.showNum();

    // Creating second complex number: 3 + 4i
    ComplexNumbers c2(3, 4);
    cout << "Second Complex Number: ";
    c2.showNum();

    // Using overloaded '+' operator to add c1 and c2
    // This demonstrates compile-time polymorphism through operator overloading
    c1 + c2; // Internally calls c1.operator+(c2)

  // FUNCTION OVERRIDING -> (RUN-TIME POLYMORPHISM)

    Child ch1;
    ch1.show(); // Output: "child class show"

    /*
    Explanation:
    Even though the Child class inherits the show() method from the Parent class,
    defining a new show() method in Child overrides the one from Parent.
    Since we are calling the method using a Child object, the Child's version is executed.
    This is an example of function overriding, but without 'virtual', it's resolved at compile time.
    */

    // VIRTUAL FUNCTION -> (RUN-TIME POLYMORPHISM)

    Child ch2;
    Parent *ptr; // ptr points at object of parent class

    ptr = &ch2; // => parent ptr is pointing at child object its a run time binding.

    /*
    Run-time polymorphism in action:
    Even though the pointer type is Parent*, the actual object is of type Child.
    Because 'hello()' is virtual, C++ uses the virtual table (vtable) to decide at runtime
    which version of 'hello()' to call.
    Hence, it calls Child's version, not Parent's.
    */

    ptr->hello(); // As ptr already pointing to ch2 which is a child object thus it internally represent (ch2.hello())
    return 0;
}

/*
   Difference between Compile-time and Run-time Polymorphism:

    Compile-time Polymorphism (also called Static Polymorphism):
    - The decision about which function or operator to call is made at compile time.
    - It is resolved during the compilation process.
    - Examples: Function Overloading, Operator Overloading.
    - It is faster because all the function calls are resolved before the program runs.
    - The function or operator signature is determined by the compiler based on the input parameters and types.

    Run-time Polymorphism (also called Dynamic Polymorphism):
    - The decision about which function to call is made at runtime, during the execution of the program.
    - It is resolved dynamically through mechanisms like virtual functions and function overriding.
    - Examples: Function Overriding with virtual functions.
    - It is more flexible but slightly slower due to dynamic dispatch (vtable mechanism).
    - The actual function to be called is determined by the object type that the pointer or reference is pointing to at runtime.
*/
