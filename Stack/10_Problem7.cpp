/*
Problem: Check for Double Parentheses

Given a string containing parentheses and possibly other characters, determine if the string contains any double parentheses.
Double parentheses mean there is a pair of opening and closing parentheses with nothing (or only spaces) between them, like "(())" or "()".

Example:
Input:  s = "((a+b))"
Output: true   // There are double parentheses around "a+b"

Input:  s = "(a + (b))"
Output: true   // The inner "(b)" is double parentheses

Input:  s = "(a + b)"
Output: false  // No double parentheses

Constraints:
- Use stack operations to solve the problem efficiently.
- Ignore non-parenthesis characters when checking for double parentheses.
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to check if the expression contains duplicate parentheses
bool hasDuplicateParentheses(string exp) {
    stack<char> st;  // stack to keep track of characters

    // Iterate over each character in the expression
    for (int i = 0; i < exp.size(); i++) {
        // When we encounter a closing parenthesis ')'
        if (exp[i] == ')') {
            int count = 0;  // count characters inside the current parentheses

            // Pop characters from stack until we find the matching opening '('
            // These popped characters are the contents inside the parentheses
            while (!st.empty() && st.top() != '(') {
                st.pop();
                count++;  // count increments for each character inside parentheses
            }

            // Pop the opening '(' from the stack
            if (!st.empty()) 
                st.pop();

            // If count is zero, it means there were no characters inside the parentheses,
            // which means the parentheses are duplicate/redundant like "()"
            if (count == 0) 
                return true;
        } else {
            // For any character other than ')', just push it onto the stack
            st.push(exp[i]);
        }
    }

    // If no duplicate parentheses found in the entire expression
    return false;
}

int main() {
    string expr;
    cout << "Enter the expression: ";
    cin >> expr;

    if (hasDuplicateParentheses(expr)) {
        cout << "Duplicate parentheses found.\n";
    } else {
        cout << "No duplicate parentheses.\n";
    }

    return 0;
}