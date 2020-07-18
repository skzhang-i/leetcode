#pragma once
#include<vector>
#include<bitset>
#include<iostream>
using namespace std;

class Solution {
public:
	// Wicked.
	uint32_t reverseBitsWicked(uint32_t n) {
		bitset<32> bits(n);
		string str = bits.to_string();
		reverse(str.begin(),str.end());
		bits = bitset<32>(str);
		return bits.to_ulong();
	}

	// Improved.
	uint32_t reverseBits(uint32_t n) {
		bitset<32> bits(n);
		int right = 0, left = 31;
		while (right < left) {
			bool temp = bits[right];
			bits[right++] = bits[left];
			bits[left--] = temp;
		}
		return bits.to_ulong();
	}

	void displaySample() {
		vector<long long> v = { 43261596,4294967293 };
		vector<long long> ans = { 964176192,3221225471 };
		cout << "Sample 1: " << endl << "Input: 43261596" << endl << "Output: " 
			<< reverseBits(v[0]) << endl << "Answer: " << ans[0] << endl;
		cout << "Sample 2: " << endl << "Input: 4294967293" << endl << "Output: " 
			<< reverseBits(v[1]) << endl << "Answer: " << ans[1] << endl;

	}
};