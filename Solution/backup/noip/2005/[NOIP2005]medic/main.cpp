#include <iostream>
#include <cstdio>
using namespace std;

int res[1001];
int w[101];
int t[101];
int main()
{
    //freopen("medic.in", "r", stdin);
    //freopen("medic.out", "w", stdout);
	int time, num;
	cin >>time >>num;
	for(int index=1; index<=num; ++index)
		cin >>t[index] >>w[index];
	for(int i=1; i<=num; ++i)
		for(int j=time; j>=t[i]; --j)
			res[j] = max(res[j], res[j-t[i]]+w[i]);
	cout <<res[time];
	return 0;
}
