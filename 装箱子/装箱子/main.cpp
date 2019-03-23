#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> arr(6+1);
	for (int i = 1; i <= 6; i++)
		cin >> arr[i];
	int count = 0;
	count += arr[6];
	count += arr[5];
	int need1of5 = arr[5] * (6 * 6 - 5 * 5);
	arr[1] = arr[1] > need1of5 ? arr[1] - need1of5 : 0;
	count += arr[4];
	int need2of4 = arr[4] * 5;
	if (need2of4 > arr[2]) {
		arr[2] = 0;
		int need1of4 = (need2of4 - arr[2]) * 4;
		arr[1] = arr[1] > need1of4 ? arr[1] - need1of5 : 0;
	}
	else {
		arr[2] -= need2of4;
	}
	count += (arr[3] + 3) / 4;
	int left3 = arr[3] % 4;
	int need2of3[4] = { 0,5,3,1 };
	if (need2of3[left3] > arr[2]) {
		arr[2] = 0;
		int need1of3 = 6 * 6 - arr[2] * 2 * 2 - left3 * 3 * 3;
		arr[1] = arr[1] > need1of3 ? arr[1] - need1of3 : 0;
	}
	else {
		arr[2] -= need2of3[left3];
		int need1of3 = 6 * 6 - need2of3[left3] * 2 * 2 - left3 * 3 * 3;
		arr[1] = arr[1] > need1of3 ? arr[1] - need1of3 : 0;
	}

	if (arr[2] > 0) {
		count += (arr[2] + 8) / 9;
		int need1of2 = 6 * 6 - (arr[2] % 9) * 4;
		arr[1] = arr[1] > need1of2 ? arr[1] - need1of2 : 0;
	}
	count += (arr[1] + 35) / 36;
	cout << count << endl;
	return 0;
}