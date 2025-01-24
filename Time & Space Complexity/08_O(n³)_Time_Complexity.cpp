// O(n³) : O(n³) means the time it takes grows very quickly as the input size increases, often due to three nested loops where each loop runs for the size of the input.

// Graph of O(n³):

// Graph of O(n³):

// Number of Operations
//   ^
//   |
//   |                                                                *
//   |                                                       *    
//   |                                              *  
//   |                                     *  
//   |                            *  
//   |                       *  
//   |                  *  
//   |             *  
//   |        *  
//   |   *  
//   | *  
//   +---------------------------------------------------> Input size (n)

// Example: O(n³)

#include<iostream>
using namespace std;

int main() {
    int n;
    int count = 0;
    
    cout << "Enter a number: ";
    cin >> n;

    // Outer loop runs n times
    for(int i = 1; i <= n; i++) {
        // Middle loop runs n times for each iteration of the outer loop
        for(int j = 1; j <= n; j++) {
            // Inner loop runs n times for each iteration of the middle loop
            for(int k = 1; k <= n; k++) {
                count++; // Constant operation inside the innermost loop
            }
        }
    }

    // The total number of operations is n * n * n, which is O(n³)
    cout << "Total operations: " << count << endl;

    return 0;
}