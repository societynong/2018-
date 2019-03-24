#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int N,nBuf;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N;i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int i = 0;
	int j = -1;
	cout << arr[0] << endl;
	for (int i = 1; i < N;i++)
		if (arr[i] != arr[i - 1])
			cout << arr[i] << endl;
	/*while (i < arr.size()) {
		if (j == -1 || arr[i] != arr[j]) {
			arr[++j] = arr[i++];
		}
		else {
			i++;
		}

	}
	arr.resize(j + 1);

	for (int i = 0; i <= j; i++)
		cout << arr[i] << endl;
	*/
	return 0;
}