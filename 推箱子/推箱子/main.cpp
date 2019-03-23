/*
 * main.cpp
 *
 *  Created on: 2019Äê3ÔÂ22ÈÕ
 *      Author: ZYN
 */

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct State {
	int row;
	int col;
	int rowB;
	int colB;
	int step;
	State(int r, int c, int rb, int cb, int s) :
			row(r), col(c), rowB(rb), colB(cb), step(s) {
	}
	;
};
struct State1 {
	int row;
	int col;
	int rowB;
	int colB;
	State1(int r, int c, int rb, int cb) :
			row(r), col(c), rowB(rb), colB(cb) {
	}
	;
};

int main() {
	int n, m;
	fstream fs;
	fs.open("input.txt");
	fs >> n >> m;

	vector<vector<char>> mat(n, vector<char>(m));
	int rb = -1;
	int cb = -1;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			fs >> mat[row][col];
			if (mat[row][col] == '0') {
				rb = row;
				cb = col;
			}
		}
	}
	fs.close();
	if (rb == -1 || cb == -1) {
		cout << "-1" << endl;
		return 0;
	}

	int dirs[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	queue<State> q;
	q.push(State(0, 0, rb, cb, 0));
	set<pair<pair<int,int>,pair<int,int>>> st;
	st.insert(make_pair(make_pair(0, 0),make_pair(rb, cb)));
	int res = -1;
	while (!q.empty()) {
		State fS = q.front();
		q.pop();
		int r = fS.row;
		int c = fS.col;
		int rb = fS.rowB;
		int cb = fS.colB;
		int s = fS.step;

		for (int i = 0; i < 4; i++) {
			int rn = r + dirs[i][0];
			int cn = c + dirs[i][1];
			if (rn >= 0 && rn < n && cn >= 0 && cn < m) {
				if (rn == rb && cn == cb) {
					int rbn = rb + dirs[i][0];
					int cbn = cb + dirs[i][1];
					if (rbn >= 0 && rbn < n && cbn >= 0 && cbn < m) {
						if (mat[rbn][cbn] == '.') {
							if (st.find(make_pair(make_pair(rn, cn), make_pair(rbn, cbn))) == st.end()) {
								q.push(State(rn, cn, rbn, cbn, s + 1));
								st.insert(make_pair(make_pair(rn, cn), make_pair(rbn, cbn)));
							}
						}
						else if (mat[rbn][cbn] == 'E') {
							res = s + 1;
							cout << res + 1 << endl;
							return 0;
						}
					}
				}
				else {
					if (mat[rn][cn] == '.' && st.find(make_pair(make_pair(rn, cn), make_pair(rb, cb))) == st.end()) {
						//cout << rn << "," << cn <<" "<< rb << "," << cb << endl;
						q.push(State(rn, cn, rb, cb, s + 1));
						st.insert(make_pair(make_pair(rn, cn), make_pair(rb, cb)));
					}
				}

			}
		}
	}
	cout << res << endl;
	return 0;
}

	
