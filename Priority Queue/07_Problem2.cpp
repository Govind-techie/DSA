/*
Problem: Connect N Ropes (Minimum Cost)

Given N ropes with different lengths, connect them all into one rope. The cost to connect two ropes is equal to the sum of their lengths. Find the minimum total cost to connect all ropes.

Input:
- First line: N (number of ropes)
- Second line: N integers (lengths of ropes)

Output:
- Minimum total cost

Example:
Input:
ropes = 4
lengths = 4 3 2 6

Output:
29
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Function to calculate the minimum cost to connect all ropes into one
void connectNRopes(vector<int> lengths) {
    // Min-heap to store the rope lengths
    priority_queue<int, vector<int>, greater<int>> pq;

    // Push all rope lengths into the min-heap
    for (int i = 0; i < lengths.size(); i++) {
        pq.push(lengths[i]);
    }

    int cost = 0; // To keep track of the total cost

    // Keep combining the two smallest ropes until only one rope is left
    while (pq.size() > 1) {
        int min1 = pq.top(); // Smallest rope
        pq.pop();

        int min2 = pq.top(); // Second smallest rope
        pq.pop();

        // Add the cost of connecting these two ropes
        cost += (min1 + min2);

        // Push the combined rope length back into the heap
        pq.push(min1 + min2);
    }

    // Output the minimum total cost
    cout << "min cost to connect ropes is " <<  cost << endl;
}

int main(){
    vector<int>lengths = {4,3,2,6};
    connectNRopes(lengths);
}