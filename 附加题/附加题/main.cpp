#include<bits/stdc++.h>
using namespace std;
int mod = 10e9 + 7;
int main() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i]++;
	}
		
		
	vector<long long> dp;
	dp.push_back(0);
	int i = 1;
	while (i <= n) {
		
		dp.push_back(2 * dp[i - 1] + 2 - dp[p[i] - 1]);
		i++;
	}
	
	cout << dp.back() % mod << endl;

	return 0;
}