#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	// Beware of out of bound errors.
	bool isPalindrome(string s) {
		int size = (int)s.size();
		if (size < 2)
			return true;
		int left = 0, right = size - 1;
		constexpr char diff = 'a' - 'A';
		while (true) {
			while (left < size && !((s[left] >= 'A' && s[left] <= 'Z')
				|| (s[left] >= 'a' && s[left] <= 'z')
				|| (s[left] >= '0' && s[left] <= '9')))
				left++;
			while (right >= 0 && !((s[right] >= 'A' && s[right] <= 'Z') 
				|| (s[right] >= 'a' && s[right] <= 'z')
				|| (s[right] >= '0' && s[right] <= '9')))
				right--;
			if (left >= right)
				break;
			if (!(s[left] == s[right] ||
				((s[left] >= 'A' && s[left] <= 'Z') && s[left] + diff == s[right]) ||
				((s[left] >= 'a' && s[left] <= 'z') && s[left] - diff == s[right])))
				return false;
			left++;
			right--;
		}
		return true;
	}

	void displaySample() {
		string s[] = { "A man, a plan, a canal: Panama","race a car" };
		cout << "Sample 1: " << endl << "Input: A man, a plan, a canal: Panama" << endl
			<< "Output: " << isPalindrome(s[0]) << endl;
		cout << "Sample 2: " << endl << "Input: race a car" << endl << "Output: "
			<< isPalindrome(s[1]) << endl;
	}
};