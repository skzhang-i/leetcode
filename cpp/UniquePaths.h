#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int uniquePathsRecursive(int m, int n) {
		if (m == 1 || n == 1)
			return 1;
		return uniquePathsRecursive(m - 1, n) + uniquePathsRecursive(m, n - 1);
	}

	// The recursive method is obvious. Now imagine a matrix, in which every number 
	// represents the number of paths to the first element (0,0). Numbers in the first 
	// line and the first column must be 1. Then we can easily calculate the other numbers
	// (i,j) in the matrix, by adding (i-1,j) and (i,j-1). The last number in the matrix
	// is the answer.
	// Similar algorithm is used in pathfinding algorithm in video games.
	// Generally we might be able to use additional space to store results, in order to 
	// avoid the exponential growth of computing time caused by the "multi-branched" 
	// recursive method.
	int uniquePaths(int m, int n) {
		vector<vector<int>> matrix(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
		return matrix[m - 1][n - 1];
	}

	void displaySample() {
		cout << "Sample 1: " << endl << "Input: 3,2" << endl << "Output: "
			<< uniquePaths(3, 2) << endl;
		cout << "Sample 2: " << endl << "Input: 7,3" << endl << "Output: "
			<< uniquePaths(7, 3) << endl;
	}
};