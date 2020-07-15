#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		//int size = (int)s.size();
		//char ch;
		//for (int i = 0; i < size / 2; i++) {
		//	ch = s[i];
		//	s[i] = s[size - i - 1];
		//	s[size - i - 1] = ch;
		//}
		reverse(s.begin(), s.end());
	}

	void displaySample() {
		vector<char> v1 = { 'H','e','l','l','o' };
		vector<char> v2 = { 'H','a','n','n','a','h' };
		reverseString(v1);
		reverseString(v2);
		cout << "Sample 1: " << endl << "Input: Hello" << endl << "Output: "
			<< toString(v1) << endl;
		cout << "Sample 2: " << endl << "Input: Hannah" << endl << "Output: "
			<< toString(v2) << endl;
	}

	string toString(const vector<char>& v) {
		string result;
		for (char ch : v) {
			result.push_back(ch);
		}
		return result;
	}
};