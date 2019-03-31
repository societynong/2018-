#include<bits/stdc++.h>

using namespace std;

int findTheChongFu(vector<int> &arr) {

	int i = 0;
	while (i < arr.size()) {
		if (arr[i] == i)
			i++;
		else {
			if (arr[arr[i]] != arr[i])
				swap(arr[i], arr[arr[i]]);
			else
				return arr[i];
		}
	}
	return -1;
}

void test() {
	vector<int> arr = { 3,1,0,2,5,4 };
	cout << findTheChongFu(arr) << endl;
}
int main() {
	test();
	return 0;

}