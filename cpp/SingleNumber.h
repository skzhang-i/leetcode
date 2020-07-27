#pragma once
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, bool> unmap(nums.size() / 2 + 1);
		for (int i : nums) {
			if (unmap.insert(make_pair(i, false)).second == false)
				unmap[i] = true;
		}
		for (auto p : unmap) {
			if (!p.second)
				return p.first;
		}
		return -1;	// Bad result;
	}

	// Better solution from leetcode website.
	int singleNumberXor(vector<int>& nums) {
		int result = 0;
		for (int i : nums)
			result ^= i;
		return result;
	}

	void displaySample() {
		vector<int> v1 = { 2,2,1 };
		vector<int> v2 = { 4,1,2,1,2 };
		cout << "Sample 1: " << endl << "Input: [2,2,1]" << endl << "Output: "
			<< singleNumber(v1) << endl;
		cout << "Sample 1: " << endl << "Input: [4,1,2,1,2]" << endl << "Output: "
			<< singleNumber(v2) << endl;
	}
};