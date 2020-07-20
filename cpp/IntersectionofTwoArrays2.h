#pragma once
#include<vector>
#include<list>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return intersect(nums2, nums1);
		unordered_map<int, int> unmap(nums2.size());
		list<int> result_lst;
		for (int i : nums2)
			unmap[i]++;
		for (int i : nums1) {
			if (unmap[i] > 0) {
				result_lst.push_back(i);
				unmap[i]--;
			}
		}
		vector<int> result(result_lst.size());
		auto iter = result_lst.begin();
		for (size_t i = 0; i < result_lst.size(); i++) {
			result[i] = *iter;
			iter++;
		}
		return result;
	}

	void displaySample() {
		vector<vector<int>> v1 = { {1,2,2,1},{4,9,5} };
		vector<vector<int>> v2 = { {2,2},{9,4,9,8,4} };
		cout << "Sample 1: " << endl << "Input: [1,2,2,1],[2,2]" << endl << "Output: "
			<< toString(intersect(v1[0], v2[0])) << endl;
		cout << "Sample 2: " << endl << "Input: [4,9,5],[9,4,9,8,4]" << endl << "Output: "
			<< toString(intersect(v1[1], v2[1])) << endl;
	}

	string toString(const vector<int>& v) {
		string result;
		for (int i : v) {
			result.push_back(i + 48);
			result.push_back(',');
		}
		return result;
	}
};