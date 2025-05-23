/*
Greedy Algorithm

1. What is it?
   - Make the best local choice at each step without reconsidering.

2. When does it work?
   - If the problem has:
     * Greedy-choice property: Local optimum leads to global optimum.
     * Optimal substructure: Optimal solution contains optimal solutions to subproblems.

3. Common Examples:
   - Activity Selection
   - Fractional Knapsack
   - Huffman Coding
   - Dijkstra’s, Prim’s, Kruskal’s algorithms

4. Pros:
   - Easy and fast.

5. Cons:
   - Not always optimal; requires proof; difficult to identify greedy applications.

6. How to design:
   - Identify subproblem.
   - Choose best local option.
   - Prove greedy choice works.
   - Implement.

IMP NOTE:
- Make the Greedy choice at all steps
- Choose the local optimum & hope for global optimum

Optimal Sub-structure Property:
=> A problem is said to have an optimal sub-structure if it can be divided into sub-problems whose
optimal solution are part of overall optimal solution.
*/


#include<iostream>
using namespace std;

// Largest element in Array

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    /*
    Greedy Idea:
    We want the maximum element, so at each step,
    we keep track of the best option seen so far.
    That "best-so-far" idea is what makes this greedy.
    */

    // Step 1: Assume the first element is the maximum.
    // This is our initial greedy choice.
    int maxVal = arr[0];

    // Step 2: Go through the rest of the array
    // and update maxVal if we find a better (larger) value.
    for(int i = 1; i < n; i++) {

        // Greedy Decision:
        // At each step, we ask: "Is this number better than my current best?"
        // If yes, we discard the old choice and pick the new one.

        if(arr[i] > maxVal) {
            maxVal = arr[i]; // Make the greedy choice
        }
        // Note: We don't store all values or go back — greedy is forward-only.
    }

    // Final result after greedily picking the best at each step
    cout << "Maximum element is: " << maxVal << endl;

    return 0;
}