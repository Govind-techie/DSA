/*
Problem: Sliding Window Maximum

Given an array of N integers and an integer K, find the maximum element in every contiguous subarray (window) of size K.

Input:
- First line: Two integers N (size of array) and K (window size)
- Second line: N integers representing the array

Output:
- Print the maximum element of each window, space-separated

Example:
Input:
8 3
1 3 -1 -3 5 3 6 7

Output:
3 3 5 5 6 7

Explanation:
The maximums of each window of size 3 are: [3, 3, 5, 5, 6, 7]
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void maxSlidingWindow(vector<int>& nums, int k, vector<int>&vec){
    priority_queue<pair<int,int>>pq;
    for (int i = 0 ; i < nums.size() ; i++){
        pq.push({nums[i],i});

        while (pq.top().second <= i - k){
            pq.pop();
        }

        if (i >= k - 1){
            vec.push_back(pq.top().first);
        }
    }
}

int main(){
    vector<int>nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int>vec;
    int k = 3;
    maxSlidingWindow(nums,k,vec);

    for (int i : vec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}