/*
Problem: Reverse a String using Stack

Given a string S, reverse the string using a stack.

Example:
Input:  S = "hello"
Output: "olleh"

Constraints:
- You can only use standard stack operations: push, pop, top, and isEmpty.
- Do not use any additional data structures (like arrays or queues) for reversal logic.
- The original string should be reversed in order using the stack.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string using stack
string reverseString(string str) {
    string ans;
    stack<char> s; // Stack to store characters

    // Push each character of the string into the stack
    for (int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    // Pop characters from stack to get them in reverse order
    while (!s.empty()) {
        ans += s.top(); // Add top character to result
        s.pop();        // Remove the top character
    }

    return ans;
}

int main() {
    string str = "abcd"; // Input string
    string reversedStr = reverseString(str); // Call function to reverse
    cout << "Reversed string: " << reversedStr << endl; // Output result
    return 0;
}