/*
Job Sequencing Problem (with Job Order)

Problem Statement:
Given a set of N jobs where each job i has a deadline and a profit associated with it. Each job can be executed only once and takes one unit of time. The goal is to maximize the total profit by selecting a subset of jobs to execute and also determine the order in which these jobs should be executed to achieve this maximum profit.

Input:
- An array of jobs, where each job has a deadline and a profit.
- Number of jobs N.

Output:
- The maximum total profit that can be earned by scheduling the jobs.
- The sequence (order) of jobs that should be executed to achieve this maximum profit.

Example:
Input:
jobs[] = { {2, 100, 'A'}, {1, 19, 'B'}, {2, 27, 'C'}, {1, 25, 'D'}, {3, 15, 'E'} }
N = 5
(Each inner array represents a job with {deadline, profit, job_id})

Output:
Max Profit: 142
Job Sequence: D A E

Explanation:
The optimal sequence is to schedule job D (deadline 1, profit 25) at time slot 1, job A (deadline 2, profit 100) at time slot 2, and job E (deadline 3, profit 15) at time slot 3.  Total profit = 25 + 100 + 15 = 140. The job IDs are returned in the order they are scheduled.
*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// Define a class to represent a Job
class Job {
public:
    int deadline; // Deadline of the job
    int profit;   // Profit associated with the job
    char idx;     // Index/ID of the job

    // Constructor to initialize the Job object
    Job(int deadline, int profit, char idx){
        this->deadline = deadline; // Assign the provided deadline to the job's deadline
        this->profit = profit;   // Assign the provided profit to the job's profit
        this->idx = idx;         // Assign the provided index to the job's index
    }
};

// Function to find the maximum profit and the sequence of jobs
int jobSequencing(vector<pair<int,int>>pairs){
    int n = pairs.size(); // Get the number of jobs
    vector<Job>jobs;       // Create a vector to store Job objects

    // Convert the input pairs into Job objects and store them in the jobs vector
    for (int i = 0 ; i < n ; i++){
        jobs.emplace_back(pairs[i].first , pairs[i].second,i);
        // Create a Job object with deadline, profit, and index, then add it to the jobs vector
    }

    /*
    emplace_back() in C++ STL:

    - Used to add a new element at the end of a vector.
    - More efficient than push_back() when adding complex objects.
    - It constructs the object in place (no temporary object is created).

    Example:
        vector<MyClass> vec;
        vec.emplace_back(arg1, arg2); 
        // Directly constructs MyClass(arg1, arg2) inside the vector
    */

    // Sort the jobs in descending order of profit using a lambda function
    sort(jobs.begin(),jobs.end(),[](Job &a , Job &b){return a.profit > b.profit;});
    // This lambda function compares the profit of two jobs and returns true if the first job has a higher profit

    /*
    Lambda Function in Job Scheduling:

    - A lambda is an inline, anonymous function.
    - Commonly used with sort() to define custom sorting logic.

    Example:
        sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
            return a.profit > b.profit;
        });

    Explanation:
        []                → Capture list (empty here, meaning no external variables are used)
        (Job &a, Job &b)  → Parameters: two Job objects passed by reference
        return a.profit > b.profit;
                        → Sorts jobs so that higher profit jobs come first
    */

    int safeDeadline = 0; // Keep track of the latest safe deadline
    int profit = 0;       // Initialize the total profit

    // Iterate through each job in the sorted order
    for (int i = 0 ; i < n ; i++){
        // Check if the job's deadline is greater than the current safe deadline
        if (jobs[i].deadline > safeDeadline){
            cout << "Selecting JOB - " << char('A'+jobs[i].idx) << endl;
            // Output the job ID that is being selected

            profit += jobs[i].profit; // Add the job's profit to the total profit
            safeDeadline++;           // Increment the safe deadline (schedule the job)
        }
    }

    return profit; // Return the maximum achievable profit
}

int main(){
    // Vector of pairs representing jobs (deadline, profit)
    vector<pair<int, int>> jobs = {{2, 100},{1, 19},{2, 27},{1, 25},{3, 15}};

    int maxProfit = jobSequencing(jobs);
    cout << "max profit = " << maxProfit << endl;

    return 0;
}

