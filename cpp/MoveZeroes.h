#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		auto iter = nums.begin();
		auto first_zero = iter;
		bool first_zero_updated = false;
		while (iter != nums.end()) {
			if (*iter == 0 && !first_zero_updated) {
				first_zero = iter;
				first_zero_updated = true;
			}
			else if (*iter != 0 && first_zero_updated) {
				*first_zero = *iter;
				*iter = 0;
				// **Note:
				// iter_swap(iter1, iter2) swaps the elements, whereas swap(iter1, iter2)
				// only swaps the iterators. To swap the elements, use swap(*iter1, *iter2);
				//iter_swap(first_zero, iter);
				first_zero++;		// The next position of first_zero after the swap
									// is always 0.
			}
			iter++;
		}
	}

	void displaySample() {
		vector<int> v1 = { 0,1,0,3,12 };
		moveZeroes(v1);
		cout << "Sample 1: " << endl << "Input: 0,1,0,3,12" << endl << "Output: ";
		for (int i : v1) {
			cout << i << ",";
		}
		cout << endl;
		vector<int> v2 = { 0,1,0,3,12 };
		auto it1 = v2.begin(), it2 = v2.begin() + 1;
		swap(it1, it2);
		for (int i : v2) {
			cout << i << ",";
		}
		cout << endl << *it1 << "," << *it2;
	}
};