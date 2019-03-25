#include<bits/stdc++.h>

using namespace std;

int main() {

	string str;

	while (cin >> str) {
		int st[128 + 1] = { 0 };
		int count = 0;
		for (auto item : str)
			if (item < 128 && item >= 0)
				if (st[item] == 0)
					++count, ++st[item];
		cout << count << endl;
	}

	return 0;
}