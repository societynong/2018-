#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

void operation(vector<int> &shaizi, char item,unordered_map<char, vector<int> > mp) {
	vector<int> tmp(6);
	for (int i = 0; i < 6; i++)
		tmp[i] = shaizi[mp[item][i]];
	shaizi = tmp;
}

int main() {
	unordered_map<char, vector<int> > mp;
	mp['L'] = { 4,5,2,3,1,0 };
	mp['R'] = { 5,4,2,3,0,1 };
	mp['A'] = { 3,2,0,1,4,5 };
	mp['C'] = { 2,3,1,0,4,5 };
	mp['F'] = { 0,1,4,5,3,2 };
	mp['B'] = { 0,1,5,4,2,3 };

	string str;
	cin >> str;
	vector<int>shaizi = { 1,2,3,4,5,6 };
	for (auto item : str) {
		operation(shaizi, item, mp);
	}

	for (int i = 0; i < shaizi.size(); i++)
		cout << shaizi[i] << " ";
	cout << endl;
	return 0;
}