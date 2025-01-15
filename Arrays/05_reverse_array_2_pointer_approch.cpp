// Reverse Array : Reverse an array means changing the order of the elements so that the first element becomes the last, the second becomes
// the second-to-last, and so on, until the entire array is flipped.

// 2 Pointer Approach : The two-pointer approach is a technique in which two pointers are used to traverse an array or list, typically 
// starting from different ends (like one pointer at the beginning and another at the end). The pointers move toward each other based on 
// certain conditions, helping solve problems efficiently.

// Reverse an array using the two-pointer approach :
// 	•	One starts at the beginning of the array.
// 	•	The other starts at the end of the array.

// You swap the elements at these two pointers, then move the pointers closer to each other until they meet in the middle. This effectively reverses the array.

// For example:

// Original Array: {1, 2, 3, 4, 5}
// 	•	Swap 1 and 5 → {5, 2, 3, 4, 1}
// 	•	Swap 2 and 4 → {5, 4, 3, 2, 1}

// Reversed Array: {5, 4, 3, 2, 1}


#include<iostream>
using namespace std;

int main(){

    // Array Input
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size]; // Initialize an array

    // Filling the array with values
    for (int i = 0 ; i < size ; i++){
        cout<<"Enter number "<<i+1<<" : ";
        cin>>arr[i];
    }

    // Prints original array
    cout << "Original Array : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2 Pointer Approach:
    int startIdx = 0; // Starting index (Pointer 1)
    int endIdx = size-1; // Ending index (Pointer 2)

    // Loop to swap elements until pointers meet
    while (startIdx <= endIdx) {
        swap(arr[startIdx], arr[endIdx]); // Swap the elements
        startIdx++;  // Move start pointer forward
        endIdx--;    // Move end pointer backward
    }

    // Prints reversed array
    cout << "Reversed Array : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

//  While Condition Explaination (<=):

//     Even-Sized Array Example

// For an array of size 6, like [1, 2, 3, 4, 5, 6]:
// 	•	Initial pointers: startIdx = 0, endIdx = 5
// 	•	We swap elements at both pointers, move the pointers towards the center, and repeat until startIdx > endIdx.

// Odd-Sized Array Example

// For an array of size 5, like [1, 2, 3, 4, 5]:
// 	•	Initial pointers: startIdx = 0, endIdx = 4
// 	•	We swap elements, and when startIdx == endIdx, the middle element stays in place.

// Why <=?
// 	•	Even-sized arrays: The loop stops when startIdx > endIdx.
// 	•	Odd-sized arrays: The loop stops when startIdx == endIdx, leaving the middle element as it is.

// This ensures the array is reversed correctly for both even and odd sizes.

}