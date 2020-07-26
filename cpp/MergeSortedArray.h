#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	// My thought fell into chaos several times during solving this problem. An easy
	// problem but hard to code.
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			if (ptr < i + m) {
				while (ptr < i + m) {
					if (nums2[i] < nums1[ptr]) {
						for (int j = i + m; j > ptr; j--)
							nums1[j] = nums1[j - 1];
						nums1[ptr] = nums2[i];
						break;
					}
					else {
						ptr++;
					}
				}
			}
			if (ptr >= i + m) {
				nums1[ptr] = nums2[i];
				ptr++;
			}
		}
	}

	void displaySample() {
		vector<int> v1 = { 1,2,3,0,0,0 };
		vector<int> v2 = { 2,5,6 };
		merge(v1, 3, v2, 3);
		cout << "Sample 1: " << endl << "Input: [1,2,3,0,0,0], [2,5,6]" << endl 
			<< "Output: ";
		for (int i : v1)
			cout << i << ',';
		cout << endl;
	}
};