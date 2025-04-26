/*
 For-Each Loop (Range-based For Loop) in C++

 Definition:
 The for-each loop is used to iterate over each element in a container (like an array, vector, etc.) without using an explicit index. 
 It automatically accesses each element in the container one by one.

 General Syntax:
 for (datatype element : container) {
     // Use 'element' to access each value in the container
 }

 - 'datatype' : The type of the element (int, char, etc.).
 - 'element' : The variable that will hold the current element during each iteration.
 - 'container' : The collection (array, vector, etc.) that is being iterated over.

 Example:
 int arr[] = {1, 2, 3, 4, 5};

 // For-each loop to print each element of the array
 for (int num : arr) {
     cout << num << " ";  // Output: 1 2 3 4 5
 }
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "Hello World!";

    // Prints all individual character of string using for loop.
    for (int i = 0 ; i < str.length() ; i++){
        cout << str[i] << " ";
    } cout << "\n";

    // Prints all individual character of string using for each loop.

    for (char ch : str){
        cout << ch << " "; // In for each loop each character of str is stored in variable ch which is used for printing.
    } cout << "\n";

    return 0;
}
