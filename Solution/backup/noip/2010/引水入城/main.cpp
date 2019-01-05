#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 501;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int mat[MAX][MAX];
int l[MAX][MAX], r[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

void dfs(int x, int y);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &mat[i][j]);
    //init
    memset(l, 0x3f, sizeof(l));
    for(int i = 1; i <= m; ++i)
        l[n][i] = r[n][i] = i;
    //work
    for(int i = 1; i <= m; ++i)
        if(!visited[1][i])
            dfs(1, i);
    //check && output
    //cannot
    int cnt = 0;
    for(int i = 1; i <= m; ++i)
        if(!visited[n][i])
            ++cnt;
    if(cnt)
    {
        printf("0\n%d\n", cnt);
        return 0;
    }
    //ok
    int ans = 0;
    int left = 1;
    while(left <= m)
    {
        int maxr = 0;
        for(int i = 1; i <= m; ++i)
            if(l[1][i] <= left)
                maxr = max(maxr, r[1][i]);
        left = maxr+1;
        ++ans;
    }
    printf("1\n%d\n", ans);
    //end
    return 0;
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx <= n && ny > 0 && ny <= m && mat[nx][ny] < mat[x][y])
        {
            if(!visited[nx][ny])
                dfs(nx, ny);
            l[x][y] = min(l[x][y], l[nx][ny]);
            r[x][y] = max(r[x][y], r[nx][ny]);
        }
    }
}
