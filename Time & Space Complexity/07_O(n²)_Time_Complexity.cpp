// O(n²) : O(n²) means the time it takes grows quickly as the input size increases, often due to nested loops where each loop runs for the size of the input.

// Graph of O(n²):

// Number of Operations
//   ^
//   |
//   |                                            *
//   |                                       *    
//   |                                  *  
//   |                             *  
//   |                        *  
//   |                   *  
//   |              *  
//   |         *  
//   |    *  
//   | *  
//   +---------------------------------------------------> Input size (n)

// Example: O(n²)

#include<iostream>
using namespace std;

int main() {
    int n;
    int count = 0;
    
    cout << "Enter a number: ";
    cin >> n;

    // Outer loop runs n times
    for(int i = 1; i <= n; i++) {
        // Inner loop runs n times for each iteration of the outer loop
        for(int j = 1; j <= n; j++) {
            count++; // Constant operation inside the inner loop
        }
    }

    // The total number of operations is n * n, which is O(n²)
    cout << "Total operations: " << count << endl;

    return 0;
}