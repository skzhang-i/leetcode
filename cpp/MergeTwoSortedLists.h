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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode* ptr1 = l1, * ptr2 = l2;
		ListNode* result, * end;
		if (l1->val < l2->val) {
			result = l1;
			ptr1 = ptr1->next;
		}
		else {
			result = l2;
			ptr2 = ptr2->next;
		}
		end = result;
		while (ptr1 != nullptr && ptr2 != nullptr) {
			if (ptr1->val < ptr2->val) {
				end->next = ptr1;
				ptr1 = ptr1->next;
			}
			else {
				end->next = ptr2;
				ptr2 = ptr2->next;
			}
			end = end->next;
		}
		while (ptr1 != nullptr) {
			end->next = ptr1;
			ptr1 = ptr1->next;
			end = end->next;
		}
		while (ptr2 != nullptr) {
			end->next = ptr2;
			ptr2 = ptr2->next;
			end = end->next;
		}
		return result;
	}

	void displaySample() {
		ListNode l1[3], l2[3];
		l1[0].val = 1;
		l1[0].next = &l1[1];
		l1[1].val = 2;
		l1[1].next = &l1[2];
		l1[2].val = 4;
		l2[0].val = 1;
		l2[0].next = &l2[1];
		l2[1].val = 3;
		l2[1].next = &l2[2];
		l2[2].val = 4;
		cout << "Sample 1: " << endl << "Input: 1->2->4, 1->3->4" << endl << "Output: "
			<< *mergeTwoLists(&l1[0], &l2[0]);
	}
};