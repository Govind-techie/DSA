/*
Problem Statement: Find All Permutations of a String

Given a string `s`, write a program to generate all possible permutations of the string. 
A permutation is a rearrangement of the characters of the string in all possible orders.

Example:
Input: "abc"
Output: "abc", "acb", "bac", "bca", "cab", "cba"

Note:
- The input string will not contain duplicate characters.
- The order of the permutations in the output does not matter.
*/

#include<iostream>
#include<string>
using namespace std;

// Recursive function to generate all permutations of the given string
void permutations(string str, string ans, int n){
    // Base case: if the current permutation has length equal to the original string,
    // print it and return
    if (ans.size() == n){
        cout << ans << endl;
        return;
    }

    // Loop through each character in the current string
    for (int i = 0 ; i < str.size() ; i++){
        char ch = str[i];  // Select the i-th character

        // Create the next string by removing the i-th character
        string nextStr = str.substr(0,i) + str.substr(i+1,n-i-1);

        // Recurse with the updated string and the current answer appended with ch
        permutations(nextStr, ans + ch, n);
    }
}

/*
Explanation of nextStr logic:

To remove a specific character (like 'c') from a string (e.g., "abcdefg"), 
we split the string into two parts: the portion before 'c' and the portion after 'c'. 
For example, removing 'c' from "abcdefg" results in "ab" + "defg" = "abdefg".

This is achieved using:
    str.substr(0, i) + str.substr(i + 1, n - i - 1)

- str.substr(0, i): gets the substring from the beginning up to (but not including) index i
- str.substr(i + 1, n - i - 1): gets the substring from index i + 1 to the end

We use (n - i - 1) to ensure we only take the remaining characters after index i,
excluding the character at i itself.
*/

int main(){
    string str = "abc";     // Input string
    string ans = "";        // Variable to store current permutation

    // Call the recursive function with initial values
    permutations(str, ans, str.size());
    return 0;
}

// Time Complexity = O(n!)
// Space Complexity = O(n)