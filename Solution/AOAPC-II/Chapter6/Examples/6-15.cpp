#include <cstdio>
#include <cstring>

const int MAX = 105;

bool g[MAX][MAX];
bool visit[MAX];
int ans[MAX];
int cnt = MAX;

void init();
void toposort(int n);
void dfs(int now, int n);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && (n || m))
    {
        init();
        for(int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            g[a][b] = true;
        }
        //work
        toposort(n);
        //output
        printf("%d", ans[cnt]);
        while(++cnt < MAX)
            printf(" %d", ans[cnt]);
        printf("\n");
    }
    //end
    return 0;
}

void toposort(int n)
{
    for(int i = 1; i <= n; ++i)
        if(!visit[i])
            dfs(i, n);
}

void dfs(int now, int n)
{
    visit[now] = true;
    for(int i = 1; i <= n; ++i)
        if(g[now][i] && !visit[i])
            dfs(i, n);
    ans[--cnt] = now;
}

void init()
{
    memset(g, 0, sizeof(g));
    memset(ans, 0, sizeof(ans));
    memset(visit, 0, sizeof(visit));
    cnt = MAX;
}
