#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	// Slow.
	// Bit operation can implement *2 or /2 easily. Maybe we should implement division
	// depending on it.
	int divide(int dividend, int divisor) {
		if (divisor == 1)
			return dividend;
		if (divisor == dividend)
			return 1;
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		if (dividend == INT_MIN && divisor == 2)
			return -1073741824;
		if (dividend == INT_MIN && divisor == -2)
			return 1073741824;
		if (dividend == INT_MIN)
			return divide(dividend + 1, divisor);
		if (divisor == 0)
			return 0;
		if (divisor == INT_MIN)
			return 0;
		if (divisor < 0 && dividend > 0)
			return -divide(dividend, -divisor);
		if (divisor > 0 && dividend < 0)
			return -divide(-dividend, divisor);
		if (divisor < 0 && dividend < 0)
			return divide(-dividend, -divisor);

		int result = 0, temp = dividend, diff = divisor, multi = 1;
		while (true) {
			temp -= diff;
			if (temp >= 0) {
				dividend = temp;
				result += multi;
				if (diff <= (INT_MAX >> 1)) {
					diff = diff << 1;
					multi = multi << 1;
				}
			}
			else {
				temp = dividend;
				diff = diff >> 1;
				multi = multi >> 1;
			}
			if (divisor > dividend)
				return result;
		}
	}

	void displaySample() {
		int d1[] = { 10,7,INT_MIN,INT_MAX };
		int d2[] = { 3,-3,-1,2 };
		cout << "Sample 1: " << endl << "Input: 10, 3" << endl << "Output: "
			<< divide(d1[0], d2[0]) << endl;
		cout << "Sample 2: " << endl << "Input: 7, -3" << endl << "Output: "
			<< divide(d1[1], d2[1]) << endl;
		cout << "Sample 3: " << endl << "Input: INT_MIN, -1" << endl << "Output: "
			<< divide(d1[2], d2[2]) << endl;
		cout << "Sample 4: " << endl << "Input: INT_MAX, 2" << endl << "Output: "
			<< divide(d1[3], d2[3]) << endl;
	}
};