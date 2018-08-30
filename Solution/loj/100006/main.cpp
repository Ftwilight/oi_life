#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 100005;

int num[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//init
	int n, m;
	//input
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", num+i);
	//work
	int sum = 0;
	int ans = 1;
	for(int i = 0; i < n; ++i)
	{
		if(sum + num[i] > m)
		{
			sum = 0;
			++ans;
		}
		sum += num[i];
	}
	//output
	printf("%d", ans);
	//end
	return 0;
}
