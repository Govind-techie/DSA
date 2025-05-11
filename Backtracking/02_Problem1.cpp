/*
Problem Statement: Find All Subsets of a String

Given a string `s`, write a program to generate all possible subsets (also known as the power set) of the string. 
The subsets can be generated in any order, and the empty subset should also be included.

Example:
Input: "abc"
Output: "", "a", "b", "c", "ab", "ac", "bc", "abc"

Note:
- Subsets do not need to be in lexicographical order.
- The input string will not contain duplicate characters.
*/

#include<iostream>
#include<string>
using namespace std;

// Function to generate all subsets of a string
void subsetString(string str, string subset, int n) {
    // Base case: If the input string is empty, print the current subset
    if (str.size() == 0) {
        cout << subset << endl; // Print the subset
        return; // End the recursion
    }

    char ch = str[0]; // Take the first character of the string

    // Recursive call: Include the current character in the subset
    subsetString(str.substr(1, str.size() - 1), subset + ch, n); // "Yes" branch: Add the character to the subset

    // Recursive call: Exclude the current character from the subset
    subsetString(str.substr(1, str.size() - 1), subset, n); // "No" branch: Do not add the character to the subset
}

int main() {
    string str = "abc"; // Input string
    string subset = ""; // Initialize an empty subset

    // Call the function to generate all subsets
    subsetString(str, subset, str.size());
    return 0;
}

// Time Complexity = O(2^n) => Exponential Time Complexity
// Space Complexity = O(n) => Linear Space Complexity
/*
RECURSION TREE

subsetString("abc", "")  // Start with the full string and an empty subset
├── Include 'a': subsetString("bc", "a")
│   ├── Include 'b': subsetString("c", "ab")
│   │   ├── Include 'c': subsetString("", "abc") → "abc"
│   │   └── Exclude 'c': subsetString("", "ab") → "ab"
│   └── Exclude 'b': subsetString("c", "a")
│       ├── Include 'c': subsetString("", "ac") → "ac"
│       └── Exclude 'c': subsetString("", "a") → "a"
└── Exclude 'a': subsetString("bc", "")
    ├── Include 'b': subsetString("c", "b")
    │   ├── Include 'c': subsetString("", "bc") → "bc"
    │   └── Exclude 'c': subsetString("", "b") → "b"
    └── Exclude 'b': subsetString("c", "")
        ├── Include 'c': subsetString("", "c") → "c"
        └── Exclude 'c': subsetString("", "") → ""
*/