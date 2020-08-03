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
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* prev = nullptr;
		ListNode* next;
		while (head != nullptr) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
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
		cout << "Sample 1: " << endl << "Input: 1->2->3->4->5" << endl << "Output: "
			<< *reverseList(&l1[0]);
	}
};