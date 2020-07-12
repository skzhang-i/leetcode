#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum_array = 0;
		int result = INT_MIN;
		for (int key : nums) {
			sum_array += key;
			result = result > sum_array ? result : sum_array;
			if (sum_array < 0)
				sum_array = 0;
		}
		return result;
	}

	void displaySample() {
		vector<int> v1 = { -2,1,-3,4,-1,2,1,-5,4 };
		vector<int> v2 = { -5,-1,-3,-2,-4 };
		vector<int> v3 = { 1,4,5,2,3 };
		vector<int> v4 = { 0,-3,1,1 };
		cout << "Sample 1: " << endl << "Input: [-2,1,-3,4,-1,2,1,-5,4]" << endl
			<< "Output: " << maxSubArray(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [-5,-1,-3,-2,-4]" << endl<< "Output: "
			<< maxSubArray(v2) << endl;
		cout << "Sample 3: " << endl << "Input: [1,4,5,2,3]" << endl<< "Output: " 
			<< maxSubArray(v3) << endl;
		cout << "Sample 4: " << endl << "Input: [0,-3,1,1]" << endl << "Output: "
			<< maxSubArray(v4) << endl;
	}
};