/*
Minimum Absolute Difference Pairs

Problem Statement:
Given two arrays A and B of equal length N, pair up each element of array A 
with an element of array B such that the sum of absolute differences of all 
pairs is minimum.

Input:
- Two arrays A[] and B[] of equal size N
- Size of arrays: N

Output:
- Minimum sum of absolute differences of all pairs

Example:
Input:
A[] = {1, 4, 7}
B[] = {2, 5, 6}
N = 3

Output:
3

Explanation:
Pairs are: (1,2), (4,5), (7,6)
Sum of absolute differences = |1-2| + |4-5| + |7-6| = 1 + 1 + 1 = 3
*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// Function to find minimum sum of absolute differences between two arrays
int minAbsoluteDifference(vector<int>A , vector<int>B){
    // Sort both arrays to minimize differences between pairs
    sort (A.begin() , A.end());
    sort (B.begin() , B.end());

    int n = A.size();
    // Create vector of pairs to store corresponding elements from both arrays
    vector<pair<int,int>>pair(n , make_pair(0,0));

    // Match each element of sorted array A with corresponding element of sorted array B
    for (int i = 0 ; i < n ; i++){
        pair[i] = make_pair(A[i] , B[i]);
    }

    int res = 0;
    // Calculate sum of absolute differences for each pair
    for (int i = 0 ; i < n ; i++){
        res += abs(pair[i].first - pair[i].second);
    }

    return res;
}

int main(){
    // Sample input vectors
    vector<int>A = {4, 1, 8, 7};
    vector<int>B = {2, 3, 6, 5};

    cout << "min absolute diff = " << minAbsoluteDifference(A,B) << endl;
    return 0;
}