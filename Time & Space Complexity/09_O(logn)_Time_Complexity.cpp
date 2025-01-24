// O(log n) : O(log n) means the time it takes grows logarithmically with the input size, often due to algorithms that divide the problem in half at each step, like binary search.

// Graph of O(log n):

// Graph of O(log n):

// Number of Operations
//   ^
//   |
//   |                            
//   |                        
//   |                 
//   |             
//   |        *    *    *    *    * 
//   |   *  
//   | *  
//   +---------------------------------------------------> Input size (n)

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If target is found at mid, return the index
        if (arr[mid] == target)
            return mid;

        // If target is smaller than mid, search the left half
        if (arr[mid] > target)
            high = mid - 1;
        
        // If target is greater than mid, search the right half
        else
            low = mid + 1;
    }
    return -1; // Target not found
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value to search for: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}