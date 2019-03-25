#include <bits/stdc++.h>

using namespace std;
int LCS(string s1, string s2) {
	int l1 = s1.size();
	int l2 = s2.size();

	vector<vector<int>> dp(l1, vector<int>(l2));
	dp[0][0] = s1[0] == s2[0] ? 1 : 0;

	for (int i1 = 1; i1 < l1; i1++)
		dp[i1][0] = s2[0] == s1[i1] ? 1 : dp[i1 - 1][0];

	for (int i2 = 1; i2 < l2; i2++)
		dp[0][i2] = s1[0] == s2[i2] ? 1 : dp[0][i2-1];

	for (int i1 = 1; i1 < l1; i1++) {
		for (int i2 = 1; i2 < l2; i2++) {
			if (s1[i1] == s2[i2]) {
				dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
			}
			else {
				dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
			}
		}
	}
	return dp[l1 - 1][l2 - 1];
}


bool isMaxDup(string &str) {
	int ret = 0;
	for (int i = 0; i + 3 <= str.size(); i++) {
		string strtmp = str.substr(i, 3);
		for (int j = i + 3; j + 3 <= str.size(); j++) {
			if (strtmp == str.substr(j, 3))
				return true;
		}
	}
	return false;
}

bool isLengthOK(string &str) {
	return str.size() > 8;
}

bool isTypeOK(string &str) {
	bool c = false;
	bool C = false;
	bool n = false;
	bool o = false;
	for (auto item : str) {
		if (item >= 'a' && item <= 'z')
			c = true;
		else if (item >= 'A' && item <= 'Z')
			C = true;
		else if (item >= '0' && item <= '9')
			n = true;
		else
			o = true;
	}
	int count = 0;
	if (c)
		++count;
	if (C)
		++count;
	if (n)
		++count;
	if (o)
		++count;
	return count >= 3;
}

int main() {
	string str;
	while (cin >> str) {
		if (isTypeOK(str) && isLengthOK(str) && !isMaxDup(str))
			cout << "OK" << endl;
		else
			cout << "NG" << endl;
	}
		
	return 0;
}