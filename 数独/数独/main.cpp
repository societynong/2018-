#include<bits/stdc++.h>

using namespace std;

bool isOk(int mat[][9], int t, int i, int j) {
	for (int id = 0; id < 9; id++) {
		if (mat[id][j] == t)
			return false;
		if (mat[i][id] == t)
			return false;
	}

	int i0 = i / 3 * 3;
	int j0 = j / 3 * 3;
	for (int si = 0; si < 3;si++)
		for (int sj = 0; sj < 3; sj++)
			if (mat[i0 + si][j0 + sj] == t)
				return false;
	return true;

}

void showResult(int mat[][9]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j == 8)
				cout << mat[i][j] << endl;
			else
				cout << mat[i][j] << " ";
		}
	}
}

void dfs(int mat[][9], int i, int j) {
	if (i == 9) {
		showResult(mat);
		return;
	}

	int ni = i;
	int nj = j + 1;
	if (nj == 9)
		++ni, nj = 0;
	if (mat[i][j] != 0) {
		dfs(mat, ni, nj);
	}
	else {
		for (int t = 1; t <= 9; t++) {
			if (isOk(mat, t, i, j)) {
				mat[i][j] = t;
				dfs(mat, ni, nj);
				mat[i][j] = 0;
			}
		}
	}


}


int main() {
	int mat[9][9] = { 0 };
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> mat[i][j];
	dfs(mat, 0, 0);
	return 0;
}