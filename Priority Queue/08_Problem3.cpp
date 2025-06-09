/*
Problem: Weakest Soldiers

You are given a matrix of size N x M where each row represents a group of soldiers.
Each cell contains either 1 (soldier) or 0 (civilian). Soldiers (1s) always appear before civilians (0s) in each row.
Your task is to find the indices of the K weakest rows (groups), where weakness is defined by the number of soldiers in the row.
If two rows have the same number of soldiers, the row with the lower index is considered weaker.

Input Format:
- The first line contains two space-separated integers N and M, representing the number of rows and columns respectively.
- The next N lines each contain M space-separated integers (either 0 or 1), representing the rows of the matrix.
- The last line contains a single integer K, representing the number of weakest rows to find.

Output Format:
- Print K lines, each containing a single integer — the index of one of the K weakest rows in ascending order of weakness.

Example:

Input:
5 4
1 1 0 0
1 1 1 1
1 0 0 0
1 1 0 0
0 0 0 0
3

Output:
0
2
4

Explanation:
- Row 0 has 2 soldiers.
- Row 2 has 1 soldier.
- Row 4 has 0 soldiers.
These are the three weakest rows, so their indices are printed in order.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Function to find the k weakest rows
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    // Min-heap to store pairs of (number of soldiers, row index)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Count soldiers and store in the priority queue
    for (int i = 0; i < mat.size(); i++) {
        int sol = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                sol++;
            }
        }
        pq.push({sol, i});
    }

    // Extract indices of k weakest rows
    vector<int> idx;
    for (int i = 0; i < k; i++) {
        idx.push_back(pq.top().second);
        pq.pop();
    }

    return idx;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;

    vector<int> result = kWeakestRows(mat, k);

    cout << "Indices of the " << k << " weakest rows: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}