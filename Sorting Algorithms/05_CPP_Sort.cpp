/*
C++ STL Inbuilt Sort : sort() is a built-in function in C++ to sort containers like arrays or vectors.

Syntax:
    sort(startPointer, endPointer);
    sort(startPointer, endPointer, comparator); // Optional for custom order

Time Complexity: O(nlogn) - uses IntroSort (Hybrid of QuickSort + HeapSort + InsertionSort)
*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort in ascending order
    sort(arr, arr + n);  // Default: ascending

    // Sort in descending order
    sort(arr, arr + n, greater<int>()); 

    // greater<int>() is a comparator that sorts elements in descending order
    // It returns true if the first element is greater than the second (element1 > element2) results in descending order sorting.

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}

/*
Notes:
- sort(arr, arr+n): sorts from index 0 to n-1.
- For vectors: sort(v.begin(), v.end());
- To sort in descending order, pass comparator: greater<int>()
- Stable sort (preserves order of equal elements) → use stable_sort()
*/