#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int main() {
	int n;
	cin >> n;
	int *x = new int[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x + n);
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		if (x[i] - i <= 0) {
			ret = 0;
			break;
		}
		else {
			ret = ret * (x[i] - i) % mod;
		}
	}
	cout << ret << endl;
	delete[]x;

	return 0;
}