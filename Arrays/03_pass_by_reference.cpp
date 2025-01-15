// Pass by reference : Pass by reference means that when you pass an argument to a function, the function receives a reference 
// (or memory address) to the actual data rather than a copy of it. This allows the function to modify the original data directly.

// Note : Address is a memory location where data is stored and when we pass array as arguement to function it pass the orginal address of array that is initialized in main function.

// Note: When an array is passed to a function as an argument, its original address is passed, allowing changes made within the function to affect the main array. Therefore, we must be cautious when modifying the array.

#include<iostream>
using namespace std;

void changeArray(int arr[]){ // Here, we pass the address of orginal array arguement. 
    arr[2] = 4; // Here, any changes or operations performed on the array within the function will directly affect the original array, as the function operates on its actual memory address.
}

void sqaureArray(int arr_2[], int size){
    for (int i = 0 ; i < size ; i++){ // Here, we execute a loop over an array.
        arr_2[i] = arr_2[i]*arr_2[i]; // Here, we take each element from array and make its quare and store it at that same index
        cout<<arr_2[i]<<" ";
    } 
    cout<<endl;  
}

int main(){
    int arr[] = {1,2,3}; // Its an array with 3 int values.
    int size = sizeof(arr)/sizeof(int); // Gives, the size of array

    cout<<arr[2]<<endl; // Output : 3 (Before calling the changeArray fucntion)

    changeArray(arr); // Here, we call the changeArray function with arguement (arr) which changes the orginal data of array at particular index.
    
    cout<<arr[2]<<endl; // Output : 4 (After calling the changeArray fucntion)

    // Problem : Create a function which returns the square of value present in array.

    int arr_2[] = {2,3,4};
    sqaureArray(arr_2,size);

    for (int i = 0 ; i < size ; i++){
        // It shows that the changes within the function modify the orginal array too.
        cout<<arr_2[i]<<" ";
    }
    cout<<endl;

    return 0;
}