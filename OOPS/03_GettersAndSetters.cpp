/*
GETTERS AND SETTERS IN C++:

Getters and Setters are used to access and update private data members of a class.
- A getter is a public method that returns the value of a private variable.
- A setter is a public method that sets/updates the value of a private variable.

Why use them?
- They help keep data safe by allowing controlled access.
- We can add checks or conditions while setting values.

Syntax:
class ClassName {
  private:
    DataType variableName;
  public:
    void setVariableName(DataType value);  // Setter
    DataType getVariableName();            // Getter
};
*/

#include<iostream>
#include<string>
using namespace std;


class Student {
    private:
        string name;
        float cgpa;
    public:

    
    // Setters: Set some value of private variable using a function to not give full access to private variable.
    void setName(string studentName){
        name = studentName; // Setting student name which is private indirectly by not giving full access to the the name but instead we can add name using setter functions.
    }
    
    void setCgpa(float studentCgpa){
        cgpa = studentCgpa; // Setting student cgpa which is private indirectly by not giving full access to the the name but instead we can add name using setter functions.
    }
    
    // Getters: Get some value of private variable using a function to not give full access to private variable.
    string getName() {
        return name; // Returning student name which is private but accessible via the getter function.
    }
    
    float getCgpa() {
        return cgpa; // Returning student CGPA which is private but accessible via the getter function.
    }
    
    void getPercentage() {
        cout << "Percentage : " << (cgpa * 10) << "%" << endl;
    }

};

int main(){
    Student s1;
    // Setter Function
    s1.setName("ABCD");
    s1.setCgpa(9.1);

    // Getter Function
    cout << s1.getName() << endl;
    cout << s1.getCgpa() << endl;

    s1.getPercentage();
    return 0;
}