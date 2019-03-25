#include<bits/stdc++.h>

using namespace std;

int LIS(vector<int> &arr, int l, int r) {
	if (r < l)
		return 0;
	vector<int> p(r - l + 1, 1);
	int mx = 0;
	for (int i = l + 1; i <= r; i++) {
		for (int j = l; j < i; j++) {
			if (arr[i] > arr[j])
				p[i - l] = max(p[i - l], 1 + p[j - l]);
		}
		mx = max(p[i - l], mx);
	}
	return r - l + 1 - mx;
}

int LDS(vector<int> &arr, int l, int r) {
	if (r < l)
		return 0;
	vector<int> p(r - l + 1, 1);
	int mx = 0;
	for (int i = l+1; i <= r; i++) {
		for (int j = l; j < i; j++) {
			if (arr[i] < arr[j])
				p[i - l] = max(p[i - l], 1 + p[j - l]);
		}
		mx = max(p[i - l], mx);
	}
	return r - l + 1 - mx;
}


int main() {
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		vector<int> p(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j])
					p[i] = max(p[i], 1 + p[j]);
			}
		}
		vector<int> q(n, 1);
		for (int i = n - 2; i >= 0; i--) {
			for (int j = n - 1; j > i; j--) {
				if (arr[i] > arr[j])
					q[i] = max(q[i], 1 + q[j]);
			}
		}


		int mi = INT_MAX;
		for (int i = 0; i < n; i++) {
			int left = p[i];
			int right = q[i];
			mi = min(n - (left + right - 1), mi);
		}
		cout << mi << endl;
	}
	return 0;


}