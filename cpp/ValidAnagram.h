#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		const char ASCII_a = 97;
		vector<int> counts(26, 0);
		for (char ch : s)
			counts[ch - ASCII_a]++;
		for (char ch : t)
			counts[ch - ASCII_a]--;
		for (int i : counts) {
			if (i != 0)
				return false;
		}
		return true;
	}

	void displaySample() {
		string s[] = { "anagram","rat" };
		string t[] = { "nagaram","car" };
		cout << "Sample 1: " << endl << "Input: anagram,nagaram" << endl << "Output: "
			<< isAnagram(s[0], t[0]) << endl;
		cout << "Sample 2: " << endl << "Input: rat,car" << endl << "Output: "
			<< isAnagram(s[1], t[1]) << endl;
	}
};