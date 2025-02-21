/*
Pair: A pair in C++ STL is a container that holds two values of possibly different types as a single unit. 
It is useful for storing related data, such as key-value pairs.
*/

#include <iostream>
#include <vector>
#include <utility> // Note: The pair container is part of the utility library, but including the utility file is not mandatory to use it.
using namespace std;

int main() {

    // Initialization of a pair

    pair<int, int> p = {1, 3}; // A pair with both values of the same datatype.
    pair<char, int> p1 = {'a', 2}; // A pair with values of different datatypes.
    pair<string, int> p2 = {"govind", 10};

    // Note: A pair in C++ STL can only store two values, typically representing a key-value pair.

    // Accessing elements in a pair

    cout << "First element: " << p1.first << endl;  // p1.first accesses the first element of the pair.
    cout << "Second element: " << p1.second << endl; // p1.second accesses the second element of the pair.

    // Nested Pair: A nested pair is a pair where one of its elements is another pair.

    // Initialization of a nested pair
    pair<int, pair<char, int>> p3 = {1, {'a', 7}}; 
    // A nested pair where the first element is an int (1), and the second element is another pair containing a char ('a') and an int (7).

    // Accessing elements in a nested pair

    cout << "First element: " << p3.first << endl;  // Output: 1

    // cout << "Second element: " << p3.second << endl; // This would cause an error since the second element itself is a pair.

    cout << "First value of the inner pair: " << p3.second.first << endl;  // Output: 'a'
    cout << "Second value of the inner pair: " << p3.second.second << endl; // Output: 7

    // Vector of pairs

    // Initialization of a vector of pairs
    vector<pair<char, int>> vec = {{'a', 1}, {'b', 2}, {'c', 3}};

    // Difference between emplace_back() and push_back():
    // push_back() inserts an existing object, while emplace_back() constructs the object in place, making it more efficient.

    vec.push_back({'d', 5}); // Inserts the value at the back, requiring an explicitly created pair object.
    vec.emplace_back('e', 5); // Constructs the pair directly in place, avoiding unnecessary copies.

    // Iterating through the vector of pairs
    for (const auto& p : vec) {  // Using 'auto' simplifies type declaration.
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}