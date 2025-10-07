/*
OBJECT-ORIENTED PROGRAMMING (OOPS)

OOP is a programming paradigm based on the concept of "objects", which are instances of "classes". 
It helps in designing modular, reusable, and maintainable code by modeling real-world entities.

➤ Four Pillars of OOP:
  1. Encapsulation – Bundling data and methods that operate on that data within one unit (class).
  2. Abstraction – Hiding internal implementation details and exposing only the necessary interface.
  3. Inheritance – Enabling new classes to acquire the properties and behaviors of existing ones.
  4. Polymorphism – Allowing objects to take many forms and respond differently to the same function call.

➤ CLASS:
A class is a user-defined blueprint or prototype from which objects are created.
It defines the attributes (data members) and methods (member functions) that characterize any object of the class.

Syntax:
    class ClassName {
        // properties or attributes
        // methods or functions
    };

➤ OBJECT:
An object is an instance of a class. It occupies memory and can access class members (based on access specifiers).

Syntax:
    ClassName objectName;

➤ Key Notes:
  - Class members are private by default.
  - Objects can access only the public members of a class directly.
  - Member functions do not contribute to object size.
  - Static members are shared across all objects.
  - A class acts as a common blueprint; each object has its own copy of non-static data members.
*/


#include<iostream>
#include<string>
using namespace std;

class Student {
	// Properties/Attributes
	string name;
	float cgpa;

	// Methods/Functions
	void getPercentage(){
		cout << "Percentage of student " << name << " is " << (cgpa*10) << "%"<< endl;
	}
};

// NOTE: A class is like a blueprint. 
// All objects made from the class have the same structure and properties defined in it.

class UserInstagram {
	// PROPERTIES
	string username;
	string password;
	string bio;
	int id;

	// METHODS 
	void deactivate(){
		cout << "Deactivating Account: " << username << " with id: " << id << endl; 
	}

	void changeBio(){
		string changeBio;
		cout << "Change Bio: ";
		cin >> changeBio;
		cout << "Bio successfully changed." << endl;
	}

	void addComments(){
		string addComment;
		cout << "Enter your comment: ";
		cin >> addComment;
		cout << "Your comment: " << addComment << endl; 
	}

};

int main(){
	Student s1; // Object of class Student.
	// NOTE: When we create an object, it is allocated some memory.
	cout << sizeof(s1) << endl; // OUTPUT: 32 (bytes)

    return 0;
}