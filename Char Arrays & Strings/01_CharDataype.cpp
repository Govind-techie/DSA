/*
CHAR DATAYPE: A char datatype is used to store a single character like a letter, number, or symbol.
It usually takes 1 byte of memory and stores the ASCII value of that character.
*/

#include<iostream>
using namespace std;

int main(){
    char ch1 = 'a';
    char ch2 = 'X';
    char ch3 = '@';
    char ch4 = '9'; // The digit 9 is inside single quotes, so it is stored as a character, not as a number.

    /*
    NOTE:
    • Always put a character inside single quotes like 'a' when storing it.
	• Each character has a special number (ASCII value) that gets stored in memory.
	• Capital and small letters have different ASCII values.
    */

    /*
    Char Datatype in memory:

    1. A 'char' uses 1 byte (8 bits) of memory.

    2. It stores the ASCII value (a number) of the character, not the character itself.
        {ASCII - American Standard Code for Information Interchange}

    3. Example:
       char ch = 'A'; 
       // 'A' is stored as ASCII value 65 in memory.

    4. Always enclose a character in single quotes, like 'A', '9', '%', etc.

    5. Uppercase and lowercase letters have different ASCII values:
       // 'A' → 65
       // 'a' → 97

    6. Internally, storage happens like this:
       Character → ASCII Value → Binary form → Stored in memory.
    */

    // Accessing ASCII value.
    char ch = 'A';
    cout << "ASCII value of A is "<< (ch) << endl; // Output: 65 (because we typecasted 'A' from char to int)
    
    // Finding Position of characters.
    char character = 'F';
    int pos = character - 'A';

    cout << "Position of " << character << " is " << pos << endl;

    return 0;
}