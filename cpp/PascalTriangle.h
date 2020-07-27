#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	// Avoid using vector.push_back() if you have known the size of vector in advance.
	// Remember vector is an encapsulated c++ array. Resizing means to create a brand 
	// new array in RAM and assign it and destroy the old one.
	// For example, 
	// Segment 1:
	// vector<int> v(50000000);
	// for (int i = 0; i < 50000000; i++)
	//     v[i] = i;						// This will finish immediately.
	// Segment 2:
	// vectot<int> v;
	// for (int i = 0; i < 50000000; i++)
	//     v.push_back(i);					// This will run for a while.
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0)
			return {};
		else if (numRows == 1)
			return { {1} };
		else if (numRows == 2)
			return{ {1},{1,1} };
		vector<vector<int>> result(numRows);
		result[0] = vector<int>({ 1 });
		result[1] = vector<int>({ 1,1 });
		for (int i = 2; i < numRows; i++) {
			vector<int> next(i + 1);
			next[0] = next[i] = 1;
			for (int j = 1; j < i; j++)
				next[j] = result[i - 1][j - 1] + result[i - 1][j];
			result[i] = next;
		}
		return result;
	}

	void displaySample() {
		cout << "Sample 1: " << endl << "Input: 5" << endl << "Output: " << endl;
		vector<vector<int>> v = generate(5);
		for (auto vi : v) {
			for (int i : vi)
				cout << i << ',';
			cout << endl;
		}
	}
};