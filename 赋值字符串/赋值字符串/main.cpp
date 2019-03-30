#include<bits/stdc++.h>

using namespace std;


int myStrLen(char *p) {
	if (p == nullptr)
		return 0;
	else {
		int cnt;
		while (p) {
			cnt++;
			p++;
		}
		return cnt;
	}

}

void myStrCpy(char *p1, char *p2) {
	do {
		*p1++ = *p2++;
	} while (p2);

}

class MyString {
private:
	char *m_pData;
public:
	MyString(char *p = nullptr) {
		if (p == nullptr) {
			m_pData = new char[1];
			m_pData[0] = '\0';
		}
		else {
			m_pData = new char[strlen(p) + 1];
			strcpy(m_pData, p);

		}

	}

	char* getData() {
		return m_pData;
	}

	MyString& operator=(MyString &s2) {
		if (this != &s2) {
			delete[] m_pData;
			m_pData = NULL;
			m_pData = new char[strlen(s2.getData()) + 1];
			strcpy(m_pData, s2.getData());
		}
		return *this;
	}
	MyString& operator=(char *p) {
		if (p == nullptr) {
			m_pData = new char[1];
			m_pData[0] = '\0';
		}
		else {
			m_pData = new char[myStrLen(p) + 1];
			myStrCpy(m_pData, p);
		}
		
		return *this;
	}
	~MyString() {
		delete[] m_pData;
	}

};

ostream& operator<<(ostream &out, MyString& str) {// Сbug &&&&&
	out << str.getData();
	return out;
}



void test1() {
	MyString str0("123");
	cout << str0 << endl;
}

void test2() {
	MyString str1("123");
	MyString str2("456");
	str1 = str2;
	cout << str1 << str2 << endl;

}

void test3() {
	MyString str1 = "123";
	cout << str1 << endl;
}

int main() {
	test3();
	return 0;

}