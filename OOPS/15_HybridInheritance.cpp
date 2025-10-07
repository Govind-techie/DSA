/*
    HYBRID INHERITANCE IN C++

    ➤ Definition:
      Hybrid inheritance is a combination of two or more types of inheritance
      (e.g., single, multiple, hierarchical) in a single program.

    ➤ General Structure:
            BaseClass1       BaseClass2
                 \             /
                  \           /
               IntermediateClass
                       |
                 DerivedClass

    ➤ Real-life Analogy:
      - "Person": A general individual with basic traits.
      - "Worker": Adds professional identity.
      - "Teacher": Inherits from both Person and Worker (Multiple Inheritance).
      - "MathTeacher": Inherits from Teacher (Single Inheritance).
        A MathTeacher is a specialized type of teacher with math expertise.

    ➤ Advantages:
      - Combines benefits of multiple inheritance models.
      - Useful for modeling complex real-world scenarios.

    ➤ Challenges:
      - Ambiguity due to inherited members with the same name.
      - The Diamond Problem: Can occur when multiple paths lead to the same base class.
      - Use `virtual` inheritance to resolve such ambiguity.

    ➤ Constructor Order:
      - Constructors are called in the order of inheritance:
        Base classes → Intermediate → Derived class.

    ➤ Example Flow:
      Person + Worker → Teacher → MathTeacher

    ➤ Note:
      This example is simple and does not include `virtual` keyword,
      but it's necessary when resolving the Diamond Problem.
*/

#include <iostream>
using namespace std;

// Base class - Person
// General attributes of a person
class Person {
public:
    // Method to display details of a person
    void showPersonDetails() {
        cout << "This is a person." << endl;
    }
};

// Base class - Worker
// Professional/work-related traits
class Worker {
public:
    // Method to display details of a worker
    void showWorkerDetails() {
        cout << "This is a worker." << endl;
    }
};

// Intermediate class - Teacher
// Inherits from Person and Worker
class Teacher : public Person, public Worker {
public:
    // Method to display details of a teacher
    void showTeacherDetails() {
        cout << "This is a teacher." << endl;
    }
};

// Derived class - MathTeacher
// Inherits from Teacher
class MathTeacher : public Teacher {
public:
    // Method to display details of a math teacher
    void showMathTeacherDetails() {
        cout << "This is a math teacher." << endl;
    }
};

int main() {
    // Create object of MathTeacher
    MathTeacher mathTeacher;

    // Calling inherited methods from each level
    mathTeacher.showPersonDetails();      // From Person
    mathTeacher.showWorkerDetails();      // From Worker
    mathTeacher.showTeacherDetails();     // From Teacher
    mathTeacher.showMathTeacherDetails(); // From MathTeacher

    return 0;
}

// Hybrid inheritance demonstration complete