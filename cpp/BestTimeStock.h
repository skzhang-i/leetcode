#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int low = INT_MAX, high = INT_MIN;
		int result = 0;
		for (int key : prices) {
			if (key < low) {
				low = key;
				high = INT_MIN;
			}
			if (key > high) {
				high = key;
				result = (high - low) > result ? (high - low) : result;
			}
		}
		return result;
	}

	void displaySample() {
		vector<int> v1 = { 7,1,5,3,6,4 };
		vector<int> v2 = { 7,6,4,3,1 };
		cout << "Sample 1: " << endl << "Input: [7,1,5,3,6,4]" << endl << "Output: "
			<< maxProfit(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [7,6,4,3,1]" << endl << "Output: "
			<< maxProfit(v2) << endl;
	}
};