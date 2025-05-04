/*
PROBLEM:
Make a class called User with three properties:
- id (private)
- username (public)
- password (private)

Use a parameterized constructor to set the id.

Also, create a setter and getter for the password.
*/

#include<iostream>
#include<string>
using namespace std;

// User class demonstrating encapsulation: keeping sensitive data (id, password) private
class User{
    // Private property: user ID (only accessible inside the class)
    int id;
    // Private property: password (confidential data)
    string password;

    public:
        // Public property: username (accessible from outside the class)
        string username;

        // Parameterized constructor to initialize user ID
        User(int id){
            // 'this' pointer refers to the current object to avoid naming conflict
            this->id = id;
        }

        // Setter: allows setting private password securely
        void setPassword(string password){
            this->password = password;
        }

        // Getter: allows reading private password safely
        string getPassword(){
            return password;
        }
};

int main(){
    // Creating a user object and initializing ID using the constructor
    User u1(12345);
    // Setting password using setter method
    u1.setPassword("ABCD");
    // Accessing password using getter method
    cout << u1.getPassword() << endl;
    return 0;
}