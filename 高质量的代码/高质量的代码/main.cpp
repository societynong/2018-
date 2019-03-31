#include<bits/stdc++.h>
using namespace std;

double Power(double di, int zhi) {
	double base = di;
	double res = 1.0;

	if (zhi < 0) {
		base = 1.0 / di;
		zhi = -zhi;
	}
		

	while (zhi) {
		if (zhi & 1)
			res *= base;
		base *= base;
		zhi >>= 1;
	}
	return res;
}

void operator++(string &str) {
	int jinwei = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		int digit = str[i] - '0';
		int v = digit + jinwei ;
		jinwei = v / 10;
		digit = v % 10;
		str[i] = digit + '0';
	}
	if (jinwei)
		str = "1" + str;
}

void print1ToMaxOfNDigit(int n) {
	string str = "1";
	while (str.size() <= n) {
		cout << str << " ";
		++str;
	}
	cout << endl;
}

vector<string> rec;
template<typename T>
ostream& operator << (ostream& os, vector<T> v) {
	for (auto item : v)
		os << item << " ";
	return os;
}
void quanpailie(string &str,int i) {
	if (i == str.size()) {
		rec.push_back(str);
	}
	else {
		for (int j = i; j < str.size(); j++) {
			swap(str[i], str[j]);
			quanpailie(str, i + 1);
			swap(str[i], str[j]);
		}

	}
		
}


int partition(vector<int>  &arr, int start, int end) {
	int small = start - 1;
	for (int i = start; i < end; i++) {
		if (arr[i] < arr[end]) {
			swap(arr[++small], arr[i]);
		}
	}
	swap(arr[small + 1], arr[end]);
	return small + 1;
}

int findMoreThanHalf(vector<int> &arr) {
	int l = 0;
	int r = arr.size() - 1;
	int mid = (l + r) / 2;
	int loc;
	do {
		loc = partition(arr, l, r);
		if (loc > mid) {
			r = loc-1;
		}
		else if (loc < mid) {
			l = loc+1;
		}
	} while (loc != mid);
	return arr[mid];
}



int findMid(vector<int> &arr) {
	priority_queue<int, vector<int>, less<int> > mxh;
	priority_queue<int, vector<int>, greater<int> > mih;
	for (int i = 0; i < arr.size(); i++) {
		if (mih.empty() && mxh.empty()) {
			mih.push(arr[i]);
		}
		else {
			if (mih.top() < arr[i]) {
				mih.push(arr[i]);
			}
			else {
				mxh.push(arr[i]);
			}

			if (mih.size() == mxh.size() + 2) {
				mxh.push(mih.top());
				mih.pop();
			}
			else if (mih.size() + 2 == mxh.size()) {
				mih.push(mxh.top());
				mxh.pop();
			}
		}
		
	}

	if (mxh.size() > mih.size())
		return mxh.top();
	else if (mih.size() > mxh.size())
		return mih.top();
	else
		return (mxh.top() + mih.top()) / 2;
}
void test() {
	vector<int> arr = { 7,3,1,5,2,0,1,9 };
	cout << findMid(arr) << endl;
}
int main() {
	test();
	return 0;
}