#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int num = 0;
	for (int i = 2; i < str.size(); i++) {
		int digit = 0;
		if (str[i] >= 'A' && str[i] <= 'F')
			digit += str[i] - 'A' + 10;
		else
			digit += str[i] - '0';
		num = num * 16 + digit;
	}
	cout << num << endl;
}