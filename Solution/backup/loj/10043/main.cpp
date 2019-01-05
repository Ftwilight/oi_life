#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 1005;

char s[MAX], p[MAX], next[MAX];

int kmp();

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	while(scanf("%s %s", s+1, p+1) == 2)
	{
		//work && output
		printf("%d\n", kmp());
	}
	//end
	return 0;
}

int kmp()
{
	//init
	int j = 0, ans = 0;
	int len_s = strlen(s+1);
	int len_p = strlen(p+1);
	for(int i = 2; i <= len_p; ++i)
	{
		while(j && p[j+1] != p[i])
			j = next[j];
		if(p[j+1] == p[i])
			++j;
		next[i] = j;
	}
	//kmp
	j = 0;
	for(int i = 1; i <= len_s; ++i)
	{
		while(j && p[j+1] != s[i])
			j = next[j];
		if(p[j+1] == s[i])
			++j;
		if(j == len_p)
		{
			++ans;
			j = next[j];
		}
	}
	//return
	return ans;
}
