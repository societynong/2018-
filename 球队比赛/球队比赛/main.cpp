#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int t;
	cin >> t;
	int dir[4][2] = { { 1,1 },{ -1,1 },{ -1,-1 },{ 1,-1 } };
	while (t != 0) {
		LL n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		if (n % 3 != 0) {
			cout << "no" << endl;
			t--;
			continue;
		}
		bool ok = false;
		for (int i = 0; i < 4; i++) {
			LL x2_3 = k - dir[i][0] * d1 - dir[i][1] * d2;
			if (x2_3 % 3 != 0)
				continue;
			LL x2 = x2_3 / 3;
			LL x1 = x2 + dir[i][0] * d1;
			LL x3 = x2 + dir[i][1] * d2;
			if (x1 < 0 || x3 < 0)
				continue;
			if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3) {
				ok = true;
				break;
			}
		}
		if(ok)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		t--;

	}
	return 0;
}