#include<bits/stdc++.h>
using namespace std;
int main() {
	// �����������

	string str;
	cin >> str;
	int l = str.size();
	int ret = 0;
	for (int i = 0; i < l - 1; i++) {
		// ��str��Ϊ[0,i]��[i+1,l - 1]
		
		vector<vector<int>> dp(i + 1, vector<int>(l , 0));
		//[0,i1]��[i + 1,i + 1 + i2]�غ��˶���
		dp[0][0] = str[0] == str[i + 1] ? 1 : 0;
		for (int i1 = 1; i1 <= i; i1++)
			dp[i1][0] = str[i1] == str[i + 1] ? 1 : dp[i1 - 1][0];
		for (int i2 = 1; i + 1 + i2 < l; i2++)
			dp[0][i2] = str[0] == str[i + 1 + i2] ? 1 : dp[0][i2 - 1];

		for (int i1 = 1; i1 <= i; i1++) {
			for (int i2 = 1; i + 1 + i2 < l;i2++) {
				dp[i1][i2] = max(max(dp[i1 - 1][i2], dp[i1][i2 - 1]), dp[i1 - 1][i2 - 1] + (str[i1] == str[i + 1 + i2] ? 1 : 0)); 
				//dp[i1][i2] = max(max(dp[i1 - 1][i2], dp[i1][i2 - 1]), dp[i1 - 1][i2 - 1] + str[i1] == str[i + 1 + i2] ? 1 : 0); ����bug 
			}
		}
		ret = max(dp[i][l - i - 2], ret);
	}
	cout << ret * 2 << endl;

	return 0;
}