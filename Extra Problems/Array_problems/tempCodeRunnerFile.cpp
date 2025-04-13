// Problem : Write a function to print the intersecction (common elements) of 2 arrays.

#include<iostream>
using namespace std;

void intersectionArray(int arr_1[], int arr_2[], int size_1, int size_2){
    int commonValues[size_1];
    int commonCount = 0;

    for(int i = 0 ; i < size_1 ; i++){
        bool common = false;
        for(int j = 0 ; j < size_2 ; j++){
            if (arr_1[i] == arr_2[j]){
                common = true;
                break;
            }
        if (common == true){
            commonValues[commonCount] = arr_1[i];
            commonCount++;
        }
        }
    }

    cout<<"Common values Array : ";
    for(int i = 0 ; i < commonCount ; i++){
        cout<<commonValues[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr_1[] = {1,2,3,4};
    int arr_2[] = {1,6,9,8,3};
    int size_1 = sizeof(arr_1)/sizeof(int);
    int size_2 = sizeof(arr_2)/sizeof(int);

    intersectionArray(arr_1,arr_2,size_1,size_2);
    return 0;
}