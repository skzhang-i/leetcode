#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;
		for (int i = 1; i <= n; i++) {
			if (i % 15 == 0)
				result.push_back("FizzBuzz");
			else if (i % 3 == 0)
				result.push_back("Fizz");
			else if (i % 5 == 0)
				result.push_back("Buzz");
			else
				result.push_back(to_string(i));
		}
		return result;
	}

	void displaySample() {
		int n1 = 15;
		vector<string> s1 = fizzBuzz(n1);
		cout << "Sample 1: " << endl << "Input: 15" << endl << "Output: " << endl;
		for (string s : s1) {
			cout << s << endl;
		}
	}
};