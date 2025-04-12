// Problem: Find the largest value in an array.

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array: "; // Taking array size from user at runtime.
    cin >> n;

    int arr[n]; // Array is created using user input size. This is called dynamic sizing (works in some compilers like GCC).

    for (int i = 0 ; i < n ; i++){
        cout << "Enter a number: ";
        cin >> arr[i]; // Taking input for each element of the array.
    }

    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " "; // Printing each element of the array.
    } 
    cout << endl;
    
    int currentLargest = arr[0];
    for (int i = 0 ; i < n ; i++){
        if (arr[i] > currentLargest){
            currentLargest = arr[i];
        }
    }

    cout << "Largest value in array is : " << currentLargest << endl;
    return 0;
}