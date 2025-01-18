// Static Memory Allocation : Static memory allocation is the process of allocating fixed memory at compile time, before the program runs.
// Dynamic Memory Allocation : Dynamic memory allocation is the process of allocating memory at runtime, as needed by the program.

// Note : Static memory is allocated in stack memory whereas Dynamic memory is allocated in heap memory.


#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[5]; // In case of array, fixed memory (5) is allocated at compile time.

    vector<int> vec; // Memory is allocated dynamically as elements are added at when code is executed in runtime.
    vec.push_back(10);    // Adds an element to the vector, dynamically resizing the memory if the current capacity is exceeded.
    vec.push_back(20);  

    // Note: When we push back a value into a vector, if the current capacity is exceeded, the vector resizes dynamically by doubling its previous capacity.

// Properties of vector:
// 1. size: The number of elements currently stored in a vector is called its size.
// 2. capacity: The maximum number of elements a vector can hold without resizing it dynamically in memory is called its capacity.

    vector<int>vec_2;
    vec_2.push_back(1);
    vec_2.push_back(2);
    vec_2.push_back(3);

    cout<<vec_2.size()<<endl; // (size = 3) No. of elements stored in a vector.
    cout<<vec_2.capacity()<<endl; // Here, we used capacity function to print vector's capacity. (capacity = 4). No. of elements that can be stored in a vector.

    return 0;
}