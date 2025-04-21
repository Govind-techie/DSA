
/*
COUNTING SORT:

Counting Sort is a non-comparison-based sorting algorithm. It works by:
1. Counting how many times each value appears.
2. Using that count to place elements in their correct sorted position.

Note:
- Efficient only when the range of elements is small.
*/
#include <iostream>
using namespace std;


// Function to perform Counting Sort
int countingSort(int arr[], int n){
    int freq[100000] = {0}; // Frequency array to count occurrences of each element (assuming elements ≤ 99999)
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Step 1: Find the minimum and maximum elements in the array
    // This helps to determine the range of input values
    for (int i = 0 ; i < n ; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    // Step 2: Count the frequency of each element in the input array
    // We increment the index corresponding to each value
    for (int i = 0 ; i < n; i++){
        freq[arr[i]]++;
    }
    
    // Step 3: Reconstruct the sorted array using the frequency array
    // Traverse from minVal to maxVal and place each value back into original array
    for(int i = minVal, j = 0 ; i <= maxVal ; i++){
        while (freq[i] > 0){        // Place value 'i' as many times as its count
            arr[j++] = i;           // Assign current value to the array and move to next index
            freq[i]--;              // Decrease count after placing the value
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {1, 4, 3, 2, 1, 2, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}