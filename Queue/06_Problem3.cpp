/*
Problem Statement: First Non-Repeating Character in a Stream

Description:
- Given a stream of lowercase characters (one character at a time), for each character added to the stream, print the first non-repeating character so far. 
- If there is no non-repeating character, print -1.

Input:
- A string S representing the stream of characters.

Output:
- For each character in the stream, output the first non-repeating character at that point. If none exists, output -1.

Example:
Input:  aabc
Output: a -1 b b

Explanation:
- After reading 'a' -> first non-repeating: a
- After reading 'a' -> no non-repeating: -1
- After reading 'b' -> first non-repeating: b
- After reading 'c' -> first non-repeating: b
*/

#include<iostream>
#include<queue>
#include<string>
using namespace std;

// Function to return a string with the first non-repeating character at every index
string nonRepeatingChar(string str){
    int freq[26] = {0}; // Frequency array to count occurrences of each character (assuming lowercase a-z)
    queue<char> q; // Queue to maintain order of characters
    string s = ""; // Final answer string to store non-repeating characters

    // Traverse the input string
    for (int i = 0 ; i < str.size() ; i++){
        char ch = str[i]; // Current character

        q.push(ch); // Push current character into the queue
        freq[ch - 'a']++; // Update frequency count (convert char to index by subtracting 'a')

        // Remove characters from the front of the queue until we find a non-repeating one
        while (!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop(); // Pop if it's repeating
        }

        // After the loop, the front of the queue is the first non-repeating character (if any)
        if (q.empty()){
            s += "-1 "; // If queue is empty, no non-repeating character found
        } else {
            s += q.front(); // Append the non-repeating character to result
            s += " "; // Add space to separate values
        }
    }

    return s; // Return the final string
}

int main(){
    string str = "aabc";

    cout << nonRepeatingChar(str) << endl;
    return 0;
}