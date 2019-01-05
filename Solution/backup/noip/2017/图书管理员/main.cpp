#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 1001;
const int INF = 0x3f3f3f3f;

int book[MAX], reader[MAX];

bool check(int b, int g);

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	int n, q, t;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; ++i)
		scanf("%d", book+i);
	for(int i = 0; i < q; ++i)
		scanf("%d %d", &t, reader+i);
	//work && output
	for(int i = 0; i < q; ++i)
	{
		int ans = INF;
		for(int j = 0; j < n; ++j)
			if(check(book[j], reader[i]))
				ans = min(ans, book[j]);
		if(ans == INF)
			ans = -1;
		printf("%d\n", ans);
	}
	//end
	return 0;
} 

bool check(int b, int g)
{
	while(g)
	{
		int num = g%10;
		if(b%10 != num)
			return false;
		b /= 10;
		g /= 10;
	}
	return true;
}
