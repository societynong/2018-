#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int i = 0;
		int l = 8;
		while (i + l <= str.size()) {
			cout << str.substr(i, l)<<endl;
			i += l;
		}
		if (i < str.size()) {
			string tmp = str.substr(i);
			while (tmp.size() < l)
				tmp += '0';
			cout << tmp<< endl;
		}
		
	}
	return 0;
}