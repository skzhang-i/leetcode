#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		auto iter = nums.begin(), it_left = iter, it_right = nums.end() - 1;
		while (iter <= it_right) {
			if (*iter == 0) {
				// It seems that swap() is slower than this.
				*iter = *it_left;
				*it_left = 0;
				it_left++;
				iter++;
			}
			else if (*iter == 2) {
				*iter = *it_right;
				*it_right = 2;
				it_right--;
			}
			else {
				iter++;
			}
		}
	}

	void displaySample() {
		vector<int> v1 = { 2,0,2,1,1,0 };
		vector<int> v2 = { 1,2,0,1,0,2,1 };
		sortColors(v1);
		sortColors(v2);
		cout << "Sample 1: " << endl << "Input: [2,0,2,1,1,0]" << endl << "Output: ";
		for (int i : v1)
			cout << i << ",";
		cout << endl;
		cout << "Sample 2: " << endl << "Input: [1,2,0,1,0,2,1]" << endl << "Output: ";
		for (int i : v2)
			cout << i << ",";
		cout << endl << "------------------------------------" << endl;
		vector<int> vrand;
		srand(rand());
		for (int i = 0; i < 10; i++)
			vrand.push_back(rand() % 3);
		cout << "Sample Random: " << endl << "Input: [";
		for (int i : vrand)
			cout << i << ",";
		cout << "]" << endl << "Output: ";
		sortColors(vrand);
		for (int i : vrand)
			cout << i << ",";
	}
};