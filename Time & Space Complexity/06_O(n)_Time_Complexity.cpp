// O(n) (Linear Time): O(n) time complexity means that the algorithm’s execution time grows linearly with the size of the input n.

// // Graph of O(n):

// Number of Operations
//   ^
//   |
//   |                           *
//   |                        *
//   |                     *
//   |                  *
//   |               *
//   |            *
//   |         *
//   |      *
//   |   *
//   +---------------------------------------------------> Input Size (n)

// Eg : O(n)

#include<iostream>
using namespace std;

int main(){
    int n;
    int fact = 1;
    cout<<"Enter a number : ";
    cin>>n;

    for(int i = 1 ; i <= n ; i++){ // As the loops run n times 
        fact *= i; // but the operation performing inside loop is constant. Therefore, the complexity is O(n).
    }

    cout<<"Factorial of "<< n <<" is : "<< fact << endl;

    return 0;
}