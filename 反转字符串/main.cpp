#include <bits/stdc++.h>

using namespace std;


int main() {
    string str;
    while(cin >> str) {
        int i = 0;
        int j = str.size() - 1;
        while(i < j) {
            swap(str[i],str[j]);
            ++i;
            --j;
        }
        cout << str << endl;
    }
    return 0;
}