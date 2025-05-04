/*
  ENCAPSULATION IN C++

  - Encapsulation is one of the core principles of Object-Oriented Programming (OOPS).
  - It refers to the bundling of data (variables) and methods (functions) that operate on the data into a single unit called a class.
  - The main goal is to restrict direct access to some components, which is why we use access modifiers like private, protected, and public.
  - This helps in maintaining control over the data and ensures better security, especially for sensitive information like passwords or user data.
  - Encapsulation also improves code maintainability and reduces complexity.

  Real-life analogy: A capsule (medicine) wraps ingredients inside a single outer shell — similarly, a class hides data and exposes only what's necessary.

  NOTE: Encapsulation is wrapping up of data & member functions (methods) in a single unit. It also implements data hiding
*/


#include<iostream>
#include<string>
using namespace std;

/*
ENCAPSULATION: Encapsulation is the concept of wrapping data (variables) and methods (functions)
into a single unit called a class. It helps protect the internal state of an object by making 
some members private and controlling access using public methods like getters and setters.
This provides security, modularity, and data hiding in object-oriented programming.
*/

// ENCAPSULATION EXAMPLE
class Student {
private:
    // Private data members: can't be accessed directly outside the class
    string name;
    float cgpa;

public:
    // Setter method for name
    // Allows controlled way to update private 'name'
    void setName(string studentName) {
        name = studentName;
    }

    // Getter method for name
    // Allows controlled way to read private 'name'
    string getName() {
        return name;
    }

    // Setter method for cgpa
    void setCgpa(float studentCgpa) {
        cgpa = studentCgpa;
    }

    // Getter method for cgpa
    float getCgpa() {
        return cgpa;
    }
};

int main() {
    Student s1;  // Create an object of Student class

    // Set values using setter methods
    s1.setName("Govind");
    s1.setCgpa(9.2);

    // Get values using getter methods
    cout << "Name: " << s1.getName() << endl;
    cout << "CGPA: " << s1.getCgpa() << endl;

    return 0;
}
