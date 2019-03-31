

#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> a;
int book[210], match[210];
int dfs(int);
int isp[100000] = { 0 };
void su();
int main()
{
	int N, i, t;
	su();
	for (;scanf("%d", &N) != EOF;)
	{
		a.clear();
		int sum = 0;
		for (i = 0;i<N;scanf("%d", &t), a.push_back(t), i++);
		memset(match, -1, sizeof(match));
		for (i = 0;i<a.size();i++)
		{
			if (a[i] % 2 == 0) {
				memset(book, 0, sizeof(book)); book[i] = 1;
				if (dfs(i)) sum++;
			}
		}
		printf("%d\n", sum);
	}
}

int dfs(int x)
{
	int i;
	for (i = 0;i<a.size();i++)
		if (a[i] % 2 == 1 && isp[a[i] + a[x]] == 0 && book[i] == 0)
		{
			book[i] = 1;
			if (match[i] == -1 || dfs(match[i]))
			{
				//printf("%d->%d\n",a[x],a[i]);
				match[i] = x;
				match[x] = i;
				return 1;
			}
		}
	return 0;
}

void su()
{
	isp[0] = isp[1] = 1;
	int i, j;
	for (i = 2;i<100000;i++)
		if (isp[i] == 0) {
			for (j = 2 * i;j<100000;j += i) isp[j] = 1;
		}
}