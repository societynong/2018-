#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;


void operation(vector<int>&saizi, char item, unordered_map<char, vector<int>> &mp) {
	vector<int> tmp(6);
	for (int i = 0; i < 6; i++) {
		tmp[i] = saizi[mp[item][i]];
	}
	saizi = tmp;
}

int main() {
	unordered_map<char, vector<int>> mp;
	mp['L'] = { 2,1,3,0,4,5 };
	mp['R'] = { 3,0,2,1,4,5 };
	mp['F'] = { 0,4,1,5,3,2 };
	mp['B'] = { 0,5,1,4,2,3 };
	mp['C'] = { 5,2,4,3,0,1 };
	mp['A'] = { 4,2,5,3,1,0 };

	vector<int> saizi = { 1,2,3,4,5,6 };
	string str;
	cin >> str;
	for (auto item : str) {
		operation(saizi, item,mp);
	}
	for (auto item : saizi) {
		cout << item << " ";
	}
	cout << endl;
}