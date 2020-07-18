#pragma once
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<iostream>
using namespace std;

class Solution {
public:
	// 96ms.
	bool containsDuplicateEasy(vector<int>& nums) {
		unordered_set<int> unset(nums.begin(), nums.end());
		return unset.size() != nums.size();
	}
	// 56ms.
	bool containsDuplicateBySort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return unique(nums.begin(), nums.end()) != nums.end();
	}
	// 56ms.
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> unset(nums.size());
		for (int i : nums)
			if (unset.insert(i).second == false)
				return true;
		return false;
	}

	void displaySample() {
		vector<int> v1 = { 1,2,3,1 };
		vector<int> v2 = { 1,2,3,4 };
		cout << "Sample 1: " << endl << "Input: [1,2,3,1]" << endl << "Output: "
			<< containsDuplicate(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [1,2,3,4]" << endl << "Output: "
			<< containsDuplicate(v2) << endl;
	}
};