#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	int A = 0, B = 0, C = 0, D = 0, E = 0, S = 0, EY = 0;
	while (cin >> str) {
		int mid = str.find_first_of('~');
		string ip1 = str.substr(0, mid);
		string ip2 = str.substr(mid+1);
		vector<int> n1;
		vector<int> n2;
		int i = 0;
		while (i < ip1.size()) {
			int dot = ip1.find_first_of('.');
			if (dot == string::npos)
				dot = ip1.size();
			int digit = 0;
			while (i < dot) {
				digit = digit * 10 + ip1[i] - '0';
				++i;
			}
			n1.push_back(digit);
			if (dot == ip1.size())
				break;
			ip1[dot]++;
			++i;
 		}

		i = 0;
		while (i < ip2.size()) {
			int dot = ip2.find_first_of('.');
			if (dot == string::npos)
				dot = ip2.size();
			int digit = 0;
			while (i < dot) {
				digit = digit * 10 + ip2[i] - '0';
				++i;
			}
			n2.push_back(digit);
			if (dot == ip2.size())
				break;
			ip2[dot]++;
			++i;
		}

		if (n1[0] <= 126 && n1[1] <= 255 && n1[2] <= 255 && n1[3] <= 255) {
			++A;
			if (n1[0] == 10)
				++S;

		} else if (n1[0] >= 128 && n1[0] <= 191 && n1[1] <= 255 && n1[2] <= 255 && n1[3] <= 255) {
			++B;
			if (n1[0] == 172 && n1[1] >= 16 && n1[1] <= 31)
				++S;
		}
		else if (n1[0] >= 192 && n1[0] <= 223 && n1[1] <= 255 && n1[2] <= 255 && n1[3] <= 255) {
			++C;
			if (n1[0] == 192 && n1[1] == 168)
				++S;
		}
		else if (n1[0] >= 224 && n1[0] <= 239 && n1[1] <= 255 && n1[2] <= 255 && n1[3] <= 255) {
			++D;
		}
		else if (n1[0] >= 240 && n1[0] <= 255 && n1[1] <= 255 && n1[2] <= 255 && n1[3] <= 255) {
			++E;
		}
		bool z = false;
		bool notok = false;
		for (int i = 0; i < 3; i++) {
			int tmp = 128;
			for (int j = 0; j < 8; j++) {
				if (!z) {
					if (n2[i] & tmp == 0)
						z = true;
				}
				else {
					++EY;
					notok = true;
					break;
				}
				tmp >>= 1;
			}
			if (notok)
				break;
		}
	}
	return 0;
}