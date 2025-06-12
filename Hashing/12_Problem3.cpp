/*
Problem: Valid Anagram

Given two strings, determine if one is an anagram of the other.

Input:
- Two strings (can contain lowercase letters)

Output:
- Return true if the strings are anagrams of each other, otherwise return false.

Example:
Input: s = "listen", t = "silent"
Output: true

Input: s = "hello", t = "world"
Output: false
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// Function to check if two strings are anagrams
bool validAnagram(string s1, string s2){
    // If lengths are different, they can't be anagrams
    if (s1.size() != s2.size()) return false;

    // Create a frequency map for characters in s1
    unordered_map<char, int> m;
    for (char ch : s1) {
        m[ch]++;  // Increment count for each character
    }

    // Traverse s2 and decrease the frequency of each character
    for (char ch : s2){
        // If the character doesn't exist in map OR its frequency is already 0, it's not an anagram
        if (!m.count(ch) || m[ch] == 0){
            return false;
        }
        m[ch]--;  // Decrease frequency
    }

    // If we reached here, all characters matched in frequency — it's an anagram
    return true;
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    // Call the function and print result
    if (validAnagram(s1, s2)) {
        cout << s1 << " and " << s2 << " are anagrams." << endl;
    } else {
        cout << s1 << " and " << s2 << " are not anagrams." << endl;
    }

    return 0;
}