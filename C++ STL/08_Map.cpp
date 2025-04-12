/*
Map : A map is a data structure that stores key-value pairs. Each key is unique, and it is associated with a specific value. 
You can think of a map like a dictionary where each word (key) has a definition (value).

Imagine a contact list on your phone. The name of each person is the key, and their phone number is the value. If you want to 
find someone’s number, you look up their name (key), and the map gives you the corresponding number (value). You can also update 
a number (value) for a given name (key).

Common Functions Used in map
1.	insert() – Inserts a key-value pair into the map.
2.	emplace() – Constructs and inserts a key-value pair in-place.
3.	operator[] (m[key]) – Accesses or modifies the value associated with a key.
4.	count() – Checks if a key exists in the map and returns 1 if found, otherwise 0.
5.	find() – Searches for a key in the map and returns an iterator to it if found, otherwise m.end().
6.	erase() – Removes a key and its associated value from the map.
7.	end() – Returns an iterator pointing past the last element of the map.
8.	Range-based loop (for (auto p : m)) – Iterates through the map, accessing key-value pairs.

*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m; // Here, string is the key type and int is the value type.

    // Inserting key-value pairs
    m["tv"] = 100; 
    m["laptop"] = 500;
    m["Iphones"] = 200;
    m["tablet"] = 300;

    m.insert({"camera", 60});  // Insert using pair
    m.emplace("fridge", 45);   // Emplace automatically constructs in-place

    cout << m["laptop"] << endl; // Print value associated with a certain key.

    // Note: Values of different keys can be the same, but keys must be unique.

    // Displaying all items in the map
    cout << "Items in the store:\n";
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl; 
    }

    cout << "count : " << m.count("tv") << endl; // count() checks if a key exists in the map. Returns 1 if found, else 0. 
    
    // Note : (Its not a boolean value instead it is count in integer and as key should be unique it returns either 1 or 0).

    // Searching for an item using count function
    string item = "laptop";
    if (m.count(item)) {
        cout << "\n" << item << " is available with price: " << m[item] << endl;
    } else {
        cout << "\n" << item << " is not available.\n";
    }

    // Updating an item's price
    m["laptop"] = 550;
    cout << "\nUpdated price of laptop: " << m["laptop"] << endl;

    // Removing an item
    m.erase("Iphones"); // Delete mentioned key along with the value associated with that key.
    cout << "\nAfter removing 'Iphones', available items:\n";
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    // find() searches for a key in the map. If found, it returns an iterator to the key; otherwise, it returns m.end().

    if (m.find("fridge") != m.end()) { // Here, m.end() is an iterator pointing past the last element of the map. It does not point to a valid key-value pair in the map.
        cout << "Found" << endl;  
    } else {  
        cout << "\nNot Found" << endl;  
    }  
    return 0;

    // Note : m.find() function iterate over map upto m.end().
}
