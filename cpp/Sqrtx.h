#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	// Binary search for suitable result.
	int mySqrt(int x) {
		const int max_result = 46340;
		int a = max_result * max_result;
		if (x >= a)
			return max_result;
		int low = 0, high = max_result, mid;
		while (low <= high) {
			mid = (high + low) / 2;
			if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
				return mid;
			}
			else if (mid * mid > x) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return -1; // Bad result;
	}

	void displaySample() {
		int n1 = 4, n2 = 8;
		cout << "Sample 1: " << endl << "Input: 4" << endl << "Output: " << mySqrt(n1)
			<< endl;
		cout << "Sample 2: " << endl << "Input: 8" << endl << "Output: " << mySqrt(n2)
			<< endl;
	}
};