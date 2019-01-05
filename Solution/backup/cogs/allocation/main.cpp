#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 120;
const int INF = 0x3f3f3f3f;

//flow
int orign[MAX][MAX], maxrem[MAX][MAX], minrem[MAX][MAX];
int s, t, node;
//graph
int pos_g[MAX][MAX], neg_g[MAX][MAX];
//spfa
int dist[MAX], pre[MAX];
bool visit[MAX];
//other
int n;

//function
int work(int remain[MAX][MAX], int graph[MAX][MAX]);
bool spfa(int remain[MAX][MAX], int graph[MAX][MAX]);
int dfs(int now, int len, int remain[MAX][MAX], int graph[MAX][MAX]);

inline int task(int index)
{
    return index + n;
}

inline void add(int i, int j, int flow, int w)
{
    orign[i][j] = maxrem[i][j] = minrem[i][j] = flow;
    pos_g[i][j] = neg_g[j][i] = w;
    pos_g[j][i] = neg_g[i][j] = -w;
}

//main
int main()
{
    //file
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    //input
    cin >>n;
    s = 0;
    node = t = n*2+1;
    for(int i = 1; i <= n; ++i)
    {
        add(s, i, 1, 0);
        for(int j = 1; j <= n; ++j)
        {
            int temp;
            cin >>temp;
            add(i, task(j), 1, temp);
        }
    }
    for(int i = 1; i <= n; ++i)
        add(task(i), t, 1, 0);
    //work
    int minn = work(minrem, pos_g);
    int maxx = -work(maxrem, neg_g);
    //output
    cout <<minn <<"\n" <<maxx <<"\n";
    return 0;
}

int work(int remain[MAX][MAX], int graph[MAX][MAX])
{
    int ans = 0;
    while(spfa(remain, graph))
        dfs(s, INF, remain, graph);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(orign[i][task(j)] && !remain[i][task(j)])
                ans += graph[i][task(j)];
    return ans;
}

bool spfa(int remain[MAX][MAX], int graph[MAX][MAX])
{
    //init
    queue<int> work;
    memset(pre, 0, sizeof(pre));
    memset(dist, 0x7f, sizeof(dist));
    memset(visit, 0, sizeof(visit));
    dist[s] = 0;
    dist[t] = INF;
    pre[s] = -1;
    work.push(s);
    visit[s] = true;
    //work
    while(!work.empty())
    {
        int now = work.front();
        work.pop();
        visit[now] = false;
        for(int i = 0; i <= node; ++i)
        {
            if(remain[now][i] && dist[i] > dist[now] + graph[now][i])
            {
                dist[i] = dist[now] + graph[now][i];
                pre[i] = now;
                if(!visit[i])
                {
                    work.push(i);
                    visit[i] = true;
                }
            }
        }
    }
    return dist[t] != INF;
}

int dfs(int now, int len, int remain[MAX][MAX], int graph[MAX][MAX])
{
    if(now == t)
        return len;
    for(int i = 0; i <= node; ++i)
    {
        if(pre[i] == now && remain[now][i])
        {
            int t = dfs(i, min(len, remain[now][i]), remain, graph);
            if(t)
            {
                remain[now][i] -= t;
                remain[i][now] += t;
                return t;
            }
        }
    }
    return 0;
}
