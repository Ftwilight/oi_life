#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 105;
const int INF = 0x3f3f3f3f;

int depth[MAX];
int graph[MAX][MAX];
int s, t, n, n1;

int dinic();
bool bfs();
int dfs(int now, int dist);

int main()
{
    //init
    freopen("flyer.in", "r", stdin);
    freopen("flyer.out", "w", stdout);
    s = 0;
    //input
    cin >>n >>n1;
    n += 1;
    t = n;
    int a, b;
    while(cin >>a >>b)
    {
        graph[a][b] = 1;
        graph[s][a] = 1;
        graph[b][t] = 1;
    }

    //work
    int ans = dinic();
    //input
    cout <<ans <<"\n";
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
    for(int i = 0; i <= n; ++i)
        depth[i] = 0;
    depth[s] = 1;
    //work
    while(!proc.empty())
    {
        int now = proc.front();
        proc.pop();
        for(int i = 0; i <= n; ++i)
            if(graph[now][i] > 0 && !depth[i])
            {
                proc.push(i);
                depth[i] = depth[now] + 1;
            }
    }
    if(depth[t] == 0)
        return false;
    else
        return true;
}

int dfs(int now, int dist)
{
    if(now == t)
        return dist;
    for(int i = 0; i <= n; ++i)
        if(depth[i] == depth[now] + 1 && graph[now][i] != 0)
        {
            int t = dfs(i, min(dist, graph[now][i]));
            if(t > 0)
            {
                graph[now][i] -= t;
                graph[i][now] += t;
                return t;
            }
        }
    return 0;
}
