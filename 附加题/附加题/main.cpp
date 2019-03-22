#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
LL	 mod = 1000000007;

int main() {
	int n;
	cin >> n;
	vector<int> p(n+1);
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	vector<LL> dp(1+n);
	dp[1] = 1;
	for (int i = 2; i <= n;i++) {
		dp[i] = (2*dp[i - 1]) % mod + 1;
		if (p[i] == 1) {
			dp[i] = (dp[i] + 2) % mod;
		}
		else {
			dp[i] = (dp[i]  - dp[p[i] - 1]  + 1) % mod;
		}
	}
	
	cout << (dp[n] + 1) % mod<< endl;

}