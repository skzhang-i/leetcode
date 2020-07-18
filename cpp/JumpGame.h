#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	// If you can get to a position, you can certainly get to all the positions before it.
	// So we only consider the furthest position.
	bool canJump(vector<int>& nums) {
		int i = 0, furthest = 0, size = (int)nums.size();
		while (i <= furthest) {
			if (i + nums[i] > furthest)
				furthest = i + nums[i];
			if (furthest >= size - 1)
				return true;
			i++;
		}
		return false;
	}

	void displaySample() {
		vector<int> v1 = { 2,3,1,1,4 };
		vector<int> v2 = { 3,2,1,0,4 };
		cout << "Sample 1: " << endl << "Input: [2,3,1,1,4]" << endl << "Output: "
			<< canJump(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [3,2,1,0,4]" << endl << "Output: "
			<< canJump(v2) << endl;
	}
};