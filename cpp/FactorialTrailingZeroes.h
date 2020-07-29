#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int result = 0;
		while (n) {
			n /= 5;
			result += n;
		}
		return result;
	}

	void displaySample() {
		int i[] = { 3,5,25 };
		cout << "Sample 1: " << endl << "Input: 3" << endl << "Output: "
			<< trailingZeroes(i[0]) << endl;
		cout << "Sample 2: " << endl << "Input: 5" << endl << "Output: "
			<< trailingZeroes(i[1]) << endl;
		cout << "Sample 3: " << endl << "Input: 25" << endl << "Output: "
			<< trailingZeroes(i[2]) << endl;
	}
};