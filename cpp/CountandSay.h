#pragma once
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		for (int i = 2; i <= n; i++) {
			string strnew;
			int count = 0;
			char number = 'a';
			for (size_t j = 0; j < result.size(); j++) {
				if (result[j] != number) {
					if (count != 0) {
						strnew += to_string(count);
						strnew += number;
					}
					number = result[j];
					count = 1;
				}
				else {
					count++;
				}
			}
			strnew += to_string(count);
			strnew += number;
			result = strnew;
		}
		return result;
	}

	void displaySample() {
		cout << "Sample 1: " << endl << "Input: 1" << endl << "Output: "
			<< countAndSay(1) << endl;
		cout << "Sample 1: " << endl << "Input: 4" << endl << "Output: "
			<< countAndSay(4) << endl;
	}
};