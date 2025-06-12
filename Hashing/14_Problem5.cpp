/*
Problem: Union and Intersection of Two Arrays

Given two arrays of integers, find:
1. The union of the arrays (all unique elements present in either array).
2. The intersection of the arrays (elements present in both arrays).

Input:
- Two arrays of integers

Output:
- The union as a list of unique elements
- The intersection as a list of common elements

Example:
Input: arr1 = [1, 2, 3, 4], arr2 = [3, 4, 5, 6]
Union: [1, 2, 3, 4, 5, 6]
Intersection: [3, 4]
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void Union(vector<int>arr1, vector<int>arr2){
    unordered_set<int>s;
    for (int i : arr1) s.insert(i);
    for (int i : arr2) s.insert(i);

    for (int i : s){
        cout << i << " ";
    }
    cout << endl;
}

void Intersection(vector<int>arr1,vector<int>arr2){
    unordered_map<int,int>m;
    for (int i : arr1) m[i]++;
    
    for (int i : arr2){
        if (m[i] > 0){
            cout << i << " ";
            m[i] = 0;
        }
    }
    cout << endl;
}

int main(){
    vector<int>arr1 = {1,2,3,4};
    vector<int>arr2 = {3,4,5,6};
    Union(arr1,arr2);
    Intersection(arr1,arr2);
    return 0;
}