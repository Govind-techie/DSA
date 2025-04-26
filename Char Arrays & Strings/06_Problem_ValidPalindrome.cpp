/*
Problem: Valid Palindrome

Statement:
Given a character array (string), check whether it is a palindrome or not.
A palindrome is a word that reads the same backward as forward.

You must ignore cases (treat lowercase and uppercase letters as the same) and consider only alphabetic characters (ignore digits, spaces, punctuation, etc.).

Example:

Input: 
    word = "RaceCar"
Output: 
    Valid Palindrome

Input: 
    word = "hello"
Output: 
    Not a Palindrome

Input: 
    word = "A man, a plan, a canal: Panama"
Output: 
    Valid Palindrome
*/


#include<iostream>
using namespace std;

void validPalindrome(char word[], int n){
    int st = 0;
    int end = n - 1;
    bool isPalindrome = true; 
    while(st < end){
        if (tolower(word[st++]) != tolower(word[end--])){
            isPalindrome = false;
        }
    }

    if(!isPalindrome){
        cout << "Not a valid Palindrome" << endl;
    }else{
        cout << "Valid Palindrome" << endl;
    }
}

int main(){
    char word[] = "RaceCar";
    validPalindrome(word,strlen(word));
    return 0;
}