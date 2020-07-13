#pragma once
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int sizeh = haystack.size(), sizen = needle.size();
		if (sizen == 0)
			return 0;
		if (sizeh == 0 || sizen > sizeh)
			return -1;
		// Brute force.
		bool equal = true;
		for (int i = 0; i < sizeh - sizen + 1; i++) {
			for (int j = 0; j < sizen; j++) {
				if (haystack[i + j] != needle[j]) {
					equal = false;
					break;
				}
				equal = true;
			}
			if (equal == true)
				return i;
		}
		return -1;
	}

	void displaySample() {
		string h1 = "hello", n1 = "ll", h2 = "aaaaa", n2 = "bba";
		cout << "Sample 1: " << endl << "Input: hello, ll" << endl << "Output: "
			<< strStr(h1, n1) << endl;
		cout << "Sample 2: " << endl << "Input: aaaaa, bba" << endl << "Output: "
			<< strStr(h2, n2) << endl;
	}
};