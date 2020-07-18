#pragma once
#include<vector>
#include<bitset>
#include<iostream>
using namespace std;

class Solution {
public:
	// Wicked.
	int hammingWeightWicked(uint32_t n) {
		bitset<32> bits(n);
		return bits.count();
	}

	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n) {
			result += n & 1;
			n >>= 1;
		}
		return result;
	}

	void displaySample() {
		vector<uint32_t> v = { 0xb,0x80,0xfffffffd };
		vector<int> ans = { 3,1,31 };
		cout << "Sample 1: " << endl << "Input: " << v[0] << endl << "Output: "
			<< hammingWeight(v[0]) << endl << "Answer: " << ans[0] << endl;
		cout << "Sample 2: " << endl << "Input: " << v[1] << endl << "Output: "
			<< hammingWeight(v[1]) << endl << "Answer: " << ans[1] << endl;
		cout << "Sample 3: " << endl << "Input: " << v[2] << endl << "Output: "
			<< hammingWeight(v[2]) << endl << "Answer: " << ans[2] << endl;
	}
};