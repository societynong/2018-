#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;

	stack<char> s;

	int ret = 0;
	int depth = 0;
	for (auto item : str) {

		if (item == '(') {
			s.push(item);
			depth++;
		}
		else if (item == ')') {
			s.pop();
			depth--;
		}
		ret = max(ret, depth);

	}
	cout << ret << endl;
	return 0;
}