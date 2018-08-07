#include <cstdio>
#include <cstring>

const int MAX = 105;

char mat[MAX][MAX];
int idx[MAX][MAX];
int m, n;

void dfs(int x, int y, int id);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(scanf("%d %d", &m, &n) == 2 && m)
    {
        memset(idx, 0, sizeof(idx));
        int ans = 0;
        for(int i = 0; i < m; ++i)
            scanf("%s", mat[i]);
        //work
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == '@' && !idx[i][j])
                    dfs(i, j, ++ans);
        //output
        printf("%d\n", ans);
    }
    //end
    return 0;
}

void dfs(int x, int y, int id)
{
    if(x < 0 || x >= m || y < 0 || y >= n)
        return;
    else if(mat[x][y] != '@' || idx[x][y])
        return;
    idx[x][y] = id;
    for(int dx = -1; dx <= 1; ++dx)
        for(int dy = -1; dy <= 1; ++dy)
            dfs(x+dx, y+dy, id);
}
