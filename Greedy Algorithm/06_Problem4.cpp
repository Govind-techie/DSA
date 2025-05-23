/*
Maximum Length Chain of Pairs

Problem Statement:
You are given n pairs of numbers. In every pair, the first number is always smaller 
than the second number. A pair (a, b) can come after pair (c, d) if b < c. 
Find the longest chain which can be formed from a given set of pairs.

Input:
- Array of pairs where each pair has two numbers
- Number of pairs: N

Output:
- Length of longest chain that can be formed

Example:
Input:
pairs[] = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}}
N = 5

Output:
3

Explanation:
Longest chain that can be formed is: {5, 24} -> {27, 40} -> {50, 90}
Each pair's second number is less than next pair's first number, forming a valid chain.
*/

#include<iostream>
#include<utility>
using namespace std;

// Function to compare pairs based on the end time
// This is used to sort the pairs by their end time in ascending order
bool compare (pair<int,int>p1 , pair<int,int>p2){
    return p1.second < p2.second;
}

// Function to find the maximum length of chain that can be formed
int maxChainLength(vector<pair<int,int>>p){ // O(nlogn) -> Time Complexity
    int n = p.size(); // Get the number of pairs (activities)
    
    // Sort the pairs based on the end time using the compare function
    sort(p.begin() , p.end() , compare);

    int chainLen = 1; // Start with the first pair, count it as part of the chain
    int lastEnd = p[0].second; // Initialize the last end time to the end of the first activity

    // Iterate through the rest of the pairs
    for (int i = 1 ; i < n ; i++){
        // If the start time of the current activity is greater than the last activity's end time
        // This means we can add this activity to the chain
        if (p[i].first > lastEnd){
            chainLen++; // Increase the chain length
            lastEnd = p[i].second; // Update the last end time to the current activity's end time
        }
    }

    // Return the maximum length of the chain
    return chainLen;
}

int main(){
    // Define a vector of pairs where each pair represents (start, end) time of an activity
    vector<pair<int,int>>p = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    
    // Call the function to get the max length of the chain and print the result
    cout << "max length of chain = " << maxChainLength(p) << endl;
    return 0;
}

/*
NOTE: This problem is a variation of the original Activity Selection Problem.
In this variation, we are given pairs of (start, end) points and we need to find 
the maximum length of chain where the next pair can only be taken if its start 
is greater than the end of the previous selected pair.
*/