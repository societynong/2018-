#include<bits/stdc++.h>

using namespace std;

int cut(int l) {
	if (l < 1)
		return 0;
	int ret = l;
	vector<int> dp(l + 1);
	for (int i = 2; i <= l; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], j * max(dp[i - j],i - j));
		}
	}
	return dp[l];
}

void test() {
	int l;
	cout << hex << (-4>>1) << endl;
	/*while (cin >> l)
		cout << cut(l) << endl;*/
}

int main() {
	test();
	return 0;
}