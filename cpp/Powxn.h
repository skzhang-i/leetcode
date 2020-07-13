#pragma once
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
	// The idea is using recursive method to reduce the run times.
	// Again, the detail matters.
	double myPow(double x, int n) {
		if (x == 0)
			return 0;
		if (n == INT_MIN)
			return x * myPow(x, n + 1);		// -INT_MIN overflows.
		if (n < 0) {
			x = 1 / x;
			n = -n;
		}
		if (n == 0)
			return 1;

		double result = myPow(x, n / 2);
		if (n % 2 == 0) {
			return result * result;
			// Following sentence is BAD. Calculated twice.
			//return myPow(x, n / 2) * myPow(x, n / 2)
		}
		else {
			return x * result * result;
		}
	}

	void displaySample() {
		double x[] = { 2,2.1,2,0.1,10 };
		int n[] = { 10,3,-2,INT_MAX,INT_MIN };
		cout << "Sample 1: " << endl << "Input: 2, 10" << endl << "Output: "
			<< myPow(x[0], n[0]) << endl;
		cout << "Sample 2: " << endl << "Input: 2.1, 3" << endl << "Output: "
			<< myPow(x[1], n[1]) << endl;
		cout << "Sample 3: " << endl << "Input: 2, -2" << endl << "Output: "
			<< myPow(x[2], n[2]) << endl;
		cout << "Sample 4: " << endl << "Input: 0.1, INT_MAX" << endl << "Output: "
			<< myPow(x[3], n[3]) << endl;
		cout << "Sample 5: " << endl << "Input: 10, INT_MIN" << endl << "Output: "
			<< myPow(x[4], n[4]) << endl;
	}
};