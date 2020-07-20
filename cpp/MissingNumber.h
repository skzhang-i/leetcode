#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = (0 + nums.size()) * (nums.size() + 1) / 2;
		for (int i : nums)
			sum -= i;
		return sum;
	}

	void displaySample() {
		vector<int> v1 = { 3,0,1 };
		vector<int> v2 = { 9,6,4,2,3,5,7,0,1 };
		cout << "Sample 1: " << endl << "Input: [3,0,1]" << endl << "Output: "
			<< missingNumber(v1) << endl;
		cout << "Sample 1: " << endl << "Input: [9,6,4,2,3,5,7,0,1]" << endl << "Output: "
			<< missingNumber(v2) << endl;
	}
};