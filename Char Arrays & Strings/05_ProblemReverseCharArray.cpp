/*
Problem: Reverse Character Array

You are given a character array (a string). Your task is to reverse the characters in the array in-place — that means without using any extra array.
After reversing, print the modified array.

Example:
Input: word[] = "HELLO"
Output: OLLEH
*/

#include <iostream>
using namespace std;

// By Two Pointer Approach
void reverseCharArray(char word[], int n){
    int st = 0; // Initialize start pointer at the beginning
    int end = n - 1; // Initialize end pointer at the last character (excluding null character)
    
    // Continue swapping until the two pointers meet or cross
    while (st < end){
        // Swap the characters at start and end positions
        swap(word[st++], word[end--]);
        // Move start pointer forward
        // Move end pointer backward
    }
    
    // After reversing, print the modified array
    cout << word << endl;
}

int main(){
    // INPUT ARRAY
    char word[] = "HELLO";
    // Pass the array and its length (excluding '\0') to the function using strlen function.
    reverseCharArray(word, strlen(word));
    return 0;
}