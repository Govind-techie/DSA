/*
String Member Functions in C++

Definition:
String member functions are functions that are built into the C++ string class. These functions allow manipulation of string objects like getting their length, appending, finding substrings, and more.

Commonly used String Member Functions:

1. length() or size()
   - Returns the number of characters in the string (excluding the null-terminator).
   - Example: int len = str.length();  // Returns the length of the string 'str'

2. append() 
   - Adds characters to the end of the string.
   - Example: str.append(" World");  // Appends " World" to 'str'

3. find() 
   - Finds the first occurrence of a substring in the string.
   - Example: size_t pos = str.find("World");  // Returns position of "World" in 'str'

4. substr()
   - Returns a substring starting from a specified position and optionally with a specified length.
   - Example: string sub = str.substr(0, 5);  // Extracts substring from index 0 to 5

5. clear()
   - Clears all characters from the string, making it an empty string.
   - Example: str.clear();  // Makes 'str' an empty string

6. at()
   - Returns a reference to the character at a specified position in the string. Throws an exception if the index is out of bounds.
   - Example: char ch = str.at(2);  // Returns the character at index 2 of 'str'
*/

#include<iostream>
#include<string> // For using string member functions
using namespace std;

int main(){
    // 1. LENGTH() or SIZE() - Get the Length of the String
    string str1 = "Hello, World!";
    cout << "Length of str1: " << str1.length() << endl;  // OUTPUT: 13

    // 2. APPEND() - Add Characters to the End of the String
    str1 += " How are you?";  // Using the += operator to append text
    cout << "After append: " << str1 << endl;  // OUTPUT: Hello, World! How are you?

    // 3. FIND() - Find the First Occurrence of a Substring

    string st = "I love C++ & Java . I love C++ for its speed";

    cout << st.find("C++") << endl; // Finds and prints the index of the first "C++"

    cout << st.find("C++", 8) << endl; // Finds "C++" starting the search from index 8
    
    cout << st.find("Python") << endl; // Prints string::npos because "Python" is not found which is -1.


    // Search for the position of "World" in str1
     size_t pos = str1.find("World");  // str1.find() returns the index of the first occurrence of "World"

     // Check if "World" was found by comparing with string::npos
     if (pos != string::npos) {  // If not found, pos will be equal to string::npos
         cout << "'World' found at position: " << pos << endl;  // OUTPUT: Found 'World' at position: 7
     } else {
         cout << "'World' not found!" << endl;  // If position is npos, print not found
     }
 

    // 4. SUBSTR() - Get a Substring from the String
    string sub = str1.substr(0, 5); // Extract substring starting from index 0, length 5
    cout << "Substring: " << sub << endl;  // OUTPUT: Hello

    // 5. CLEAR() - Clear All Characters from the String
    str1.clear();  // Removes all characters from str1
    cout << "After clear: " << str1 << endl;  // OUTPUT: (empty string)

    // 6. AT() - Access Character at a Specific Index
    string str2 = "Hello";
    cout << "Character at index 2: " << str2[2] << endl;  // OUTPUT: l
    // Instead of at(), using direct access with the [] operator

    return 0;
}