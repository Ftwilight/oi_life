#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 420;
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

struct Pos
{
    int x, y;
    Pos(int a=0, int b=0):x(a), y(b)
    {}
};

int ans[MAX][MAX];

void bfs(int n, int m, int x, int y);
void output(int n, int m);

int main()
{
    //freopen("data.in", "r", stdin);
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    bfs(n, m, x, y);
    output(n, m);
    return 0;
}

void bfs(int n, int m, int x, int y)
{
    queue<Pos> work;
    memset(ans, -1, sizeof(ans));
    ans[x][y] = 0;
    
    work.push(Pos(x, y));
    while(!work.empty())
    {
        int nx = work.front().x;
        int ny = work.front().y;
        work.pop();
        for(int i = 0; i < 8; ++i)
        {
            int tx = nx+dx[i];
            int ty = ny+dy[i];
            if(tx>0 && tx<=n && ty>0 && ty<=m && ans[tx][ty] == -1)
            {
                ans[tx][ty] = ans[nx][ny] + 1;
                work.push(Pos(tx, ty));
            }
        }
    }
}

void output(int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            printf("%-5d", ans[i][j]);
        printf("\n");
    }
}
