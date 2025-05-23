/*
Activity Selection Problem

Problem Statement:
Given N activities with their start and finish times, select the maximum number of activities 
that can be performed by a single person, assuming that a person can only work on a single 
activity at a time.

Input:
- An array of start times: start[] 
- An array of finish times: finish[]
- Number of activities: N

Output:
- The maximum number of non-overlapping activities that can be performed.

Example:
Input:  
start[]  = {1, 3, 0, 5, 8, 5}
finish[] = {2, 4, 6, 7, 9, 9}
N = 6

Output: 
4

Explanation:
The selected activities are at index 0 (1-2), 1 (3-4), 3 (5-7), and 4 (8-9).
*/

#include<iostream>
#include<vector>
using namespace std;

int activitySelection(vector<int> st, vector<int> en) {
    int currEnd = en[0]; // end time of first selected activity
    int count = 1; // first activity is always selected

    for (int i = 1; i < st.size(); i++) {
        if (currEnd <= st[i]) { // if current activity starts after previous ends
            count++; // select the activity
            currEnd = en[i]; // update end time
        }
    }

    return count; // total selected activities
}

int main() {
    vector<int> st = {1, 3, 0, 5, 8, 5};
    vector<int> en = {2, 4, 6, 7, 9, 9};

    cout << "Activity Selected : " << activitySelection(st, en) << endl;
    return 0;
}

/*
Proof for Greedy Choice in Activity Selection Problem

Prove it by contradiction:

1. Assume the greedy algorithm gives a solution G = {A1, A2, ..., Ak}
   and there exists another optimal solution O = {B1, B2, ..., Bm}
   such that m > k (i.e., O has more activities than G).

2. Compare the first activity in both solutions.
   Since the greedy algorithm picks the activity with the earliest end time,
   end(A1) <= end(B1)

3. Since activities are non-overlapping:
   end(A1) <= start(A2)
   end(B1) <= start(B2)

4. Replace B1 in O with A1.
   A1 finishes no later than B1, so A1 doesn't conflict with the rest of B2, B3, ...
   This new solution is still valid and has the same number of activities as O.

5. Repeat this replacement for all Ai in G.
   Eventually, we can transform O into a new optimal solution using the greedy choices.
   This contradicts the assumption that O had more activities than G.

Therefore, the greedy solution is also optimal.

Conclusion:
Choosing the earliest finishing activity leaves the most time available for remaining activities.
This leads to the maximum number of non-overlapping activities.
*/