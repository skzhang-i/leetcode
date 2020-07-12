#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = (int)prices.size();
		bool holding = false;
		int low, high;
		int result = 0;
		for (int i = 1; i < size; i++) {
			if (!holding && prices[i] > prices[i - 1]) {
				low = prices[i - 1];
				holding = true;
			}
			if (holding && prices[i] < prices[i - 1]) {
				high = prices[i - 1];
				result += high - low;
				holding = false;
			}
			if (holding && i == size - 1) {
				high = prices[i];
				result += high - low;
				holding = false;
			}
		}
		return result;
	}

	void displaySample() {
		vector<int> v1 = { 7,1,5,3,6,4 };
		vector<int> v2 = { 1,2,3,4,5 };
		vector<int> v3 = { 7,6,4,3,1 };
		cout << "Sample 1: " << endl << "Input: [7,1,5,3,6,4]" << endl << "Output: "
			<< maxProfit(v1) << endl;
		cout << "Sample 2: " << endl << "Input: [1,2,3,4,5]" << endl << "Output: "
			<< maxProfit(v2) << endl;
		cout << "Sample 3: " << endl << "Input: [7,6,4,3,1]" << endl << "Output: "
			<< maxProfit(v3) << endl;
	}
};