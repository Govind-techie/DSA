/*
Problem: Buy and Sell Stocks for Maximum Profit (Easy)

You are given a list of prices where each element represents the price of a stock on a particular day.

Your task is to buy the stock on one day and sell it on another future day, and get the maximum profit.

You are allowed to buy and sell only one time.

If it is not possible to make any profit, return 0.

Example:

Input: prices = [7, 1, 5, 3, 6, 4]
Output: 5

Explanation:
Buy at price = 1 (day 2)
Sell at price = 6 (day 5)
Profit = 6 - 1 = 5

*/  

#include <iostream>
using namespace std;

// BRUTE FORCE
int maxProfit1(int arr[], int n) {
    int maxProfit = 0;
    int currProfit = 0;

    // Try all possible pairs (buy on i, sell on j)
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Profit if bought at i and sold at j
            currProfit = arr[j] - arr[i];
            // Update maxProfit if current is better
            maxProfit = max(currProfit, maxProfit);
        }
    }
    return maxProfit;
}

// OPTIMISED (Kadane's variation)
int maxProfit2(int arr[], int n) {
    int minPrice = INT_MAX; // Stores the minimum price so far (best day to buy)
    int maxProfit = 0;
    int currentProfit = 0;

    for (int i = 0; i < n; i++) {
        // Update minPrice if a lower value is found
        if (arr[i] < minPrice) {
            minPrice = arr[i];
        }

        // Profit if bought at minPrice and sold today
        currentProfit = arr[i] - minPrice;

        // Update maxProfit if currentProfit is greater
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }
    return maxProfit;
}

int main(){
    int price[] = {7,1,5,3,6,4};
    int n = sizeof(price)/sizeof(int);

    cout << "Maximum Profit = " << maxProfit1(price,n) << endl;
    cout << "Maximum Profit = " << maxProfit2(price,n) << endl;

    return 0;
}