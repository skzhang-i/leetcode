#pragma once
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	// Solving by hash map. This run well in VS2019, but can't be accepted on website.
	// Note: 
	// 1. Use unordered_map in c++ to get a hash map. 
	// 2. unordered_map<Key,Value> gives a Key-to-Value mapping relation. You'll use 
	//	Key to find Value.
	// 3. In unordered_map a key is unique. Use unordered_multimap if you have 
	//	duplicate keys. unordered_multimap.find() returns the FIRST right element in
	//	it.
	//vector<int> twoSum(vector<int>& nums, int target) {
	//	unordered_multimap<int, int> hashmap;
	//	int x1, x2, size = (int)nums.size();
	//	vector<int> result;
	//	for (int i = 0; i < size; i++) {
	//		hashmap.insert(make_pair(nums[i], i));
	//	}
	//	for (int i = 0; i < size; i++) {
	//		x1 = nums[i];
	//		x2 = target - x1;
	//		auto iterx1 = hashmap.find(x1);
	//		hashmap.erase(iterx1);		// It seems that this doesn't go well on
	//									// leetcode website. 
	//		auto iterx2= hashmap.find(x2);
	//		if (iterx2 != hashmap.end()) {
	//			result.push_back(i);
	//			result.push_back(iterx2->second);
	//			return result;
	//		}
	//	}
	//	return { -1,-1 };	// Bad result.
	//}

	// Solving by brute force. Finally I submitted this. 
	vector<int> twoSum(vector<int>& nums, int target) {
		int size = (int)nums.size();
		vector<int> result;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return { -1,-1 };	// Bad result.
	}

	void displaySample() {
		vector<int> v1 = { 2,7,11,15 }, v2 = { 3,3 }, v3 = { 3,2,4 };
		int t1 = 9, t2 = 6, t3 = 6;
		vector<int> r1 = twoSum(v1, t1);
		vector<int> r2 = twoSum(v2, t2);
		vector<int> r3 = twoSum(v3, t3);
		cout << "Sample 1: " << endl << "Input: [2,7,11,15], 9" << endl << "Output: ["
			<< r1[0] << "," << r1[1] << "]" << endl;
		cout << "Sample 2: " << endl << "Input: [3,3], 6" << endl << "Output: ["
			<< r2[0] << "," << r2[1] << "]" << endl;
		cout << "Sample 2: " << endl << "Input: [3,2,4], 6" << endl << "Output: ["
			<< r3[0] << "," << r3[1] << "]" << endl;
	}
};