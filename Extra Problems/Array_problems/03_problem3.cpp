// Problem : Write a function to print all unique values in an array.

#include<iostream>
using namespace std;



void uniqueValues(int arr[], int size) {
    int uniqueArray[size];  // Array to store unique values
    int uniqueValueIdx = 0; // Index to track unique values in uniqueArray

    for (int i = 0; i < size; i++) {
        bool isUnique = true;

        // Check if arr[i] is already in uniqueArray
        for (int j = 0; j < uniqueValueIdx; j++) {
            if (arr[i] == uniqueArray[j]) {
                isUnique = false; // Mark as not unique
                break;
            }
        }

        // If it's unique, add it to uniqueArray
        if (isUnique) {
            uniqueArray[uniqueValueIdx] = arr[i];
            uniqueValueIdx++;
        }
    }

    // Print unique values
    cout << "Unique Array is: ";
    for (int i = 0; i < uniqueValueIdx; i++) {
        cout << uniqueArray[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,2,3,4,4,4,5,5};
    int size = sizeof(arr)/sizeof(int);

    uniqueValues(arr,size);

    return 0;
}