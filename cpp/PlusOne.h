#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result(digits);
		int size = (int)digits.size();
		result[size - 1]++;
		if (result[size - 1] < 10) {
			return result;
		}
		else {
			for (int i = size - 1; i >= 1; i--) {
				if (result[i] == 10) {
					result[i] -= 10;
					result[i - 1]++;
				}
				else {
					return result;
				}
			}
			if (result[0] == 10) {
				result[0] -= 10;
				result.insert(result.begin(), 1);
			}
			return result;
		}
	}

	void displaySample() {
		vector<int> v1 = { 1,2,3 };
		vector<int> v2 = { 0 };
		vector<int> v3 = { 8,9,9,9 };
		vector<int> v4 = { 2,1,4,7,4,8,3,6,4,8 };	// INT_MAX+1
		cout << "Sample 1: " << endl << "Input: [1,2,3]" << endl << "Output: "
			<< toString(plusOne(v1)) << endl;
		cout << "Sample 2: " << endl << "Input: [0]" << endl << "Output: "
			<< toString(plusOne(v2)) << endl;
		cout << "Sample 3: " << endl << "Input: [8,9,9,9]" << endl << "Output: "
			<< toString(plusOne(v3)) << endl;
		cout << "Sample 4: " << endl << "Input: [2,1,4,7,4,8,3,6,4,8]" << endl
			<< "Output: " << toString(plusOne(v4)) << endl;
	}

	string toString(const vector<int>& v) {
		string result;
		for (int n : v) {
			char ch = n + 48;
			result.push_back(ch);
		}
		return result;
	}
};