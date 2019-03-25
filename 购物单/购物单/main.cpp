#include<bits/stdc++.h>

using namespace std;

int buy(int i,vector<int> &v, vector<int> &p, vector<int> &q, map<int, vector<int>> &mp,int left) {
	if (i < v.size()) {
		int ret = 0;
		if (q[i] == 0) {
			if (left > v[i])
				ret = max(v[i] * p[i] + buy(i + 1, v, p, q, mp, left - v[i]), ret);
			ret = max(buy(i + 1, v, p, q, mp, left), ret);
			if (!mp[i].empty()) {
				if (mp[i].size() >= 1 && left - v[i] - v[mp[i][0]] >= 0) {
					ret = max(v[i] * p[i] + v[mp[i][0]] * p[mp[i][0]] + buy(i + 1, v, p, q, mp, left - v[i] - v[mp[i][0]]), ret);
				}
				if (mp[i].size() == 2) {
					if (left - v[i] - v[mp[i][1]] >= 0)
						ret = max(v[i] * p[i] + v[mp[i][1]] * p[mp[i][1]] + buy(i + 1, v, p, q, mp, left - v[mp[i][1]]), ret);
					if (left - v[i] - v[mp[i][0]] - v[mp[i][1]] >= 0)
						ret = max(v[i] * p[i] + v[mp[i][0]] * p[mp[i][0]] + v[mp[i][1]] * p[mp[i][1]] + buy(i + 1, v, p, q, mp, left - v[i] - v[mp[i][0]] - v[mp[i][1]]), ret);
				}

			}
		}
		else {
			ret = max(buy(i + 1, v, p, q, mp, left), ret);
		}
		return ret;
	}
	else {
		return 0;
	}
}


int main() {
	int money, n;

	cin >> money >> n;
	int nn = n;
	money = money / 10 * 10;
	vector<int> p(n);
	vector<int> v(n);
	vector<int> q(n);

	int i = 0;
	while (nn--) {
		cin >> v[i];
		cin >> p[i];
		cin >> q[i];
		++i;
	}

	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		if (q[i] != 0)
			mp[q[i] - 1].push_back(i);
	}

	vector<vector<int>> dp(n, vector<int>(money + 1, 0));

	
	if (q[n - 1] == 0) {
		for (int m = 0; m <= money; m += 10) {
			dp[n - 1][m] = m >= v[n - 1] ? v[n - 1] * p[n - 1] : 0;
			if (mp[n - 1].size() >= 1) {
				if (m >= v[n - 1] + v[mp[n - 1][0]])
					dp[n - 1][m] = max(dp[n - 1][m], v[n - 1] * p[n - 1] + v[mp[n - 1][0]] * p[mp[n - 1][0]]);
			}
			if (mp[n - 1].size() >= 2) {
				if (m >= v[n - 1] + v[mp[n - 1][1]])
					dp[n - 1][m] = max(dp[n - 1][m], v[n - 1] * p[n - 1] + v[mp[n - 1][1]] * p[mp[n - 1][1]]);
				if (m >= v[n - 1] + v[mp[n - 1][1]] + v[mp[n - 1][0]])
					dp[n - 1][m] = max(dp[n - 1][m], v[n - 1] * p[n - 1] + v[mp[n - 1][1]] * p[mp[n - 1][1]] + v[mp[n - 1][0]] * p[mp[n - 1][0]]);
			}
		}
	}


	for (int i = n - 2; i >= 0; i--) {
		for (int m = 0; m <= money; m += 10) {
			dp[i][m] = dp[i + 1][m];
			if (q[i] == 0) {
				if (m >= v[i])
					dp[i][m] = max(dp[i][m], v[i] * p[i] + dp[i+1][m - v[i]]);
				if (mp[i].size() >= 1) {
					if (m >= v[i] + v[mp[i][0]])
						dp[i][m] = max(dp[i][m], v[i] * p[i] + v[mp[i][0]] * p[mp[i][0]]);
				}
				if (mp[i].size() >= 2) {
					if (m >= v[i] + v[mp[i][1]])
						dp[i][m] = max(dp[i][m], v[i] * p[i] + v[mp[i][1]] * p[mp[i][1]]);
					if (m >= v[i] + v[mp[i][1]] + v[mp[i][0]])
						dp[i][m] = max(dp[i][m], v[i] * p[i] + v[mp[i][1]] * p[mp[i][1]] + v[mp[i][0]] * p[mp[i][0]]);
				}
			}
		}
	}

		

	cout << dp[0][money] << endl;


	return 0;
}