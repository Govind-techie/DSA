/*
  ❖ Problem 2: Print the Sum of the Numbers in the Second Row of the "nums" Array

  ➤ Description:
    Given a 2D array of integers named "nums", your task is to calculate and print the sum
    of the numbers present in the second row of the array.

  ➤ Example:
    Input:
        int nums[3][3] = {
            {1, 4, 9},
            {11, 4, 3},
            {2, 2, 3}
        };
    
    Output: 18
*/

#include <iostream>
using namespace std;

int main(){
    int nums[3][3] = {
        {1, 4, 9},
        {11, 4, 3},
        {2, 2, 3}
    };

    int n = 3;
    int m = 3;
    int sum = 0;
    int row2 = 1;

    for (int i = 0 ; i < m ; i++){
        sum += nums[row2][i];
    }

    cout << "2nd Row Sum = " << sum << endl;
    return 0;
}