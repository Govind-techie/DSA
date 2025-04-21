/*
Sort Characters in an Array

Problem : Write a program to sort an unsorted array of lowercase characters in ascending alphabetical order using the insertion sort algorithm.
You are given an array like {'d', 'a', 'e', 'c', 'b'} and your program should output the sorted array: a b c d e.

*/


#include <iostream>
using namespace std;

void charSort(char arr[] , int n){
    for (int i = 0 ; i < n ; i++){
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr){
            swap(arr[prev],arr[prev+1]);
            prev--;

        }

        arr[prev+1] = curr;
    }
}

void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main(){
    char arr[] = {'d', 'a', 'e', 'c', 'b'};

    charSort(arr, 5);
    printArray(arr, 5);
    return 0;
}