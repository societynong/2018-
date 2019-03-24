#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		unordered_set<int> st;
		int otpt = 0;
		while (n) {
			int digit = n % 10;
			if (st.find(digit) == st.end()) {
				st.insert(digit);
				otpt *= 10;
				otpt += digit;
			}
			n /= 10;
		}
		cout << otpt << endl;
	}

	return 0;

}