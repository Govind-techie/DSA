/*
Problem: Stock Span Problem

Given an array of daily stock prices, find the span of stock’s price for all days.

The span of the stock’s price on a given day is the maximum number of consecutive days just before the given day (including the given day itself) for which the price of the stock was less than or equal to its price on the given day.

Example:
Input:  prices = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]

Constraints:
- Use stack operations to solve the problem efficiently.
- The solution should run in O(n) time.
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Function to calculate stock span
vector<int> calculateSpan(vector<int>& prices) {
    vector<int>span(prices.size());
    stack<int>s;
    span[0] = 1;
    s.push(0);

    for (int i = 1 ; i < prices.size() ; i++){
        while (!s.empty() && prices[i] >= prices[s.top()]){
            s.pop();
        }
        if (s.empty()){
            span[i] = i+1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
        s.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = calculateSpan(prices);

    for (int span : result) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}

