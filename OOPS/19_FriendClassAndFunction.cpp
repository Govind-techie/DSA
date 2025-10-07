/*
Friend Class and Friend Function

-> Friend Function:
   - Not a member of the class but has access to its private and protected members.
   - Declared inside the class using the 'friend' keyword.
   - Useful when an external function needs to operate on private data of a class.

-> Friend Class:
   - A class declared as 'friend' of another class gets access to its private and protected members.
   - This allows close cooperation between two classes.

Notes:
   - Friendship is one-way and must be explicitly declared.
   - Friendship is not inherited by derived classes.
   - Should be used carefully as it breaks encapsulation.
*/

#include<iostream>
#include<string>
using namespace std;

/*
Friend Class & Function:
-> A friend class or a friend function can access private and protected members of other classes in which it is declared as a friend
*/

class A {
    string secret = "Top Secret Data";
    
    // Declaring class B as a friend of class A.
    // This allows class B to access private and protected members of class A.
    friend class B;

    // Declaring the function revealSecret as a friend of class A.
    // This allows the function to access private members of class A.
    friend void revealSecret(A &obj);
};

class B { 
    // Class B is a friend class of A, so it can access the private members of A.
    public:
        void showSecret(A &obj) {
            // Accessing the private member 'secret' of class A because class B is a friend of A.
            cout << obj.secret << endl;
        }
};

// FRIEND FUNCTION:
// This function is not a member of class A, but because it is declared as a friend,
// it can access the private members of class A, like 'secret'.
void revealSecret(A &obj) {
    // Accessing the private member 'secret' of class A from the friend function.
    cout << obj.secret << endl;
}

int main() {
    A a1; // Creating an object of class A.
    B b1; // Creating an object of class B.

    // Calling the friend function showSecret() of class B,
    // which can access the private member 'secret' of class A.
    b1.showSecret(a1);

    // Calling the friend function revealSecret().
    // This function is allowed to access the private member 'secret' of class A.
    revealSecret(a1);

    return 0;
}
