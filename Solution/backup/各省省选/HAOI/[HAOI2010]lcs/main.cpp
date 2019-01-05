#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 5005;
const int MOD = 1e8;
char s1[MAX], s2[MAX];
int f[MAX][MAX];//question 1
int f2[MAX][MAX];//question 2

int main()
{
    //init
#ifndef LOCAL
    freopen("lcs.in", "r", stdin);
    freopen("lcs.out", "w", stdout);
#endif
	//input
	cin >>(s1+1) >>(s2+1);
	int size1 = strlen(s1+1);
	int size2 = strlen(s2+1);
	//init
	for(int i=max(size1, size2); i>=0; --i)
		f2[i][0] = f2[0][i] = 1;
	//work
	for(int i=1; i<size1; ++i)
		for(int j=1; j<size2; ++j)
		{
			if(s1[i] == s2[j])
			{
				f[i][j] = f[i-1][j-1] + 1;

				f2[i][j] = f2[i-1][j-1];
				if(f[i][j] == f[i-1][j])
					f2[i][j] += f2[i-1][j];
				if(f[i][j] == f[i][j-1])
					f2[i][j] += f2[i][j-1];
			}
			else
			{
				f[i][j] = max(f[i-1][j], f[i][j-1]);

				if(f[i][j] == f[i-1][j])
					f2[i][j] += f2[i-1][j];
				if(f[i][j] == f[i][j-1])
					f2[i][j] += f2[i][j-1];
				if(f[i][j] == f[i-1][j-1])
					f2[i][j] -= f2[i-1][j-1];
			}
            f2[i][j] %= MOD;
		}
	//output
	cout <<f[size1-1][size2-1] <<"\n" <<f2[size1-1][size2-1];
    return 0;
}
