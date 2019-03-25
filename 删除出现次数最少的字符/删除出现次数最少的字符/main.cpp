#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int arr[26] = { 0 };
		for (auto item : str)
			arr[item - 'a']++;
		int minn = INT_MAX;
		for (int i = 0; i < 26; i++)
			if(arr[i] != 0)
				minn = min(minn, arr[i]);
		for (int i = 0; i < str.size();i++) {
			if (arr[str[i] - 'a'] == minn) {
				str.erase(str.begin() + i);
				--i;
			}
		}
		cout << str << endl;
	}

}