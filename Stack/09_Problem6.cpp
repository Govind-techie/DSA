/*
Problem: Valid Parenthesis

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

A string is valid if:
1. Open brackets are closed by the same type of brackets.
2. Open brackets are closed in the correct order.

Example:
Input:  s = "{[()]}"
Output: true

Input:  s = "{[(])}"
Output: false

Constraints:
- Use stack operations to solve the problem efficiently.
- The solution should check for correct matching and order of brackets.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char>st;
        
    for(int i = 0 ; i < s.size() ; i++){
        if (s[i] == '(' ||  s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }else{
            if (st.empty()){
                return false;
            }
            if ((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']')){
                st.pop();
            }else{
                return false;
            }
        }
    }

    return st.empty();
}


int main() {

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";

    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;

    return 0;
}