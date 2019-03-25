#include<unordered_map>

#include<bits/stdc++.h>

using namespace std;


int main() {
	unordered_map<char, int>  mp;
	mp['1'] = 1;
	mp['a'] = 2;
	mp['b'] = 2;
	mp['c'] = 2;
	mp['d'] = 3;
	mp['e'] = 3;
	mp['f'] = 3;
	mp['g'] = 4;
	mp['h'] = 4;
	mp['i'] = 4;
	mp['j'] = 5;
	mp['k'] = 5;
	mp['l'] = 5;
	mp['m'] = 6;
	mp['n'] = 6;
	mp['o'] = 6;
	mp['p'] = 7;
	mp['q'] = 7;
	mp['r'] = 7;
	mp['s'] = 7;
	mp['t'] = 8;
	mp['u'] = 8;
	mp['v'] = 8;
	mp['w'] = 9;
	mp['x'] = 9;
	mp['y'] = 9;
	mp['z'] = 9;
	mp['0'] = 0;


	string str;
	while (cin >> str) {

		for (int i = 0; i < str.size(); ++i) {
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = mp[str[i]] + '0';
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] = (str[i] - 'A' + 1) % 26 + 'a';
			}
		}
		cout << str << endl;
	}
	return 0;
}