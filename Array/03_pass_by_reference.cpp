// Pass by reference: It means when we pass an argument to a function, the function receives a reference 
// (or memory address) of the actual data, not a copy. This allows the function to modify the original data directly.

// Note: An address is the memory location where data is stored. When we pass an array as an argument to a function, 
// we pass the original address of the array created in the main function.

// Note: Since arrays are passed by reference, any changes made inside the function will directly affect the original array. 
// So, we must be careful while modifying arrays inside functions.

#include<iostream>
using namespace std;

void changeArray(int arr[]){ // Receives the address of the original array.
    arr[2] = 4; // Modifies the value at index 2 in the original array using the passed address.
}

void sqaureArray(int arr_2[], int size){
    for (int i = 0 ; i < size ; i++){ // Loop through each element of the array.
        arr_2[i] = arr_2[i]*arr_2[i]; // Square the element and store it back in the same index.
        cout<<arr_2[i]<<" ";
    } 
    cout<<endl;  
}

int main(){
    int arr[] = {1,2,3}; // Declares an array with 3 integers.
    int size = sizeof(arr)/sizeof(int); // Calculates the number of elements in the array.

    cout<<arr[2]<<endl; // Output before function call: 3

    changeArray(arr); // Calls the function that changes the value at index 2 in the original array.
    
    cout<<arr[2]<<endl; // Output after function call: 4

    // Problem: Create a function to square each element in an array.

    int arr_2[] = {2,3,4};
    sqaureArray(arr_2,size); // Squares each element and prints the result inside the function.

    for (int i = 0 ; i < size ; i++){
        // This shows that changes made inside the function have modified the original array.
        cout<<arr_2[i]<<" ";
    }
    cout<<endl;

    return 0;
}