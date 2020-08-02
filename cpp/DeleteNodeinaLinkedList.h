#pragma once
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	// Don't use these functions in solution. 

	friend ostream& operator<<(ostream& output, ListNode& l) {
		ListNode* ptr = &l;
		while (ptr != nullptr) {
			output << ptr->val << ',';
			ptr = ptr->next;
		}
		return output;
	}
};

class Solution {
public:
	// Very stupid problem. You can't really delete the node, but change the node.
	void deleteNode(ListNode* node) {
		if (node == nullptr)
			return;
		*node = *node->next;
	}

	void displaySample() {
		ListNode l1[4];
		l1[0].val = 4;
		l1[0].next = &l1[1];
		l1[1].val = 5;
		l1[1].next = &l1[2];
		l1[2].val = 1;
		l1[2].next = &l1[3];
		l1[3].val = 9;
		deleteNode(&l1[1]);
		cout << "Sample 1: " << endl << "Input: 4->5->1->9, 5" << endl << "Output: "
			<< l1[0];
	}
};