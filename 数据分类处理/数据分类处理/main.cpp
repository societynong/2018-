#include<bits/stdc++.h>
using namespace std;
struct Data {
	int val;
	int idx;
	Data(int v, int i) :val(v), idx(i) {};
};

bool cmp(Data a1, Data a2) {
	return a1.val < a2.val;
}


bool isContain(int i,int r) {
	string si = to_string(i);
	string sr = to_string(r);
	for (int idx = 0; idx + sr.size() <= si.size(); idx++)
		if (si.substr(idx, sr.size()) == sr)
			return true;
	return false;
}
int main() {
	int n;
	cin >> n;

	vector<Data> R;
	for (int i = 0; i < n; i++) {
		int nBuf;
		cin >> nBuf;
		R.push_back(Data(nBuf, i));
	}
	int m;
	cin >> m;
	map<int,vector<Data> > I;
		
	for (int i = 0; i < m; i++) {
		int nBuf;
		cin >> nBuf;
		I[nBuf] = {};
	}

	int total = 0;
	for (auto it = I.begin(); it != I.end(); it++) {
		for (int i = 0; i < R.size(); i++) {
			if (isContain(R[i].val, it->first)) {
				I[it->first].push_back(R[i]);
			}
		}
		if (!I[it->first].empty()) {
			total += I[it->first].size() * 2 + 1 + 1;
		}
	}
	cout << total << " ";
	for (auto it = I.begin(); it != I.end(); it++) {
		if (it->second.empty())
			continue;
		cout << it->first << " ";
		cout << it->second.size() << " ";
		for (int id = 0; id < it->second.size(); id++)
			cout << it->second[id].idx << " " << it->second[id].val << " ";
	}
	return 0;
}