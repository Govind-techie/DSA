// Recursive Binary Search : Recursive Binary Search is a searching algorithm that repeatedly divides a sorted array into halves 
// to find a target element. It calls itself on the left or right half based on comparisons until the element is found 
// or the search space becomes empty.

// Time Complexity (Recursive Binary Search) : O(logn)

// Note: The iterative approach is more efficient than the recursive approach in terms of space usage.  
// • Iterative approach → Space Complexity: O(1) (No extra memory used)  
// • Recursive approach → Space Complexity: O(log n) (Due to recursive call stack)  

#include<iostream>
#include<vector>
using namespace std;

// Recursive function for Binary Search
int recursiveBinarySearch(vector<int> vec, int start, int end, int target) {
    if (start <= end) { // Base condition: If the search space is valid
        int mid = start + (end - start) / 2; // Calculate mid index to avoid overflow

        // If target is greater than mid element, search in the right half
        if (target > vec[mid]) { 
            return recursiveBinarySearch(vec, mid + 1, end, target); 
        }
        // If target is smaller than mid element, search in the left half
        else if (target < vec[mid]) { 
            return recursiveBinarySearch(vec, start, mid - 1, target); 
        }
        // If target is equal to mid element, return the index (found)
        else { 
            return mid;
        }
    }
    return -1; // Target not found, return -1
}

int main() {
    vector<int> vec = {1, 5, 6, 9, 11, 16}; // Sorted input array
    int start = 0;
    int end = vec.size() - 1; // Last index of the array
    int target = 11; // Element to search

    cout << recursiveBinarySearch(vec, start, end, target) << endl; // Call function and print result

    return 0;
}

// Recursion Breakdown:

// 1st Function Call: recursiveBinarySearch(vec, 0, 5, 11);

// • start = 0, end = 5
// • mid = (0 + 5) / 2 = 2
// • vec[mid] = 6
// • Since 11 > 6, search in the right half:
//   recursiveBinarySearch(vec, 3, 5, 11);

// 2nd Function Call: recursiveBinarySearch(vec, 3, 5, 11);

// • start = 3, end = 5
// • mid = (3 + 5) / 2 = 4
// • vec[mid] = 11
// • Since target == vec[mid], return mid = 4
