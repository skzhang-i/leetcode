#pragma once
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int size = (int)nums.size();
		// size 48ms 21.3mb | size/2 72ms 20.5mb | size/2+1 68ms 20.6mb | size/2+2 72ms 20.6mb
		unordered_map<int, int> unmap(size);
		for (int i : nums) {
			unmap[i]++;
			if (unmap[i] > size / 2)
				return i;
		}
		return -1;		// Bad result;
	}

	void displaySample() {
		vector<int> v1 = { 3,2,3 };
		vector<int> v2 = { 2,2,1,1,1,2,2 };
		cout << "Sample 1: " << endl << "Input: [3,2,3]" << endl << "Output: "
			<< majorityElement(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [2,2,1,1,1,2,2]" << endl << "Output: "
			<< majorityElement(v2) << endl;
	}
};