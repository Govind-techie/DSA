/*

Dutch National Flag (DNF) Algorithm : The Dutch National Flag (DNF) algorithm is an efficient algorithm used to sort an array containing
only three distinct elements (usually 0, 1, and 2). It uses the three-pointer approach to sort the array in one pass (O(n)), making it 
optimal.


Concept

The algorithm maintains three pointers:
	1.	Low (low): Marks the boundary for 0s.
	2.	Mid (mid): Traverses the array.
	3.	High (high): Marks the boundary for 2s.

	•	If nums[mid] == 0: Swap nums[low] and nums[mid], then increment both low and mid.
	•	If nums[mid] == 1: Just increment mid.
	•	If nums[mid] == 2: Swap nums[mid] and nums[high], then decrement high.

*/


#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    sortColors(nums);
    
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout<<endl;
    return 0;
}