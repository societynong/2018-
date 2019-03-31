#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) :val(v), left(NULL), right(NULL) {};
};
int i;
TreeNode *construct(vector<int> &preOrderArr, vector<int> &midOrderArr, int l, int r) {
	// ÕÒµ½iµÄÎ»ÖÃ
	if (i >= preOrderArr.size() || l > r)
		return NULL;
	int loc = -1;
	for (int idx = l; idx <= r; idx++) {
		if (midOrderArr[idx] == preOrderArr[i])
			loc = idx;
	}
		
	
	TreeNode *root = new TreeNode(preOrderArr[i]);
	++i;
	if (l <= loc - 1) {
		root->left = construct(preOrderArr, midOrderArr, l, loc - 1);
	}
	if (loc + 1 <= r) {
		root->right = construct(preOrderArr, midOrderArr, loc + 1, r);
	}
	return root;

}

TreeNode * constructTree(vector<int> preOrderArr, vector<int> midOrderArr) {

	int i = 0;
	return construct(preOrderArr, midOrderArr, 0, preOrderArr.size() - 1);
}
TreeNode* nextNodeOfMideOrder(TreeNode *root, TreeNode *node) {
	stack<TreeNode*> s;
	int cnt = 0;
	while (root || !s.empty()) {
		if (root) {
			s.push(root);
			root = root->left;
		}
		else {
			root = s.top();
			s.pop();
			cout << root->val << endl;
			if (root->val == node->val)
				cnt++;
			
			else if (cnt == 1)
				return root;

			root = root->right;
		}
	}
	return NULL;
}
void test() {
	TreeNode* root = constructTree({ 1,2,4,7,3,5,6,8 }, {4,7,2,1,5,3,8,6});
	cout << nextNodeOfMideOrder(root, new TreeNode(3))->val << endl;
}



void partition(vector<int> &arr, int start, int end) {
	int small = start - 1;
	for (int i = start; i < end; ++i) {
		if (arr[i] < arr[end]) {
			swap(arr[++small], arr[i]);
		}
	}
	swap(arr[small + 1], arr[end]);
}

ostream & operator << (ostream &ot, vector<int>arr) {
	for (auto item : arr) {
		ot << item << " ";
	}
	return ot;
}

void test1() {
	int N = 10;
	int n = 30;
	vector<int> arr;
	for (int i = 0; i < N; i++)
		arr.push_back(rand() % n);
	cout << arr << endl;
	partition(arr, 0, arr.size() - 1);
	cout << arr << endl;
}

int main() {
	test1();
	return 0;
}