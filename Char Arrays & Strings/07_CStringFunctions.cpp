/*
Important C-String Functions:

1. strlen() - Returns the length of a C-string (excluding null character '\0').
   Example: int len = strlen(str); // Returns length of 'str'

2. strcpy() - Copies one C-string to another.
   Example: strcpy(dest, str); // Copies 'str' to 'dest'

3. strcat() - Concatenates (appends) one C-string to the end of another.
   Example: strcat(string1, str2); // Appends 'str2' to 'string1'

4. strcmp() - Compares two C-strings lexicographically (returns 0 if equal).
   Example: int result = strcmp(string1, str2); // Compare 'string1' and 'str2'

5. strchr() - Finds the first occurrence of a character in a C-string.
   Example: char* ptr = strchr(str, 'o'); // Finds first 'o' in 'str'

6. strstr() - Finds the first occurrence of a substring in a C-string.
   Example: char* ptr = strstr(str, "llo"); // Finds "llo" in 'str'

7. memset() - Fills a block of memory with a specified value.
   Example: memset(arr, 'A', 10); // Fills first 10 bytes of 'arr' with 'A'

8. strtok() - Breaks a C-string into tokens based on delimiters.
   Example: char* token = strtok(str, ","); // Splits string by comma
*/

#include<iostream>
#include<cstring> // For using C-string functions like strcpy(), strcat(), strcmp()
using namespace std;

int main(){

    // 1. STRCPY(DEST, SRC) - String Copy

    char str1[100];                // Declare an empty character array
    char str2[100] = "Hello World"; // Declare and initialize another character array

    // Note: Direct assignment like str1 = "Hello"; is NOT allowed for arrays in C++.

    // Copy a string into str1
    strcpy(str1, "Hello"); 
    cout << str1 << endl;  // Output: Hello

    // Copy str2 ("Hello World") into str1
    strcpy(str1, str2); 
    cout << str1 << endl;  // Output: Hello World



    // 2. STRCAT(DEST, SRC) - String Concatenation

    char a[100] = "Hello"; // Make size large enough to hold the concatenated result
    char b[] = "World";

    strcat(a, b); 
    // strcat joins 'b' to the end of 'a': "Hello" + "World" = "HelloWorld"
    cout << a << endl; // Output: HelloWorld



    // 3. STRCMP(STR1, STR2) - String Compare

    char string1[] = "apple";
    char string2[] = "banana";

    int result = strcmp(string1, string2);

    // strcmp returns:
    // 0  -> if both strings are equal
    // <0 -> if first string is smaller
    // >0 -> if first string is greater

    cout << result << endl; // Output: negative value because "apple" < "banana"

    if(result == 0){
        cout << "Strings are equal" << endl;
    }
    else if(result < 0){
        cout << "First string is smaller" << endl;
    }
    else{
        cout << "First string is greater" << endl;
    }

    return 0;
}