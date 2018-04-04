#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 105;
const int INF = 0x3f3f3f3f;
int graph[MAX][MAX], depth[MAX], rem[MAX][MAX];
int s, t, n;

bool bfs();
int dfs(int u, int dist);
int dinic();

int main()
{
    freopen("maxflowa.in", "r", stdin);
    freopen("maxflowa.out", "w", stdout);
    //input
    cin >>n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin >>graph[i][j];
            rem[i][j] = graph[i][j];
        }
    //init
    s = 1;
    t = n;
    //work
    int ans = dinic();
    //output
    cout <<ans;
    return 0;
}

int dinic()
{
    int ans = 0;
    while(bfs())
    {
        while(int t = dfs(s, INF))
            ans += t;
    }
    return ans;
}

bool bfs()
{
    //init
    queue<int> proc;
    proc.push(s);
    for(int i = 1; i <= n; ++i)
        depth[i] = 0;
    depth[s] = 1;
    //work
    while(!proc.empty())
    {
        int now = proc.front();
        proc.pop();

        for(int i = 1; i <= n; ++i)
            if(!depth[i] && rem[now][i] > 0)
            {
                depth[i] = depth[now] + 1;
                proc.push(i);
            }
    }
    if(depth[t] == 0)
        return false;
    else
        return true;
}

int dfs(int u, int dist)
{
    if(u == t)
        return dist;
    for(int i = 1; i <= n; ++i)
        if(depth[i] == depth[u]+1 && rem[u][i] != 0)
        {
            int t = dfs(i, min(dist, rem[u][i]));
            if(t > 0)
            {
                rem[u][i] -= t;
                rem[i][u] += t;
                return t;
            }
        }
    return 0;
}
