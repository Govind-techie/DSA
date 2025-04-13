// Problem : Write a function to print sum and product of all numbers in array.

#include<iostream>
using namespace std;


int sumArray(int arr[] , int size){
    int totalSum = 0;
    for(int i = 0 ; i < size ; i++){
       totalSum += arr[i];
    }
    return totalSum;
}

int productArray(int arr[] , int size){
    int totalProduct = 1;
    for(int i = 0 ; i < size ; i++){
       totalProduct *= arr[i];
    }
    return totalProduct;
}

int main(){
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(int);

    cout<<"The total sum of all numbers in array is : "<<sumArray(arr,size)<<endl;
    cout<<"The total product of all numbers in array is : "<<productArray(arr,size)<<endl;

    return 0;
}