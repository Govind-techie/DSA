/*
  ❖ Problem 1: Count the Number of 7's in a 2D Array

  ➤ Description:
    Given a 2D array of integers, your task is to count and print the total number of times
    the digit '7' appears in the matrix.

  ➤ Example:
    Input:
        int arr[2][3] = {
            {4, 7, 8},
            {8, 8, 7}
        };
        n = 2, m = 3;

    Output: 2
*/

#include <iostream>
using namespace std;

int main(){
    int arr[2][3] = {
        {4, 7, 8},
        {8, 8, 7}
    };

    int n = 2;
    int m = 3;
    int count = 0;

    // BRUTE FORCE: O(n^2)
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (arr[i][j] == 7){
                count++;
            }
        }
    }

    cout << "Count of number 7 is : " << count << endl;
    return 0;
}