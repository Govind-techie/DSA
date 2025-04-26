/*
INPUT IN CHARACTER ARRAY:
Taking multiple characters (like a word or sentence) from the user and storing them together in a character array.
*/

#include<iostream>
using namespace std;

int main(){
    char word[100];
    cout << "Enter your word : ";
    cin >> word; // Takes input as a string and stores each character at separate indexes.

    cout << "Entered word is : " << word << endl;
    cout << "Length of word " << word << " is " << strlen(word) << endl; // strlen() is used to find the length of a string.

    // NOTE: cin stops reading input after a whitespace (like space, tab, or enter).

    /*
    Example:
    If we enter: hello world
    Output: hello (word after space is ignored)
    */

    // To take a full sentence as input (with spaces), we use getline() with cin.

    // GETLINE FUNCTION: getline() reads a full line of input (including spaces) into a character array.

    // Syntax of getline() for character array:
    // cin.getline(array_name, size);
    // array_name → Name of the character array.
    // size → Maximum characters to read (including '\0' null character).

    cin.ignore(); // Skips the next unread character (like leftover newline '\n') from the input buffer.

    char sentence[100];

    cout << "Enter your sentence : ";
    cin.getline(sentence,100,'.');  // '.' is passed as a delimiter to stop input when '.' is entered.

    cout << "Entered sentence is : " << sentence << endl;
    cout << "Length of the sentence is " << strlen(sentence) << endl;

    /*
    Example:
    If we enter: i love programming. i don't love study
    Output: i love programming
    (Input stops reading when '.' is encountered.)

    NOTE: Passing a delimiter is optional in getline().
    */
   
    return 0;
}