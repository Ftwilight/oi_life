#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 2005;

int graph[MAX][MAX], remain[MAX][MAX];
int depth[MAX], need[25];
int k, n, m, node;
int s, t;

bool bfs();
int dfs(int now, int dist);
int dinic();
inline int quest(int index)
{
    return index + k;
}

int main()
{
    //file
    freopen("testlib.in", "r", stdin);
    freopen("testlib.out", "w", stdout);
    //input and init
    cin >>k >>n;
    s = 0;
    node = t = k + n + 1;
    for(int i = 1; i <= k; ++i)
    {
        cin >>graph[s][i];
        m += (remain[s][i] = graph[s][i]);
    }
    for(int i = 1; i <= n; ++i)
    {
        int num, temp;
        cin >>num;
        for(int j = 0; j < num; ++j)
        {
            cin >>temp;
            remain[temp][quest(i)] = graph[temp][quest(i)] = 1;
        }
        remain[quest(i)][t] = graph[quest(i)][t] = 1;
    }
    //work
    int ans = dinic();
    //search and output
    if(ans != m)
        cout <<"NoSolution!\n";
    else
    {
        for(int i = 1; i <= k; ++i)
        {
            cout <<i <<": ";
            for(int j = 1; j <= n; ++j)
                if(graph[i][quest(j)] && !remain[i][quest(j)])
                    cout <<j <<" ";
            cout <<"\n";
        }
    }
    return 0;
}

int dinic()
{
    int ans = 0;
    while(bfs())
        while(int x = dfs(s, INF))
            ans += x;
    return ans;
}

bool bfs()
{
    //init
    queue<int> work;
    memset(depth, 0, sizeof(depth));
    depth[s] = 1;
    work.push(s);
    //work
    while(!work.empty())
    {
        int now = work.front();
        work.pop();
        for(int i = 0; i <= node; ++i)
            if(remain[now][i] > 0 && !depth[i])
            {
                depth[i] = depth[now] + 1;
                work.push(i);
            }
    }
    //return
    if(depth[t] == 0)
        return false;
    else
        return true;
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
