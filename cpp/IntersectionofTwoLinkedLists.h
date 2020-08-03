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
		output << l.val << ',';
		return output;
	}
};

class Solution {
public:
	// I didn't see notes in the description at first. Don't modify the original list.
	ListNode* getIntersectionNodeModify(ListNode* headA, ListNode* headB) {
		ListNode new_end(0);
		ListNode* next;
		while (headA != NULL) {
			next = headA->next;
			headA->next = &new_end;
			headA = next;
		}
		while (headB != NULL) {
			if (headB->next == &new_end)
				return headB;
			headB = headB->next;
		}
		return NULL;
	}

	// List A = A + intersection, List B = B + intersection.
	// length(A+intersectin+B) = length(B+intersection+A).
	// Thus, we can find the starting node of the intersection.
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* ptrA = headA, * ptrB = headB;
		while (ptrA != ptrB) {
			ptrA = ptrA ? ptrA->next : headB;
			ptrB = ptrB ? ptrB->next : headA;
		}
		// Attention: When there is no intersection part, ptrA = ptrB = NULL.
		return ptrA;
	}

	void displaySample() {
		ListNode l1[5], l2[2];
		l1[0].val = 1;
		l1[0].next = &l1[1];
		l1[1].val = 2;
		l1[1].next = &l1[2];
		l1[2].val = 3;
		l1[2].next = &l1[3];
		l1[3].val = 4;
		l1[3].next = &l1[4];
		l1[4].val = 5;
		l2[0].val = -1;
		l2[0].next = &l2[1];
		l2[1].val = -2;
		l2[1].next = &l1[3];
		cout << "Sample 1: " << endl << "Input: 1->2->3->4->5, -1->-2->4" << endl
			<< "Output: " << *getIntersectionNode(&l1[0], &l2[0]);
	}
};