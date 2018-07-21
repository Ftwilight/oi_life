#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 1050;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Post
{
    int x, y;
    Post(int a=0, int b=0):x(a), y(b)
    {}  
};

int ans[MAX][MAX];
bool maze[MAX][MAX], visit[MAX][MAX];
int n, m;

inline int ask(int x, int y);
void bfs(int x, int y);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%1d", &maze[i][j]);
    for(int i = 0; i < m; ++i)
    {
        int tx, ty;
        scanf("%d %d", &tx ,&ty);
        //work && output
        printf("%d\n", ask(tx, ty));
    }
    //end
    return 0;
}

inline int ask(int x, int y)
{
    if(!ans[x][y])
        bfs(x, y);
    return ans[x][y];
}

void bfs(int x, int y)
{
    int res = 0;
    queue<Post> work;
    stack<Post> record;
    Post begin(x, y);
    
    work.push(begin);
    visit[begin.x][begin.y] = true;
    while(!work.empty())
    {
        Post now = work.front();
        work.pop();
        record.push(now);
        ++res;
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = now.x+dx[i], ny = now.y+dy[i];
            if(nx > 0 && nx <= n && ny > 0 && ny <= n)
            {
                Post step(nx, ny);
                if(maze[step.x][step.y] != maze[now.x][now.y] && !visit[step.x][step.y])
                {
                    work.push(step);
                    record.push(step);
                    visit[step.x][step.y] = true;
                }
            }
        }
    }
    
    while(!record.empty())
    {
        ans[record.top().x][record.top().y] = res;
        record.pop();
    }
}

