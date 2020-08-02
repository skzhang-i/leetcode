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
	// First we need to find the middle of the linked list.
	ListNode* findMiddle(ListNode* head) {
		ListNode* fast, * slow;
		fast = slow = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast != nullptr)
			slow = slow->next;
		return slow;
	}

	// Sub program to reverse a linked list. Make each pointer point to the previous 
	// element.
	ListNode* reverseList(ListNode* head) {
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

	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return true;
		ListNode* reversed_list = reverseList(findMiddle(head));
		while (reversed_list != nullptr) {
			if (head->val != reversed_list->val)
				return false;
			head = head->next;
			reversed_list = reversed_list->next;
		}
		return true;
	}

	void displaySample() {
		ListNode l1[5];
		l1[0].val = 1;
		l1[0].next = &l1[1];
		l1[1].val = 2;
		l1[1].next = &l1[2];
		l1[2].val = 3;
		l1[2].next = &l1[3];
		l1[3].val = 2;
		l1[3].next = &l1[4];
		l1[4].val = 1;
		cout << "Sample 1: " << endl << "Input: 1->2->3->2->1" << endl << "Output: "
			<< isPalindrome(&l1[0]);
	}
};