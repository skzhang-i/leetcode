#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		if (x == 0)
			return 0;
		if (x == INT_MIN)
			return 0;		// abs(INT_MIN) overflows.
		int length = (int)log10(abs(x)) + 1;
		long long result = 0, num = 0;
		for (int i = 1; i <= length; i++) {
			num = x % (long long)pow(10, i) - x % (long long)pow(10, i - 1);
			// This means: prev / pow(10, i - 1) * pow(10, length - i);
			result += num * pow(10, length - i * 2 + 1);
			// In VS2019 you can see if overflow happened(use int type). The signs of 
			// numbers will be different. If you want to know if the signs of numbers 
			// is the same, use (a&b)<0. Also, the detail matters. We need to deal 
			// with the situation when res==0.
			//if (result != 0 && (result ^ x) < 0)
			//	return 0;
			// To submit on leetcode website, use long long type and this:
			if (result > INT_MAX || result < INT_MIN)
				return 0;
		}
		return result;
    }

	void displaySample() {
		int nums[] = { 123,-10,32768,0,INT_MAX,INT_MIN };
		int i = 1;
		for (int x : nums) {
			cout << "Sample " << i << ": " << endl << "Input: " << x << endl
				<< "Output: " << reverse(x) << endl;
			i++;
		}
	}
};