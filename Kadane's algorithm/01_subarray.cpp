// Subarray : A subarray is a contiguous portion of an array. This means the elements in a subarray appear in the same order as they do in
// the original array, and they are adjacent to each other.

// int arr[] = {1, 2, 3};

// All possible subarrays are:
// 	1.	Subarray with 1 element: {1}, {2}, {3}
// 	2.	Subarray with 2 elements: {1, 2}, {2, 3}
// 	3.	Subarray with 3 elements: {1, 2, 3}


#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    for(int st = 0 ; st < n ; st++){ 
        for(int end = st ; end < n ; end++){
            for(int i = st ; i <= end ; i++){
                cout<<arr[i]; // Prints all possible subarray.
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
