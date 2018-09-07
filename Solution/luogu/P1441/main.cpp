#include <iostream>
#include <cstdio>
#include <cstring>

const int MAX = 21;

int w[MAX];
bool ban[MAX], f[MAX*100];
int n, m, ans;

void dfs(int now, int cnt);
void update();

int main()
{
	//file
	//freopen("data.in", "r", stdin);
	//input
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", w+i);
	//work
	dfs(0, 0);
	//output
	printf("%d", ans);
	//end
	return 0;
}

void dfs(int now, int cnt)
{
	if(cnt > m)
		return;
	else if(now == n)
	{
		if(cnt == m)
			update();
	}
	else
	{
		dfs(now+1, cnt);
		ban[now] = true;
		dfs(now+1, cnt+1);
		ban[now] = false;
	}
	
}

void update()
{
	memset(f, 0, sizeof(f));
	f[0] = true;
	int all = 0, res = 0;
	for(int i = 0; i < n; ++i)
		if(!ban[i])
		{
			for(int j = all; j >= 0; --j)
				if(f[j] && !f[j+w[i]])
				{
					f[j+w[i]] = true;
					++res;
				}
			all += w[i];
		}
	ans = std::max(ans, res);
}
