/*
Fractional Knapsack Problem

Problem Statement:
Given weights and values of N items, and a knapsack with capacity W, 
find the maximum total value in the knapsack. You can take fractions of items.

A knapsack is just a bag with a weight limit, and the problem is about choosing items to maximize value without exceeding that limit.

Input:
- An array of item values: value[]
- An array of item weights: weight[]
- Number of items: N
- Knapsack capacity: W

Output:
- Maximum total value that can be put in the knapsack (can include fractions of items).

Example:
Input:
value[]  = {60, 100, 120}
weight[] = {10, 20, 30}
N = 3
W = 50

Output:
240.0

Explanation:
Take all of item 1 (10), all of item 2 (20), and 2/3 of item 3 (20 out of 30).
*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// Sort items by value/weight ratio in descending order (highest ratio first)
bool compare (pair<double,int>p1 , pair<double,int>p2){
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int>val , vector<int>wt, int W){ // O(nlogn) => Time Complexity
    int n = val.size();
    // Create vector of pairs to store (value/weight ratio, index) for each item
    vector<pair<double,int>>ratio(n,make_pair(0.0 , 0));

    // Calculate value/weight ratio for each item
    for (int i = 0 ; i < n ; i++){
        double r = (double(val[i]/(double)wt[i]));
        ratio[i] = make_pair(r,i);
    }

    // Sort items by their value/weight ratio (highest first)
    sort(ratio.begin() , ratio.end() , compare);
    
    int ans = 0;
    // Process items in sorted order
    for (int i = 0 ; i < n ; i++){
        int idx = ratio[i].second;
        
        // If we can take the whole item, take it
        if (wt[idx] <= W){
            ans += val[idx];
            W -= wt[idx];
        }
        // If we can't take the whole item, take a fraction of it
        else{
            ans += ratio[i].first * W;  // (value/weight) * remaining weight
            W = 0;
            break;  // Knapsack is full
        }
    }
    return ans;
}

int main(){
    // Value of each item
    vector<int>val = {60,100,120};
    // Weight of each item
    vector<int>wt = {10,20,30};
    int W = 50; // Maximum weight capacity of knapsack

    cout << "Max Value : " << fractionalKnapsack(val,wt,W) << endl; 
}