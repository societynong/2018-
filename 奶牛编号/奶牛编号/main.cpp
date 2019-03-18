#include<bits/stdc++.h>
using namespace std;

vector<int> x;
vector<bool> visited;
int cnt;

void dfs(int i) {
	if (i == x.size())
		cnt++;
	else {
		for (int j = 1; j <= x[i]; j++) {
			if (!visited[j]) {
				visited[j] = true;
				dfs(i + 1);
				visited[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int mx = INT_MIN;
	x = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		mx = max(mx, x[i]);
	}
	visited = vector<bool>(mx + 1);

	cnt = 0;
	dfs(0);
	cout << cnt << endl;
	return 0;
}