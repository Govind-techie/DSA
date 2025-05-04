/*
ACCESS SPECIFIERS IN C++ (Access Modifiers)

Access specifiers define the visibility and accessibility of class members (variables and functions).
They control how data and methods can be accessed both within the class and outside of it.

1. private:
   - Members are accessible only within the class itself.
   - Default access level for class members.
   - Used to implement encapsulation and data hiding.

2. public:
   - Members are accessible from outside the class using objects.
   - Exposes data or functionality to users of the class.

3. protected:
   - Members are accessible within the class and its derived (child) classes.
   - Not accessible from outside the class directly, but inherited by subclasses.

Syntax:
    class ClassName {
    private:
        // Private members
    public:
        // Public members
    protected:
        // Protected members
    };

Example:
    class Example {
    private:
        int secret;  // Private member

    public:
        void setSecret(int s) { secret = s; }  // Public method to access private member
        int getSecret() { return secret; }  // Public method to access private member
    };

Key Notes:
- Prefer keeping data members private and using public getter/setter methods to access them.
- This practice helps maintain the integrity of the object state and data encapsulation.
*/

#include <iostream>
#include<string>
using namespace std;

class Student {
    private:
        string name = "ABCD";  // Name is private and can only be accessed within the class.
    public:
        float cgpa;  // Public property can be accessed outside the class.

        void getPercentage() {
            cout << "Percentage : " << (cgpa * 10) << "%" << endl;
        }
};

// NOTE: Protected members can be accessed within the class and its derived classes.
// NOTE: They cannot be accessed directly from outside the class but can be inherited by subclasses.
class GraduateStudent {
    protected:
        float protectedCgpa;  // Protected member can be accessed by derived classes
    public:
        void setProtectedCgpa(float cgpa) {
            protectedCgpa = cgpa;  // Public method to set protected member
        }
        void showProtectedCgpa() {
            cout << "Protected CGPA: " << protectedCgpa << endl;
        }
};

class Graduate : public GraduateStudent {
    public:
        void displayCgpa() {
            cout << "Graduate CGPA: " << protectedCgpa << endl;  // Access protected member in derived class
        }
};

int main() {
    Student s1;

    // PRIVATE
    // 'name' is private, so it can't be accessed directly outside the class.
    // The following lines would give an error:
    // s1.name = "ABCD";
    // cout << s1.name << endl;

    // Real-life example: Things like passwords or functions like withdrawMoney() are kept private
    // to prevent unwanted access and protect sensitive data.

    // PUBLIC
    s1.cgpa = 9.0;  // 'cgpa' is public, so it can be accessed and modified directly.
    cout << s1.cgpa << endl;
    s1.getPercentage();  // Public method to display percentage.

    // PROTECTED
    Graduate g1;
    g1.setProtectedCgpa(8.5);  // Setting protected member using a public method.
    g1.displayCgpa();  // Accessing protected member from a derived class.

    // Protected members can’t be accessed from outside the class directly,
    // but they can be used in derived classes.

    return 0;
}