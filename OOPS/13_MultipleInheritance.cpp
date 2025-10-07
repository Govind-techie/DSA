/*
    MULTIPLE INHERITANCE IN C++

    - Multiple inheritance allows a class to inherit from more than one base class.
    - The derived class combines and utilizes features from all its base classes.

    Structure:
        BaseClass1 → DerivedClass ← BaseClass2

    Real-life Analogy:
    - Teacher: Has a salary and teaches a subject.
    - Student: Has a roll number and CGPA.
    - TA (Teaching Assistant): Inherits from both Teacher and Student.
      A TA is both a student and a teacher.

    Syntax:
        class A {
            // base class A members
        };

        class B {
            // base class B members
        };

        class C : public A, public B {
            // inherits from both A and B
        };

    Key Points:
    - A derived class inherits public and protected members (not private) from multiple base classes.
    - Constructor calls occur left-to-right (A then B), destructor calls reverse (B then A).
    - Ambiguity arises if both base classes have members with the same name — resolved using scope resolution.

    This example demonstrates:
        Teacher + Student → TA (Teaching Assistant)
*/

#include<iostream>
#include<string>
using namespace std;

// Base class - Teacher
// Contains properties related to teaching responsibilities.
class Teacher{
    public:
    int salary;         // Salary of the teacher
    string subject;     // Subject taught by the teacher
};

// Base class - Student
// Contains properties related to academic performance.
class Student{
    public:
    int rollNumber;     // Roll number of the student
    float cgpa;         // CGPA of the student
};

// Derived class - TA (Teaching Assistant)
// Inherits from both Teacher and Student.
class TA : public Teacher , public Student{
    public:
    string name;        // Name of the teaching assistant
};

int main(){
    TA ta1;

    // Set TA's own member
    ta1.name = "Rohit";

    // Inherited from Teacher
    ta1.salary = 50000;
    ta1.subject = "DSA";

    // Inherited from Student
    ta1.rollNumber = 42;
    ta1.cgpa = 9.1;

    // Display TA information
    cout << "TA Name: " << ta1.name << endl;
    cout << "Subject: " << ta1.subject << endl;
    cout << "Salary: " << ta1.salary << endl;
    cout << "Roll Number: " << ta1.rollNumber << endl;
    cout << "CGPA: " << ta1.cgpa << endl;

    return 0;
}

// Multiple inheritance demonstration complete