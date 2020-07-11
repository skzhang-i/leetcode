#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		if (target > nums[nums.size() - 1])
			return nums.size();
		// Binary search.
		int low = 0;
		int high = (int)nums.size() - 1;
		while (low <= high) {
			int mid = (high - low) / 2 + low;
			if (target <= nums[mid] && (mid == 0 || target > nums[mid - 1])) {
				return mid;
			}
			else if (target > nums[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return -1;	// Bad result.
	}

	void displaySample() {
		vector<int> v1 = { 1, 3, 5, 6 };
		int t1 = 5, t2 = 2, t3 = 7, t4 = 0;
		cout << "Sample 1" << endl << "Input: [1,3,5,6], 5" << endl << "Output: "
			<< searchInsert(v1, t1) << endl;
		cout << "Sample 2" << endl << "Input: [1,3,5,6], 2" << endl << "Output: "
			<< searchInsert(v1, t2) << endl;
		cout << "Sample 3" << endl << "Input: [1,3,5,6], 7" << endl << "Output: "
			<< searchInsert(v1, t3) << endl;
		cout << "Sample 4" << endl << "Input: [1,3,5,6], 0" << endl << "Output: "
			<< searchInsert(v1, t4) << endl;
	}
};