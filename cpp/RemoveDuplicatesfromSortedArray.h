#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = (int)nums.size();
		if (size < 2)
			return size;
		int count = 1;
		for (int i = 1; i < size; i++) {
			if (nums[i] != nums[i - 1]) {
				nums[count] = nums[i];
				count++;
			}
		}
		nums.resize(count);
		return count;
	}

	void displaySample() {
		vector<int> v1 = { 1,1,2 };
		vector<int> v2 = { 0,0,1,1,1,2,2,3,3,4 };
		cout << "Sample 1: " << endl << "Input: [1,1,2]" << endl << "Output: "
			<< removeDuplicates(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [0,0,1,1,1,2,2,3,3,4]" << endl << "Output: "
			<< removeDuplicates(v2) << endl;
	}
};