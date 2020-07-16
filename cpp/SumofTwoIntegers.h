#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	// Bit operation.
	// Attention: Negative numbers are represented in two's complement. So there is 
	// no need to use different algorithms.
	int getSum(int a, int b) {
		if (b == 0)
			return a;
		int sum = a ^ b;
		int carry = (a & b & 0x7fffffff) << 1;	// Fxxx leetcode complier.
		return getSum(sum, carry);
	}

	void displaySample() {
		int a[] = { 2,-2,999,-1 };
		int b[] = { 3,3,999,1 };
		cout << "Sample 1: " << endl << "Input: 2,3" << endl << "Output: "
			<< getSum(a[0], b[0]) << endl;
		cout << "Sample 2: " << endl << "Input: -2,3" << endl << "Output: "
			<< getSum(a[1], b[1]) << endl;
		cout << "Sample 3: " << endl << "Input: 999,999" << endl << "Output: "
			<< getSum(a[2], b[2]) << endl;
		cout << "Sample 4: " << endl << "Input: -1,1" << endl << "Output: "
			<< getSum(a[3], b[3]) << endl;
	}
};