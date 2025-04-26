/*
STRINGS IN C++

String Properties:
C++ Strings are objects of pre-defined string class in STL.
C++ Strings have useful member functions. eg: str.length() - give string length
C++ Strings are dynamic (their size can change at run time).
C++ Strings support operators like +, ==, >, < etc.
C++ Strings are stored contiguously in memory similar to character array.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "Hello"; // NOTE: str is an object of class string
    // NOTE: Even though string is stored in a contigous array like manner they are dynamic and can change there size during runtime so its not necessary to mention size unlike array.
    cout << str << endl; 

    str = "Apple"; // We can directly assign string literal to string object (str).

    cout << str << endl;

    // INPUT IN STRINGS

    string str1;
    cout << "Enter a string : ";
    cin >> str1; // Ignore input after whitespaces
    cout << "Entered string : " << str1 << endl;

    cin.ignore();

    string str2;
    cout << "Enter a string sentence : ";
    getline(cin,str2,'.'); // We dont have to mention the size of str2 as string is dynamic.
    cout << "Entered string sentence: " << str2 << endl;

    // Accessing character at particular index of string.

    cout << str2[0] << endl;
    cout << str2[1] << endl;
    cout << str2[2] << endl;
    cout << str2[3] << endl;


    return 0;
}