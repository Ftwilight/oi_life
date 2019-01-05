#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000005;

struct Line
{
	int b, e;
	bool operator<(Line const &o) const
	{
		return e < o.e;
	}
};
Line line[MAX];

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//init
	int n;
	//input
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &line[i].b, &line[i].e);
	//work
	sort(line, line+n);
	int ans = 1;
	int end = line[0].e;
	for(int i = 1; i < n; ++i)
	{
		if(line[i].b >= end)
		{
			++ans;
			end = line[i].e;
		}
	}
	//output
	printf("%d", ans);
	//end
	return 0;
}
