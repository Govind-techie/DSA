/*
Problem: Valid Anagram

Statement:
Given two character arrays (strings), check whether they are anagrams of each other or not.
An anagram is a word formed by rearranging the letters of another word, using all original letters exactly once.

You must ignore cases (treat lowercase and uppercase letters as the same) and consider only alphabetic characters (ignore digits, spaces, punctuation, etc.).

Example:

Input: 
    str1 = "listen", str2 = "silent"
Output: 
    Valid Anagram

Input: 
    str1 = "hello", str2 = "world"
Output: 
    Not an Anagram

Input: 
    str1 = "Dormitory", str2 = "Dirty room"
Output: 
    Valid Anagram
*/

#include<iostream>
#include<string>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    // If lengths are different, they can't be anagrams
    if (s.length() != t.length()) 
        return false;

    int count[26] = {0}; // Array to count frequency of each character (assuming only lowercase letters)

    // Count characters from first string
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    // Decrease count based on second string
    for (int i = 0; i < t.length(); i++) {
        if (count[t[i] - 'a'] == 0) {
            return false; // If character not found or overused
        }
        count[t[i] - 'a']--;
    }

    return true; // All counts matched, so they are anagrams
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (isAnagram(str1, str2)) {
        cout << "Valid Anagram" << endl;
    } else {
        cout << "Not an Anagram" << endl;
    }

    return 0;
}