// O(1) (Constant Time) : O(1) means the algorithm’s execution time remains constant, regardless of the input size.

// Graph of O(1) :

// Number of Operations
//   ^
//   |
//   |  *****************************
//   +---------------------------------------------------> Input Size


#include<iostream>
using namespace std;
int main(){

// Example of O(1) time complexity:

    int n;
    int sum;
    cout << "Enter a number: "; // The input size (small or large) doesn't affect the time here.
    cin >> n;
    sum = (n * (n + 1) / 2); // The number of operations is constant, regardless of the input size.
    cout << "Sum of 1 to n numbers: " << sum << endl; 

    return 0;
}