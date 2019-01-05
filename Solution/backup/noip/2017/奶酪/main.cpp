#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 1001;

int x[MAX], y[MAX], z[MAX];
bool visited[MAX];
int n, h, r;

bool dfs(int u);
inline bool check(int a, int b);

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	int all;
	scanf("%d", &all);
	while(all--)
	{
		scanf("%d %d %d", &n, &h, &r);
		bool have_bot = false, have_top = false;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d %d %d", x+i, y+i, z+i);
			if(z[i] + r >= h)
				have_top = true;
			if(z[i] - r <= 0)
				have_bot = true;
		}
		//work
		bool flag = true;
		if(have_bot && have_top)
		{
			memset(visited, 0, sizeof(visited));
			for(int i = 0; i < n; ++i)
				if(z[i] - r <= 0 && dfs(i))
				{
					printf("Yes\n");
					flag = false;
					break;
				}
		}
		if(flag)
			printf("No\n");		
	}
	//end
	return 0;
}

bool dfs(int u)
{
	if(z[u] + r >= h)
		return true;
	
	visited[u] = true;
	for(int i = 0; i < n; ++i)
		if(!visited[i] && check(u, i) && dfs(i))
			return true;
	
	return false;
}

inline bool check(int a, int b)
{
	double d = sqrt(pow(x[a]-x[b], 2) + pow(y[a]-y[b], 2) + pow(z[a]-z[b], 2));
	return double(r*2) >= d;
}
