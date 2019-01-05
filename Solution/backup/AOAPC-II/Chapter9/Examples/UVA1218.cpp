#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10005;

vector<int> g[MAX], stk;
int fa[MAX], d[MAX][3];
int n;

inline void init();
void dfs(int now, int f);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(cin >>n)
    {
        init();
        int ta, tb;
        for(int i = 1; i < n; ++i)
        {
            cin >>ta >>tb;
            g[ta].push_back(tb);
            g[tb].push_back(ta);
        }
        //work && output
        dfs(1, 0);
        for(int i = stk.size()-1; i >= 0; --i)
        {
            int u = stk[i];
            d[u][0] = 1;
            d[u][1] = 0;
            for(int j = 0; j < g[u].size(); ++j)
            {
                int v = g[u][j];
                if(v == fa[u])
                    continue;
                d[u][0] += min(d[v][0], d[v][1]);
                d[u][1] += d[v][2];
            }
            d[u][2] = n+1;
            for(int j = 0; j < g[u].size(); ++j)
            {
                int v = g[u][j];
                if(v == fa[u])
                    continue;
                d[u][2] = min(d[u][2], d[u][1]-d[v][2]+d[v][0]);
            }
        }
        //output
        printf("%d\n", min(d[1][0], d[1][2]));
        //end
        int flag;
        cin >>flag;
        if(flag == -1)
            return 0;
    }
    return 0;
}

inline void init()
{
    for(int i = 1; i <= n; ++i)
        g[i].clear();
    stk.clear();
}

void dfs(int now, int f)
{
    stk.push_back(now);
    fa[now] = f;
    for(int i = 0; i < g[now].size(); ++i)
        if(g[now][i] != f)
            dfs(g[now][i], now);
}
