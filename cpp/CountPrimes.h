#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isPrime(int n, const vector<int>& primes) {
		for (int p : primes) {
			if (n % p == 0)
				return false;
			if (p * p > n)
				return true;
		}
		return false;
	}

	int countPrimes(int n) {
		if (n <= 2)
			return 0;
		else if (n == 3)
			return 1;
		else if (n == 4)
			return 2;

		int result = 2;
		vector<int> primes = { 3 };
		for (int i = 5; i < n; i += 2) {
			if (isPrime(i, primes)) {
				primes.push_back(i);
				result++;
			}
			if (i == INT_MAX)
				break;
		}
		return result;
	}

	void displaySample() {
		cout << "Sample 1: " << endl << "Input: 10" << endl << "Output: "
			<< countPrimes(10) << endl;
		cout << "Sample 2: " << endl << "Input: 4" << endl << "Output: "
			<< countPrimes(4) << endl;
		cout << "Sample 3: " << endl << "Input: 5" << endl << "Output: "
			<< countPrimes(5) << endl;
		cout << "Sample 4: " << endl << "Input: 6" << endl << "Output: "
			<< countPrimes(6) << endl;
	}
};