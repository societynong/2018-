#include<bits/stdc++.h>

using namespace std;

pair<int,int> searchInMat(int mat[][5],int target) {
	int row = 4;
	int col = 0;

	while (row >= 0 && row < 5 && col >= 0 && col < 5) {
		if (mat[row][col] > target)
			--row;
		else if (mat[row][col] < target)
			++col;
		else
			return make_pair(row, col);
	}
	return make_pair(-1, -1);
}

ostream& operator << (ostream&ot, pair<int, int> &pir) {
	ot << pir.first << " " << pir.second;
	return ot;
}

void test() {
	int mat[][5] = { {1,2,3,4,5},{3,5,6,8,9},{7,8,9,10,15},{9,11,12,17,19},{11,15,16,18,19} };
	cout << searchInMat(mat,12) << endl;
}

int main() {
	test();
	return 0;
}