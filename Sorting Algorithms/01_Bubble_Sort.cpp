/* 
Bubble Sort : Bubble Sort is a simple sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order.
This process continues until the array is fully sorted. It works by "swaping" the largest (or smallest) element to the correct position
in each pass.

Time Complexity : O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

// Bubble Sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0 ; i < n - 1 ; i++) {
        bool isSwap = false;
        for (int j = 0 ; j < n - i - 1 ; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }

        if (!isSwap){ // / If no swap occurred, array is sorted, so exit early
            return;
        }

    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 1, 5, 2, 3};

    // Calling the Bubble Sort function
    bubbleSort(arr);

    // Printing the sorted array
    printArray(arr);

    return 0;
}