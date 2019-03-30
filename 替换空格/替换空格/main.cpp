#include<bits/stdc++.h>

using namespace std;

void replaceSpace(string &str) {
	int cnt = 0;
	for (int i = 0; i < str.size(); i++)
		if (str[i] == ' ')
			++cnt;
	str.append(string(cnt * 2, '*'));

	int i, j;
	j = str.size() - 1;
	i = j - cnt * 2;
	while (i >= 0) {
		if (str[i] != ' ')
			str[j--] = str[i--];
		else {
			--i;
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
	}

}


void test() {
	string str = "nihao nihao nn hao";
	replaceSpace(str);
	cout << str << endl;
}
int main() {
	test();
	return 0;

}