#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		return n > 0 && 1162261467 % n == 0;
	}

	// (int)log(3,INT_MAX) == 19. Exhaustive method.
	bool isPowerOfThreeWicked(int n) {
		if (n == 1 || n == 3 || n == 9 || n == 27 || n == 81 || n == 243 || n == 729 ||
			n == 2187 || n == 6561 || n == 19683 || n == 59049 || n == 177147 ||
			n == 531441 || n == 1594323 || n == 4782969 || n == 14348907 ||
			n == 43046721 || n == 129140163 || n == 387420489 || n == 1162261467)
			return true;
		else
			return false;
	}

	void displaySample() {
		cout << "Sample 1: " << endl << "Input: 27" << endl << "Output: "
			<< isPowerOfThree(27) << endl;
		cout << "Sample 2: " << endl << "Input: 0" << endl << "Output: "
			<< isPowerOfThree(0) << endl;
		cout << "Sample 3: " << endl << "Input: 9" << endl << "Output: "
			<< isPowerOfThree(9) << endl;
		cout << "Sample 4: " << endl << "Input: 45" << endl << "Output: "
			<< isPowerOfThree(45) << endl;
	}
};