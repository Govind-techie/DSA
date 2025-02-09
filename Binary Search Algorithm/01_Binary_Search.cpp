// Binary Search: A fast way to find an element in a sorted array by repeatedly dividing the search range in half. 

// Time Complexity: O(log n), as the search space reduces by half in each step.

// Binary Search works for both even-sized and odd-sized (arrays/vectors).

#include<iostream>
#include<vector>
using namespace std;

// Function to perform binary search
int binarySearch(vector<int> vec, int target, int start, int end) {
    while (start <= end) {  // Continue searching while the search range is valid
    
        int mid = start + ((end - start) / 2);  // Calculate the middle index
    
        if (target > vec[mid]) {  
            start = mid + 1;  // Target is in the right half, adjust the start index
        } 
        else if (target < vec[mid]) {  
            end = mid - 1;  // Target is in the left half, adjust the end index
        } 
        else if (target == vec[mid]) {  
            return mid;  // Target found, return its index
        }
    }
    return -1; // Target not found, return -1
}

int main() {
    vector<int> vec = {-1, 0, 3, 4, 5, 9, 12};  // Sorted array
    int target = 9;  // Element to search for
    int start = 0;  
    int end = vec.size() - 1;  // Define search range

    // Call binary search function and print the index where target is found
    cout << binarySearch(vec, target, start, end) << endl;

    return 0;
}