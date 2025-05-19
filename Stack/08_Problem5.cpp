/*
Problem: Next Greater Element

Given an array of integers, for each element, find the next greater element to its right in the array.
If there is no greater element, output -1 for that position.

Example:
Input:  arr = [4, 5, 2, 25]
Output: [5, 25, 25, -1]

Constraints:
- Use stack operations to solve the problem efficiently.
- The solution should run in O(n) time.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int>ans(nums.size());
    stack<int>s;

    ans[nums.size()-1] = -1;
    s.push(nums[nums.size()-1]);

    for(int i = nums.size()-2 ; i >= 0 ; i--){
        while (!s.empty() && s.top() <= nums[i]){
            s.pop();
        }

        if (s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {6, 8, 0, 1, 3};

    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}