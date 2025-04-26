/*
CHARACTER ARRAY: 
A char array is a collection of multiple characters stored together in continuous memory locations.
It is mainly used to store a sequence of characters, like a word or a sentence.

Each character is stored one after another, and the array ends with a special character called the null character ('\0') to mark the end.
*/

#include<iostream>
using namespace std;

int main(){
    char str1[5] = {'a', 'b', 'c', 'd', 'e'}; // Character Array without null character

    for (int i = 0; i < 5; i++) {
        cout << str1[i] << " "; 
    }
    cout << endl;
    // OUTPUT: a b c d e

    char str2[5] = {'c', 'o', 'd', 'e', '\0'}; 
    // When using a character array to store a word (string),
    // the array must end with a null character ('\0') to mark the end of the string.

    // Null character ('\0') has an ASCII value of 0.

    cout << str2 << endl; 
    // OUTPUT: code

    /*
    NOTE: 
    - In an int array, the array name acts as a pointer to the first element.
    - In a char array, the array name is treated as the entire string (up to the null character).
    */

    char arr[] = "hello"; 
    // When we store a string literal in a char array, 
    // each character is automatically stored at each index, 
    // and a null character ('\0') is added at the end automatically.

    // Internally, it looks like:
    // char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};

    cout << arr << endl; 
    // OUTPUT: hello

    /*
    Important:
    - char arr2[4] = "code"; // Error!
    - The size is 4, but the string "code" needs 5 spaces 
      (4 characters + 1 for '\0').
    - Always make sure the array is large enough to store 
      all characters + the null character.
    */
    return 0;
}