/*
Problem: Convert to UpperCase

Given a word or sentence in lowercase letters, 
convert all the characters to uppercase and print the result.

Example:
Input: Hello World
Output: HELLO WORLD
*/

#include<iostream>
using namespace std;

void toUpperCase(char word[], int n){
    // Loop through each character until null character '\0' is found
    for (int i = 0 ; i < n ; i++){
        // Check if the character is a lowercase letter (between 'a' and 'z')
        if (word[i] >= 'a' && word[i] <= 'z'){
            // Convert the lowercase character to uppercase by calculating its position relative to 'a' and shifting it to the corresponding 'A' position.
            word[i] = int(word[i]) - 'a' + 'A'; 
        }
    }
    
    // Print the modified word (now in uppercase)
    cout << word << endl; // OUTPUT: APPLE
}

int main(){
    // Initialize the character array with a word
    char word[] = "ApPle";

    toUpperCase(word,strlen(word));
    
    return 0;
}

/*
NOTE:
- In the ASCII table, the uppercase letters ('A' to 'Z') and lowercase letters ('a' to 'z') have a fixed gap of 32.
- So, if we subtract 32 from a lowercase letter's ASCII value, we directly get its corresponding uppercase letter.

Example:
- 'a' ASCII → 97
- 'A' ASCII → 65
- 97 - 32 = 65 → 'A'
*/