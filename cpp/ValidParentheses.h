#pragma once
#include<string>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
	// An easy one. Details matter.
	bool isValid(string s) {
		stack<char> st;
		int size = (int)s.size();
		for (int i = 0; i < size; i++) {
			switch (s[i])
			{
			case('('):
				st.push(0);
				break;
			case(')'):
				if (st.size() != 0 && st.top() == 0)
					st.pop();
				else
					return false;
				break;
			case('['):
				st.push(1);
				break;
			case(']'):
				if (st.size() != 0 && st.top() == 1)
					st.pop();
				else
					return false;
				break;
			case('{'):
				st.push(2);
				break;
			case('}'):
				if (st.size() != 0 && st.top() == 2)
					st.pop();
				else
					return false;
				break;
			default:
				break;
			}
		}
		return st.size() == 0;
	}

	void displaySample() {
		string s1 = "()", s2 = "()[]{}", s3 = "(]", s4 = "([)]", s5 = "{[]}", s6 = "){";
		cout << "Sample 1: " << endl << "Input: " << s1 << endl << "Output: "
			<< isValid(s1) << endl;
		cout << "Sample 2: " << endl << "Input: " << s2 << endl << "Output: "
			<< isValid(s2) << endl;
		cout << "Sample 3: " << endl << "Input: " << s3 << endl << "Output: "
			<< isValid(s3) << endl;
		cout << "Sample 4: " << endl << "Input: " << s4 << endl << "Output: "
			<< isValid(s4) << endl;
		cout << "Sample 5: " << endl << "Input: " << s5 << endl << "Output: "
			<< isValid(s5) << endl;
		cout << "Sample 6: " << endl << "Input: " << s6 << endl << "Output: "
			<< isValid(s6) << endl;
	}
};