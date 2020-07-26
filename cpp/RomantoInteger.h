#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		switch (s[0]) {
		case('M'):
			return 1000 + romanToInt(s.substr(1, s.size() - 1));
		case('D'):
			return 500 + romanToInt(s.substr(1, s.size() - 1));
		case('L'):
			return 50 + romanToInt(s.substr(1, s.size() - 1));
		case('V'):
			return 5 + romanToInt(s.substr(1, s.size() - 1));
		case('C'):
			if (s[1] == 'M')
				return 900 + romanToInt(s.substr(2, s.size() - 2));
			else if (s[1] == 'D')
				return 400 + romanToInt(s.substr(2, s.size() - 2));
			else
				return 100 + romanToInt(s.substr(1, s.size() - 1));
		case('X'):
			if (s[1] == 'C')
				return 90 + romanToInt(s.substr(2, s.size() - 2));
			else if (s[1] == 'L')
				return 40 + romanToInt(s.substr(2, s.size() - 2));
			else
				return 10 + romanToInt(s.substr(1, s.size() - 1));
		case('I'):
			if (s[1] == 'X')
				return 9 + romanToInt(s.substr(2, s.size() - 2));
			else if (s[1] == 'V')
				return 4 + romanToInt(s.substr(2, s.size() - 2));
			else
				return 1 + romanToInt(s.substr(1, s.size() - 1));
		default:
			return 0;	// Bad result.
		}
	}

	void displaySample() {
		string s[] = { "III","IV","LVIII","MCMXCIV" };
		cout << "Sample 1: " << endl << "Input: III" << endl << "Output: "
			<< romanToInt(s[0]) << endl;
		cout << "Sample 2: " << endl << "Input: IV" << endl << "Output: "
			<< romanToInt(s[1]) << endl;
		cout << "Sample 3: " << endl << "Input: LVIII" << endl << "Output: "
			<< romanToInt(s[2]) << endl;
		cout << "Sample 4: " << endl << "Input: MCMXCIV" << endl << "Output: "
			<< romanToInt(s[3]) << endl;
	}
};