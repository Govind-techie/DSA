/*
Problem: Maximum Area in Histogram

Given an array representing the heights of bars in a histogram, find the area of the largest rectangle that can be formed within the bounds of the histogram.

Example:
Input:  heights = [2, 1, 5, 6, 2, 3]
Output: 10
Explanation: The largest rectangle has area 10 (formed by heights[2] and heights[3], both of height 5 and 6, width 2).

Constraints:
- Use stack operations to solve the problem efficiently.
- The solution should run in O(n) time.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int>st;
    vector<int>nsr(n);
    vector<int>nsl(n);
    int area;
    int maxArea = 0;

    for (int i = 0 ; i < n ; i++){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if (st.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n-1 ; i >= 0 ; i--){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if (st.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 0 ; i < n ; i++){
        area = heights[i] * (nsr[i] - nsl[i] - 1);
        maxArea = max(area,maxArea);
    }

    return maxArea;
}

int main() {
    int n;
    cout << "Enter number of bars in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxArea = largestRectangleArea(heights);
    cout << "Maximum area in histogram: " << maxArea << endl;

    return 0;
}


/*
Visual representation of histogram bars:
(each number represents bar height)

Index:      0   1   2   3   4   5
Heights:    2   1   5   6   2   3

Histogram:
      |       |
      |   |   |       |
      |   |   |   |   |
      |   |   |   |   |   |
      |   |   |   |   |   |
      -------------------------
      0   1   2   3   4   5   (Indices)

From this, the largest rectangle is height = 2, width = 4 (bars 2 to 5)
So max area = 2 * 4 = 8
*/
