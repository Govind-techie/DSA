/*
Problem: Tiling Problem (Google, Amazon)

Description:
- You are given a floor of size 2 x n and tiles of size 2 x 1.
- Your task is to count the number of ways to tile the entire floor using these tiles.
- A tile can either be placed vertically (covering 1 x 2 area) or horizontally (covering 2 x 1 area).

Example:
Input: n = 3
Output: 3
Explanation:
- There are 3 ways to tile a 2 x 3 floor:
  1. Place all tiles vertically.
  2. Place one tile horizontally and the rest vertically.
  3. Place two tiles horizontally and one vertically.

Constraints:
- Assume n >= 1.

Note:
- This problem is frequently asked in technical interviews at companies like Google and Amazon.
*/

#include<iostream>
using namespace std;

// Recursive function to solve the Tiling Problem
int tillingProblem(int n) {
    // Base case: If the floor size is 0 or 1, there is only 1 way to tile it
    if (n == 0 || n == 1) {
        return 1;
    }
    // NOTE: For n = 0, placing no tiles is considered a valid way (1 way).
    // For n = 1, only one vertical tile can be placed (1 way).

    // Recursive case:
    // Option 1: Place one tile vertically, reducing the problem to size (n-1)
    int v = tillingProblem(n - 1);

    // Option 2: Place two tiles horizontally, reducing the problem to size (n-2)
    int h = tillingProblem(n - 2);

    // Total ways to tile the floor is the sum of both options
    return v + h;
}

int main() {
    // Test cases to demonstrate the Tiling Problem
    cout << "Tiling Problem Results:" << endl;

    // Example 1: n = 3
    int n1 = 3;
    cout << "Number of ways to tile a 2 x " << n1 << " floor: " << tillingProblem(n1) << endl;

    // Example 2: n = 4
    int n2 = 4;
    cout << "Number of ways to tile a 2 x " << n2 << " floor: " << tillingProblem(n2) << endl;

    // Example 3: n = 5
    int n3 = 5;
    cout << "Number of ways to tile a 2 x " << n3 << " floor: " << tillingProblem(n3) << endl;

    // Example 4: n = 6
    int n4 = 6;
    cout << "Number of ways to tile a 2 x " << n4 << " floor: " << tillingProblem(n4) << endl;

    return 0;
}

/*
Explanation:

1. Base Case:
   - If n == 0, there is exactly 1 way to tile the floor (by placing no tiles).
   - In n == 1, there is exactly 1 way to tile the floor (by placing one vertical tile).

2. Recursive Case :
   - To solve the problem for a floor of size 2 x n, we consider two possibilities:
     - Place one tile vertically, which reduces the problem to a floor of size 2 x (n-1).
     - Place two tiles horizontally, which reduces the problem to a floor of size 2 x (n-2).

3. Recursive Formula:
   - The total number of ways to tile the floor is the sum of the two possibilities:
    
    -> ways(n) = ways(n-1) + ways(n-2)

5. Time Complexity:
   - The recursive solution has a time complexity of O(2^n) because each call branches into two more calls.

6. Space Complexity:
   - The space complexity is O(n) due to the recursion stack.

7. Optimization:
   - This problem can be optimized using Dynamic Programming (DP) to reduce the time complexity to O(n) by storing the results of subproblems in an array.

*/