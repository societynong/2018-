#include<bits/stdc++.h>

using namespace std;

int main() {
	string buf;
	cin >> buf;
	stack<int> s;
	for (int i = buf.size() - 1; i >= 0; i--) {
		if (buf[i] >= '0' && buf[i] <= '9')
			s.push(buf[i] - '0');
		else if (buf[i] >= 'A' && buf[i] <= 'F')
			s.push(buf[i] - 'A' + 10);
		else {
			if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/') {
				int op1 = s.top();
				s.pop();
				int op2 = s.top();
				s.pop();
				switch (buf[i]) {
				case '+':s.push(op1 + op2);break;
				case '-':s.push(op1 - op2);break;
				case '*':s.push(op1 * op2);break;
				case '/':s.push(op1 / op2);break;
				}
			}
		}
	}
	cout << s.top() << endl;
	return 0;
}