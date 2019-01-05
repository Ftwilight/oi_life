#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAX = 200005;
const int MAX_NODE = 5005;

struct Edge
{
	int x, y, v;
	bool operator<(const Edge &o) const
	{
		return v < o.v;
	}	
};

Edge edge[MAX];
int fa[MAX_NODE];
int n, m;

int kruskal(bool &flag);
int find(int a);

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i)
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].v);
	//work
	bool flag = true;
	int ans = kruskal(flag);
	//output
	if(flag)
		printf("%d", ans);
	else
		printf("org");
	//end
	return 0;
}

int kruskal(bool &flag)
{
	//init
	std::sort(edge, edge+m);
	for(int i = 1; i <= n; ++i)
		fa[i] = i;

	int cnt = 0, ans = 0;
	//kruskal
	for(int i = 0; i < m && cnt < n-1; ++i)
	{
		int f1 = find(edge[i].x);
		int f2 = find(edge[i].y);
		if(f1 != f2)
		{
			++cnt;
			fa[f1] = f2;
			ans += edge[i].v;
		}
	}
	if(cnt < n-1)
		flag = false;
	return ans;
}

int find(int a)
{
	return (fa[a] == a)? a: fa[a] = find(fa[a]);
}
