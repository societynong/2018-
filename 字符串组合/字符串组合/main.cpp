#include<bits/stdc++.h>

using namespace std;

class Comparator {
public:
	bool operator()(const string &l, const string &r) {
		if (l.size() < r.size())
			return true;
		else if (l.size() > r.size())
			return false;
		else {
			return l < r;
		}
	}
};

int main() {
	string str;
	cin >> str;
	set<string, Comparator> st;
	int l = str.size();
	for (int i = 1; i <= l;i++) {
		for (int j = 0; j + i - 1 < l; j++) {
			st.insert(str.substr(j, i));
		}
	}
	
	for (auto it : st) {
		cout << it << " ";
	}
	cout << endl;
}