#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			cout << "0" << endl;
		else {
			string str;
			while (n) {
				str.push_back('0' + n % 10);
				n /= 10;
			}
			cout << str << endl;
		}
		
	}
}