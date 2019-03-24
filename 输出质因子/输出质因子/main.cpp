#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n != 1) {
			vector<int> zhi;
			for (int i = 2; i <= n; i++) {
				while (n % i == 0) {
					cout << i << " ";
					n /= i;
				}
			}
			cout << endl;
		}
		
	}
	return 0;

}