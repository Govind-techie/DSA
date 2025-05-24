/*
Job Sequencing Problem

Problem Statement:
Given a set of N jobs where each job i has a deadline and a profit associated with it. Each job can be executed only once and takes one unit of time. The goal is to maximize the total profit by selecting a subset of jobs to execute.

Input:
- An array of jobs, where each job has a deadline and a profit.
- Number of jobs N.

Output:
- The maximum total profit that can be earned by scheduling the jobs.

Example:
Input:
jobs[] = { {2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15} }
N = 5
(Each inner array represents a job with {deadline, profit})

Output:
142

Explanation:
The optimal sequence is to schedule job 1 (deadline 2, profit 100) at time slot 2, job 4 (deadline 1, profit 25) at time slot 1, and job 5 (deadline 3, profit 15) at time slot 3.  Total profit = 100 + 25 + 15 = 140
*/

#include<iostream>
#include<utility>
#include<vector>
using namespace std;

// Custom comparator to sort jobs based on profit (descending order)
bool compare(pair<int,int>p1 , pair<int,int>p2){
    return p1.second > p2.second; // Sort by profit in descending order
}

// Function to calculate the maximum profit using job sequencing
int jobSequencing(vector<pair<int,int>>p){
    int n = p.size(); // Number of jobs
    int safeDeadline = 0; // Keep track of the latest safe deadline
    int profit = 0; // Initialize total profit

    // Sort jobs by profit in descending order
    sort(p.begin() , p.end() , compare);

    // Iterate through each job
    for (int i = 0 ; i < n ; i++){
        // If the job's deadline is greater than the current safe deadline
        if (p[i].first > safeDeadline){
            profit += p[i].second; // Add the job's profit to the total profit
            safeDeadline++; // Increment the safe deadline (schedule the job)
        }
    }
    return profit; // Return the maximum achievable profit
}

int main(){
    // Vector of pairs representing jobs (deadline, profit)
    vector<pair<int,int>>p = { {2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15} };
    cout << "Max Profit = " << jobSequencing(p) << endl; // Output the maximum profit
}