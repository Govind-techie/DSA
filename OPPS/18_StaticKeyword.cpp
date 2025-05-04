/*
STATIC KEYWORD IN C++

1. Static variable inside a function:
   - Retains its value between multiple calls.
   - Lifetime = whole program, Scope = local to function.

2. Static data member in class:
   - Shared among all objects of the class.
   - Only one copy exists, accessible with ClassName::member.

3. Static member function:
   - Can be called without creating an object.
   - Can access only static data members.

4. Static global variable:
   - Scope limited to the file it's declared in (internal linkage).

USE CASES:
- Count number of object instances.
- Share values among all objects.
- Limit visibility of global variables/functions to a file.
*/

/*
• Static Variables:
-> Variables declared as static in a function are created & initialised once for the lifetime of the program. => (in Function)
-> Static variables in a class are created & initialised once. They are shared by all the objects of the class. =>(in Class)
*/


#include<iostream>
#include<string>
using namespace std;

// NON-STATIC FUNCTION
// 'count' is a local variable that gets re-initialized to 0 every time the function is called.
// So, each call to counter1() starts fresh and prints 1.
void counter1(){
    int count = 0;
    count++;
    cout << "Count = " << count << endl;
}

// STATIC FUNCTION
// 'count' is declared static, so it's initialized only once during the first function call.
// It retains its value across multiple calls, even after the function ends.
void counter2(){
    static int count = 0; // => STATIC VARIABLE
    count++;
    cout << "Count = " << count << endl;
}

// STATIC VARIABLE (Inside Class)
// Static data members are shared among all objects of the class.
// Only one copy exists, regardless of how many objects are created.

class Example{
   public:
      static int x; // Declaration only — initialization must be done outside the class definition.
};

// Static member must be defined outside the class using ClassName::member syntax.
// This ensures memory is allocated and value is initialized.
int Example::x = 0;

/*
STATIC OBJECTS:
When an object is declared as static, it is initialized only once and persists until the end of the program.
Its constructor is called only once when the object is first encountered,
and its destructor is automatically called when the program terminates.
This behavior is useful when you need to preserve object state throughout the lifetime of the application.
*/

class Example2 {
   public:
      Example2(){
         cout << "Constructor...\n"; // Called only once when the static object is first created.
      }

      ~Example2(){
         cout << "Destructor...\n"; // Called automatically when the program ends.
      }
};


int main(){
   
   // counter1() resets 'count' every time => always prints 1.
   counter1(); // Output => 1
   counter1(); // Output => 1
   counter1(); // Output => 1
   
   // counter2() keeps incrementing 'count' across calls => prints 1, 2, 3.
   counter2(); // Output => 1
   counter2(); // Output => 2
   counter2(); // Output => 3

   // STATIC VARIABLE IN CLASS
   Example ex1;
   Example ex2;
   Example ex3;

   // All objects share the same static variable 'x'.
   // So changes made by one object reflect across others.

   cout << ex1.x++ << endl; // Output => 0 (initial value)
   cout << ex2.x++ << endl; // Output => 1 (incremented by ex1)
   cout << ex3.x++ << endl; // Output => 2 (incremented by ex2)

   // STATIC OBJECTS

   // This demonstrates the use of a static object inside a conditional block.
   int a = 0;
   if (a == 0){
      // 'ex1' is a static object, so it is created only once,
      // and its lifetime extends until the program ends.
      // Even though it's defined inside an if block, it doesn't get destroyed after the block ends.
      static Example2 ex1;
   }

   // This line executes after the if block.
   // The destructor for 'ex1' will be called after this, when main() ends.
   cout << "Code Ending...\n";

   /*
   OUTPUT for Non-Static Object:
   Constructor...
   Destructor...
   Code Ending...

   OUTPUT for Static Object:
   Constructor...
   Code Ending...
   Destructor...

   NOTE:
   -> A non-static object is created and destroyed immediately as it goes out of scope.
   -> A static object is created only once, retains its state, and remains in memory for the entire program duration.
   -> Its destructor is called automatically at the end of the program, after main() finishes execution.
   */
   return 0;
}