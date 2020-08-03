#pragma once
#include<list>
#include<iostream>
using namespace std;

class MinStack {
private:
    int min_value;
    list<pair<int, int>> values;        // It can be realized with a single linked list.
                                        // Or more tricky, a stack.
public:
    MinStack() : min_value(INT_MAX), values(list<pair<int, int>>()) {}

    void push(int x) {
        if (x < min_value)
            min_value = x;
        values.push_back(make_pair(x, min_value));
    }

    void pop() {
        values.pop_back();
        if (!values.empty()) {
            min_value = values.back().second;
        }
        else {
            min_value = INT_MAX;        // Don't forget initializing when all elements
                                        // have been removed.
        }
    }

    int top() {
        return values.back().first;
    }

    int getMin() {
        return min_value;
    }
};

class Solution {
public:
	void displaySample() {
        MinStack* obj = new MinStack();
        obj->push(-2);
        obj->push(0);
        obj->push(-3);
        cout << "Sample 1: " << endl << "Input: " << endl << "new MinStack" << endl
            << "push(-2)" << endl << "push(0)" << endl << "push(-3)" << endl << "getMin"
            << endl;
        cout << "Output: " << obj->getMin() << endl;
        obj->pop();
        cout << "Input: " << endl << "pop" << endl << "top" << endl;
        cout << "Output: " << obj->top() << endl;
        cout << "Input: " << endl << "getMin" << endl;
        cout << "Output: " << obj->getMin() << endl;
        delete obj;
	}
};