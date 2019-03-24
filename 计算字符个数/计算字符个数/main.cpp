#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;
	char c;
	cin >> str >> c;
	int count = 0;
	if (c >= 'A' && c <= 'Z')
		c -= 'A';
	if (c >= 'a' && c <= 'z')
		c -= 'a';
	for (auto item : str) {
		if (item >= 'A' && item <= 'Z')
			item -= 'A';
		if (item >= 'a' && item <= 'z')
			item -= 'a';
		if (item == c)
			count++;
	}
	cout << count << endl;
	return 0;
}