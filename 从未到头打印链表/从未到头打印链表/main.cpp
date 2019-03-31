#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

void printFromTailToHead(ListNode *list) {
	stack<ListNode*> s;
	ListNode* cur = list;
	while (cur) {
		s.push(cur);
	}

	while (!s.empty()) {
		cout << s.top->val << " ";
		s.pop();
	}
	cout << endl;
}