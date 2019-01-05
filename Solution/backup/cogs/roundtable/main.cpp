#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 500;
const int INF = 0x3f3f3f3f;

int graph[MAX][MAX], remain[MAX][MAX], depth[MAX];
int s, t, node;
int m, n, all;

int dinic();
bool bfs();
int dfs(int now, int dist);

inline int table(int index)
{
    return index + m;
}

int main()
{
    //file
    //freopen("roundtable.in", "r", stdin);
    //freopen("roundtable.out", "w", stdout);
    //input and process
    cin >>m >>n;
    s = 0;
    node = t = m + n + 1;

    for(int i = 1; i <= m; ++i)
    {
        cin >>remain[s][i];
        all += graph[s][i] = remain[s][i];
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            remain[j][table(i)] = graph[j][table(i)] = 1;
        cin >>remain[table(i)][t];
    }
    //work
    int ans = dinic();
    //output
    if(ans == all)
    {
        cout <<1 <<"\n";
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
                if(graph[i][table(j)] && !remain[i][table(j)])
                    cout <<j <<" ";
            cout <<"\n";
        }
    }
    else
        cout <<0 <<"\n";

    return 0;
}

int dinic()
{
    int ans = 0;
    while(bfs())
        while(int t = dfs(s, INF))
            ans += t;
    return ans;
}

bool bfs()
{
    //init
    memset(depth, 0, sizeof(depth));
    queue<int> work;

    depth[s] = 1;
    work.push(s);
    //work
    while(!work.empty())
    {
        int now = work.front();
        work.pop();
        for(int i = 0; i <= node; ++i)
            if(!depth[i] && remain[now][i])
            {
                depth[i] = depth[now] + 1;
                work.push(i);
            }
    }
    //return
    if(depth[t])
        return true;
    else
        return false;
}

int dfs(int now, int dist)
{
    if(now == t)
        return dist;
    for(int i = 0; i <= node; ++i)
        if(depth[i] == depth[now] + 1 && remain[now][i])
        {
            int t = dfs(i, min(dist, remain[now][i]));
            if(t > 0)
            {
                remain[now][i] -= t;
                remain[i][now] += t;
                return t;
            }
        }
    return 0;
}
