#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		const char VALUE_INIT = -2;
		const char VALUE_DUPLICATED = -1;
		const char ASCII_a = 97;
		vector<int> v(26, VALUE_INIT);
		int size = (int)s.size();
		int first = size;
		for (int i = 0; i < size; i++) {
			if (v[s[i] - ASCII_a] != VALUE_INIT)
				v[s[i] - ASCII_a] = VALUE_DUPLICATED;
			else
				v[s[i] - ASCII_a] = i;
		}
		// I used to solve this problem with unordered_map, and:
		// It seems that the methods to traverse a unordered_map are different between 
		// the leetcode's and the VS2019's.
		//for (auto pair : unmap) {
		//	if (pair.second != -1)
		//		return pair.second;
		//}
		for (int i : v) {
			if (i >= 0 && i < first)
				first = i;
		}
		return first < size ? first : -1;
	}

	void displaySample() {
		string s1 = "leetcode";
		string s2 = "loveleetcode";
		cout << "Sample 1: " << endl << "Input: leetcode" << endl << "Output: "
			<< firstUniqChar(s1) << endl;
		cout << "Sample 1: " << endl << "Input: loveleetcode" << endl << "Output: "
			<< firstUniqChar(s2) << endl;
	}
};