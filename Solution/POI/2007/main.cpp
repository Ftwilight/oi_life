#include <cstdio>
#include <iostream>

const int MAX = 1100;
const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int n, top, bottom;
int mat[MAX][MAX];
bool visited[MAX][MAX];
struct Lat
{
    int x, y, h;
    void build(int a, int b)
    {
        x = a;
        y = b;
        h = mat[a][b];
    }
};
Lat que[MAX*MAX];

int bfs(int a, int b);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &mat[i][j]);
    //work
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(!visited[i][j])
            {
                int t = bfs(i, j);
                if(t == 1 || t == 3)
                    ++top;
                if(t == 2 || t == 3)
                    ++bottom;
            }
    //output
    printf("%d %d", top, bottom);
    //end
    return 0;
}

int bfs(int a, int b)
{
    int x, y, h, nx, ny;
    
    bool is_top = true, is_bot = true;
    int head = 0, tail = 0;
    que[0].build(a, b);
    visited[a][b] = true;
    
    while(tail <= head)
    {
        x = que[tail].x;
        y = que[tail].y;
        h = que[tail++].h;
        for(int i = 0; i < 8; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n)
            {
                if(mat[nx][ny] == h && !visited[nx][ny])
                {
                    que[++head].build(nx, ny);
                    visited[nx][ny] = true;
                }
                else if(mat[nx][ny] > h)
                    is_top = false;
                else if(mat[nx][ny] < h)
                    is_bot = false;
            }
        }
    }
    
    if(!is_top && !is_bot)
        return 0;
    else if(is_top && is_bot)
        return 3;
    else if(is_top)
        return 1;
    else
        return 2;
}
