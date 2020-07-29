#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int size = (int)s.size();
		int result = 0;
		for (int i = 0; i < size; i++)
			result += (s[size - i - 1] - (int)'A' + 1) * (int)pow(26, i);
		return result;
	}

	void displaySample() {
		string s[] = { "AB","ZY" };
		cout << "Sample 1: " << endl << "Input: AB" << endl << "Output: "
			<< titleToNumber(s[0]) << endl;
		cout << "Sample 2: " << endl << "Input: ZY" << endl << "Output: " 
			<< titleToNumber(s[1]) << endl;
	}
};