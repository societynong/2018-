#include<bits/stdc++.h>
using namespace std;

struct ErrRec {
	string filename;
	int line;
	int cnt;
	ErrRec(string n, int l) :filename(n), line(l),cnt(1) {};
	bool operator == (const ErrRec &a) {
		return filename == a.filename && line == a.line;
	}
};
int main() {
	map<pair<string, int>, int> mp;
	string str;
	vector<ErrRec> lE;
	while (cin >> str) {
		int start = 0;
		int end = str.find('\\', start);

		while (end != -1) {
			start = end + 1;
			end = str.find('\\', start);
		}
		string filename = str.substr(start, end - start + 1);
		
		int line;
		cin >> line;
		ErrRec rec(filename, line);
		auto res = find(lE.begin(), lE.end(), rec);
		if (res == lE.end()) {
			lE.push_back(rec);
		}
		else {
			res->cnt++;
		}
	}
	int count = 0;
	for (auto item : lE) {
		if (count + 8 >= lE.size()) {
			string filename = item.filename;
			if (filename.size() > 16)
				filename = filename.substr(filename.size() - 16);
			cout << filename << " " << item.line << " " << item.cnt << " ";
		}
		count++;
	}
	return 0;
}