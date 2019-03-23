#include<bits/stdc++.h>

using namespace std;

int main() {
	int y, m, d;
	while (cin >> y >> m >> d) {
		int count = d;
		for (int i = 1; i < m; i++) {
			switch (i) {
			case 1:count += 31; break;
			case 2:count += y % 4 == 0 && y % 100 != 0 || (y % 400 == 0) ? 29 : 28; break;
			case 3:count += 31; break;
			case 4:count += 30; break;
			case 5:count += 31; break;
			case 6:count += 30; break;
			case 7:count += 31; break;
			case 8:count += 31; break;
			case 9:count += 30; break;
			case 10:count += 31; break;
			case 11:count += 30; break;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}