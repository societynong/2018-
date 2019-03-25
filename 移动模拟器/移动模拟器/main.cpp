#include<bits/stdc++.h>

using namespace std;

int main() {
	string order;
	
	int x = 0;
	int y = 0;
	while (cin >> order) {
		int i = 0;
		while (i < order.size()) {
			char dir = order[i];
			
			if (order[i] == ';') {
				i++;
				continue;
			}
			i++;
			int len = 0;
			while (order[i] >= '0' && order[i] <= '9') {
				len = len * 10 + order[i] - '0';
				i++;
			}

			if (order[i] != ';') {
				while (order[i] != ';')
					i++;
				i++;
				continue;
			}

			switch (dir) {
			case 'A': x -= len;break;
			case 'S': y -= len;break;
			case 'D': x += len;break;
			case 'W': y += len;break;
			case 'X':break;
			}
			i++;
		}
		cout << x << "," << y << endl;
	}
	return 0;
	

}