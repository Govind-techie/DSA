/*
Problem: Remove Duplicates in a String (Google, Microsoft)

Description:
- Given a string, remove all duplicate characters from it while maintaining the order of characters in the original string.
- The result should contain only the first occurrence of each character.

Example:
Input: "aabbccdde"
Output: "abcde"

Input: "google"
Output: "gole"

Constraints:
- The input string contains only lowercase English letters.

Note:
- This problem is frequently asked in technical interviews at companies like Google and Microsoft.
*/

#include<iostream>
#include<string>
using namespace std;

// TIME COMPLEXITY -> O(n)

string removeDuplicate(string str, bool track[], string ans, int i, int n) {
    // BASE CASE: If we reach the end of the string, return the answer string
    if (i == n) return ans;

    // Calculate the index for the current character
    int idx = str[i] - 'a';

    // If the character is not already tracked, add it to the result
    if (!track[idx]) {
        ans += str[i];
        track[idx] = true; // Mark the character as seen
    }

    // Recursive call for the next character
    return removeDuplicate(str, track, ans, i + 1, n);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Boolean array to track seen characters
    bool track[26] = {false}; // Initialize all values to false

    string result = removeDuplicate(str, track, "", 0, str.size());

    cout << "String after removing duplicates: " << result << endl;

    return 0;
}

/*
DETAIL EXPLANATION AND DRY RUN :-

- The goal is to remove all duplicate characters from a string while maintaining the order of characters.
- For example:
  - Input: "google"
  - Output: "gole"
  - Input: "aabbccdde"
  - Output: "abcde"

Approach:
1. Tracking Characters:
   - Use a boolean array track[26] to track whether a character has already been processed.
   - Each index in the array corresponds to a character ('a' → 0, 'b' → 1, ..., 'z' → 25).

2. Recursive Function:
   - Process one character at a time.
   - If the character has not been seen before, add it to the result string and mark it as seen in the track array.
   - Move to the next character using recursion.

3. Base Case:
   - If the index i reaches the length of the string (n), return the result string.

4. Recursive Case:
   - Check if the current character has been seen:
     - If yes, skip it.
     - If no, add it to the result and mark it as seen.
   - Make a recursive call for the next character.

Example Walkthrough:

Input: "google"

1. Start with i = 0, ans = "", and track = {false, false, ..., false}.
2. Process 'g' (index 6):
   - Not seen → Add to ans → ans = "g", mark track[6] = true.
3. Process 'o' (index 14):
   - Not seen → Add to ans → ans = "go", mark track[14] = true.
4. Process 'o' (index 14):
   - Already seen → Skip.
5. Process 'g' (index 6):
   - Already seen → Skip.
6. Process 'l' (index 11):
   - Not seen → Add to ans → ans = "gol", mark track[11] = true.
7. Process 'e' (index 4):
   - Not seen → Add to ans → ans = "gole", mark track[4] = true.

Final Output: "gole"
*/