#include<bits/stdc++.h>

using namespace std;

int main() {
	map<int, int> mp;
	int idx, val;
	int n;
	cin >> n;
	while (n--) {
		cin >> idx >> val;
		mp[idx] += val;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}