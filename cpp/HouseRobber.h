#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	inline int max(int a, int b) { return a > b ? a : b; }

	// First we can write a recursive solution. If we rob house[i], we need to consider
	// the remaining houses, from house[i+2] to the end. If we don't rob house[i], we need
	// to consider houses from house[i+1] to the end.
	// This is a bad solution, since we will call the function itself twice in one step. 
	int robRecursive(vector<int>& nums) {
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		else if (nums.size() == 1)
			return nums[0];
		vector<int> va(nums.begin() + 2, nums.end());
		int a = nums[0] + robRecursive(va);
		vector<int> vb(nums.begin() + 1, nums.end());
		int b = robRecursive(vb);
		return max(a, b);
	}

	// Now consider a non-recursive solution. There is some symmetry in this problem, that
	// the results will be the same no matter which end of the street you start robbing 
	// from. Reverse the above process, we can know that, whether we rob the house[i] only 
	// depends on two values -- rob values from the beginning to the house[i-2] and house[i-1].
	// Thus, we can calculate rob values one by one. 
	int rob(vector<int>& nums) {
		int a = 0, b = 0;
		int size = (int)nums.size();
		int temp_max;
		for (int i = 0; i < size; i++) {
			temp_max = max(a + nums[i], b);
			a = b;
			b = temp_max;
		}
		return max(a, b);
	}

	void displaySample() {
		vector<int> nums[] = { {1,2,3,1},{2,7,9,3,1},{9,0,0,9} };
		cout << "Sample 1: " << endl << "Input: [1,2,3,1]" << endl << "Output: "
			<< rob(nums[0]) << endl;
		cout << "Sample 2: " << endl << "Input: [2,7,9,3,1]" << endl << "Output: "
			<< rob(nums[1]) << endl;
		cout << "Sample 3: " << endl << "Input: [9,0,0,9]" << endl << "Output: "
			<< rob(nums[2]) << endl;
	}
};