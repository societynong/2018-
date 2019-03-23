#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> sum(5);
	for (int i = 0; i < 10; i++) {
		string tmp;

		cin >> tmp;

		for (int j = 0; j < 5; j++) 
			if (tmp[j] == '1')
				++sum[j];
		
	}
	int count = 0;
	while (true) {
		bool over = false;
		for (int i = 0; i < 5;i++) {
			if (sum[i] == 0) {
				over = true;
				break;
			}
			else
				--sum[i];
		}
		
		if (over)
			break;
		else
			++count;
	}
	cout << count << endl;
		
	
}