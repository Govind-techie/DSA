// Problem : Write a function to swap the maximum and minimum number

#include<iostream>
using namespace std;

void swapMaxAndMin(int arr[], int size){
    int min = INT_MAX;
    int max = INT_MIN;
    int minIdx = -1;
    int maxIdx = -1;

    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max){
            max = arr[i];
            maxIdx = i;
        }
    }
    for (int i = 0 ; i < size ; i++){
        if (arr[i] < min){
            min = arr[i];
            minIdx = i;
        }
    }

    swap(arr[maxIdx],arr[minIdx]);     
}

int main(){

    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(int);

    swapMaxAndMin(arr,size);

    cout<<"Swapped array is : ";
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
