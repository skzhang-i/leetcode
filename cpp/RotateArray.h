#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	// A little bit hard to think.
	void rotate(vector<int>& nums, int k) {
		int size = (int)nums.size();
		k = k % size;
		if (k == 0)
			return;
		if (size < 2)
			return;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}

	void displaySample() {
		vector<int> nums[] = { {1,2,3,4,5,6,7},{-1,-100,3,99} };
		int k[] = { 3,2 };
		rotate(nums[0], k[0]);
		cout << "Sample 1: " << endl << "Input: [1,2,3,4,5,6,7], 3" << endl << "Output: ";
		for (int i : nums[0])
			cout << i << ',';
		cout << endl;
		rotate(nums[1], k[1]);
		cout << "Sample 2: " << endl << "Input: [-1,-100,3,99], 2" << endl << "Output: ";
		for (int i : nums[1])
			cout << i << ',';
		cout << endl;
	}
};