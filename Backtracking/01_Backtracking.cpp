/*
Backtracking is a general algorithmic technique that involves searching through all possible combinations to solve a problem. 
It incrementally builds candidates for the solution and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot lead to a valid solution.

Types of Backtracking:
1. Decision Problems: Finding a feasible solution that satisfies given constraints or conditions.
2. Optimization Problems: Finding the best solution (e.g., maximum or minimum) among all feasible solutions.
3. Enumeration Problems: Generating all possible solutions to a problem.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to print the elements of the array
void printArr(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

// Function to modify the array using recursion and backtracking
void changeArr(vector<int>& arr, int n, int i) {
    if (i == n) { // Base case: If we have processed all elements
        printArr(arr); // Print the current state of the array
        return; 
    }
    
    arr[i] = i + 1; // Recursive work: Assign the value (1-based index) to the current position
    changeArr(arr, n, i + 1); // Recursive call: Move to the next index
    
    arr[i] -= 2; // Backtracking step: Undo the change made during the recursive work
    // This ensures that the array is restored to its previous state for other recursive branches
}

int main() {
    // Backtracking on array

    vector<int> arr(5, 0); // Initialize an array of size 5 with all elements as 0
    int n = arr.size(); // Get the size of the array
    
    changeArr(arr, n, 0); // Start the recursive process from index 0
    printArr(arr); // Print the final state of the array after all recursive calls
    
    return 0;
}

// Note: In backtracking, the work is done after the recursive call.