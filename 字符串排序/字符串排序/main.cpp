#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;
	str = "#$Y^!#Pf&~#FUyTtAfZhCs&Dly%M@(muOI@Le^mydvc((w$x-cP&t-f$R%CCp)bCck@P-ag";
	for (int i = 0; i < str.size() - 1; i++) {
		int j = 0;
		while (j < str.size() - 1 - i && !(str[j] >= 'a' && str[j] <= 'z') && !(str[j] >= 'A' && str[j] <= 'Z')) {
			j++;
		}
		while (j < str.size() - 1 - i) {
			int j1 = j + 1;
			while (j1 < str.size() - i && !(str[j1] >= 'a' && str[j1] <= 'z') && !(str[j1] >= 'A' && str[j1] <= 'Z')) {
				j1++;
			}
			if (j1 >= str.size() - i)
				break;
			else {
				int nj;
				int nj1;
				if (str[j] >= 'A' && str[j] <= 'Z')
					nj = str[j] - 'A';
				else if (str[j] >= 'a' && str[j] <= 'z')
					nj = str[j] - 'a';

				if (str[j1] >= 'A' && str[j1] <= 'Z')
					nj1 = str[j1] - 'A';
				else if (str[j1] >= 'a' && str[j1] <= 'z')
					nj1 = str[j1] - 'a';

				if (nj > nj1)
					swap(str[j], str[j1]);
				j = j1;
			}

		}
	}
	cout << str << endl;
	return 0;

}