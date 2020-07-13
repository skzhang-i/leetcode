#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	// **Note:
	// 1. string doesn't end with '\0'.
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];

		string result;
		int i = 0;
		char ch;
		while (true) {
			ch = strs[0][i];
			for (string str : strs) {
				auto iter = str.begin();
				iter += i;
				if (iter == str.end() || ch != *iter)
					return result;
			}
			result.push_back(ch);
			i++;
		}
	}

	void displaySample() {
		vector<string> s1 = { "flower","flow","flight" }, s2 = { "dog","racecar","car" };
		cout << "Sample 1: " << endl << "Input: [flower,flow,flight]" << endl
			<< "Output: " << longestCommonPrefix(s1) << endl;
		cout << "Sample 2: " << endl << "Input: [dog,racecar,car]" << endl
			<< "Output: " << longestCommonPrefix(s2) << endl;
	}
};