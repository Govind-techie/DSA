/*
Problem: Majority Element (> n/3 times)

Given an array of integers, find and print all elements that appear more than n/3 times in the array, where n is the size of the array.

Input:
- An array of integers

Output:
- Print all elements that appear more than n/3 times. If no such element exists, print nothing.

Example:
Input: arr = [1, 2, 3, 1, 1, 2, 2]
Output: 1 2

Input: arr = [3, 3, 4, 2, 4, 4, 2, 4, 4]
Output: 4
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Function to find and print all elements that appear more than n/3 times in the array
void majorityElement(vector<int>&arr) {
    int n = arr.size();

    unordered_map<int, int> m;  // Stores frequency of each element
    unordered_set<int> s;       // Stores elements already printed

    for (int i = 0; i < n; i++) {
        m[arr[i]]++;  // Increments the count of arr[i] in the map
                      // If arr[i] is not present, it's auto-initialized to 0, then incremented to 1

        // If this element's frequency becomes > n/3 AND it hasn't been printed yet
        if (m[arr[i]] > (n / 3) && s.count(arr[i]) == 0) {
            cout << arr[i] << " ";   // Print the element
            s.insert(arr[i]);        // Mark it as printed
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 2, 2, 3, 2, 1, 1};
    majorityElement(arr);
    return 0;
}