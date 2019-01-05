#include <iostream> 
#include <cstdio>
using namespace std;

const int MAX = 105;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int r, c;
int area[MAX][MAX];
int record[MAX][MAX];

int dfs(int x, int y);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            scanf("%d", &area[i][j]);
    //work
    int ans = 0;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            ans = max(ans, dfs(i, j));
    //output
    debug();
    printf("%d\n", ans);
    //end
    return 0;
}

int dfs(int x, int y)
{
    if(record[x][y])
        return record[x][y];
    
    int ans = 1;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && area[nx][ny] < area[x][y])
            ans = max(ans, 1 + dfs(nx, ny));
        
    }
    return record[x][y] = ans;
}










