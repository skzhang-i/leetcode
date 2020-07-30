#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n == 1)
			return true;
		else if (n == 145)
			return false;
		int result = 0;
		while (n) {
			result += (n % 10) * (n % 10);
			n /= 10;
		}
		return isHappy(result);
	}

	void displaySample() {
		int i[] = { 19,7,541 };
		cout << "Sample 1: " << endl << "Input: 19" << endl << "Output: " << isHappy(i[0])
			<< endl;
		cout << "Sample 2: " << endl << "Input: 7" << endl << "Output: " << isHappy(i[1])
			<< endl;
		cout << "Sample 3: " << endl << "Input: 541" << endl << "Output: " << isHappy(i[2])
			<< endl;
	}
};