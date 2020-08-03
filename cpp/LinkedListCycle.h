#pragma once
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// Thought of this solution during solving #160 Intersection of Two Linked Lists.
	bool hasCycle(ListNode* head) {
		ListNode new_end(0);
		ListNode* next;
		while (head != NULL) {
			if (head->next == &new_end)
				return true;
			next = head->next;
			head->next = &new_end;
			head = next;
		}
		return false;
	}

	void displaySample() {
		ListNode l1[5];
		l1[0].val = 1;
		l1[0].next = &l1[1];
		l1[1].val = 2;
		l1[1].next = &l1[2];
		l1[2].val = 3;
		l1[2].next = &l1[3];
		l1[3].val = 4;
		l1[3].next = &l1[4];
		l1[4].val = 5;
		l1[4].next = &l1[2];
		cout << "Sample 1: " << endl << "Input: 1->2->3->4->5-(cycle)->3" << endl
			<< "Output: " << hasCycle(&l1[0]);
	}
};