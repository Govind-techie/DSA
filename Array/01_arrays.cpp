// An array is a collection of elements, typically of the same data type, stored in contiguous memory locations. It allows multiple values
// to be stored under a single variable name, with each value accessible using an index.

// Properties of Arrays :

// 1. Store same type of data in it.
// 2. Contigous in memory (entire data stored together in a single memory location)
// 3 Linear data structure

// To create an Array : We have to mention the size of array and its datatype.
// eg : int marks[5]; This 5 represent the size or sub divisions in an array.

// To initialize an array with values : We mention the data we have to store in an array inside {}.
// eg : int marks[5] = {99,100,86,78,95};

// Note: An array can store fewer elements than its defined size, but it cannot store more elements than its size.

// Note: If the size of an array is not defined, it will automatically be set to the number of elements stored in it. 

// To access data within an array : We use indexing in which indexing in array start from 0 index to (size-1) index.

// Note : We can also use index to change data in an array at particular index.

// Note : we can access data within array respect to its size and index value we if we try to fetch data out of array's size it will give an error.

#include<iostream>
using namespace std;

int main(){

    int marks[5]= {99,100,86,78,95};
    
    int price[] = {20,45,60}; // Here, the size of array is automatically stored as 3 because of the elements in it.

    cout<<marks[3]<<endl; // Here, we are accessing the data in marks array using index of that particular element in an array.

    cout<<marks[2]<<endl; // Here, we print the data stored in marks array at index 2.
    marks[2] = 98; // Now, we changed the data of index 2 in marks array.
    cout<<marks[2]<<endl; // Here, it will print the new data assigned at index 2 of marks array

    cout<<sizeof(price)/sizeof(int)<<endl; // Here, we can check the size of an array which returns in form of bytes. If we want the size we
    // have to divide it by size of its respective datatype.

    return 0;
}