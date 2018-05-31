//A wrong solution, but the sample output is right.
//I don't know why it is wrong.
//If you find bugs, please contact me :)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//const
const int MAX_N = 20;
const int MAX_S = 50;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

char dirs[] = "NESW";
char turns[] = "FLR";

//struct
struct Node
{
    int x;
    int y;
    int dir;
    Node():x(0), y(0), dir(0)
    {}
    Node(int a, int b, int c):x(a), y(b), dir(c)
    {}
};

//global
bool path[MAX_N][MAX_N][4][3];//x y dir trun
int dist[MAX_N][MAX_N][4];
Node pre[MAX_N][MAX_N][4];
string name;

//function
int dirs_id(char x);
int turn_id(char x);
bool inside(int x, int y);

void init();
Node walk(const Node &n, int turn);
void bfs(int bx, int by, int ex, int ey, int enter);
void print_ans(Node now, int bx, int by, int enter);

//main
int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(cin >>name && name != "END")
    {
        init();
        int bx, by, ex, ey, enter;
        char init_dir;
        scanf("%d %d %[A-Z] %d %d", &bx, &by, &init_dir, &ex, &ey);
        enter = dirs_id(init_dir);
        int tx;
        while(scanf("%d", &tx) == 1 && tx)
        {
            int ty;
            char p[MAX_S];
            scanf("%d", &ty);
            while(scanf("%s", p) == 1 && p[0] != '*')
            {
                int dir = dirs_id(p[0]);
                int len = strlen(p);
                for(int i = 1; i < len; ++i)
                    path[tx][ty][dir][turn_id(p[i])] = true;
            }
        }
        //work
        cout <<name <<"\n";
        bfs(bx, by, ex, ey, enter);
    }
    //end
    return 0;
}

//define
int dirs_id(char x)
{
    return strchr(dirs, x) - dirs;
}

int turn_id(char x)
{
    return strchr(turns, x) - turns;
}

bool inside(int x, int y)
{
    if(x >= 1 && x <= 9 && y >= 1 && y <= 9)
        return true;
    return false;
}

void init()
{
    memset(path, 0, sizeof(path));
    memset(dist, -1, sizeof(dist));
}

Node walk(const Node &n, int turn)
{
    int dir = n.dir;
    if(turn == 1)
        dir = (dir+3)%4;
    else if(turn == 2)
        dir = (dir+1)%4;
    return Node(n.x+dx[dir], n.y+dy[dir], dir);
}

void bfs(int bx, int by, int ex, int ey, int enter)
{
    queue<Node> work;

    Node i(bx, by, enter);
    Node begin = walk(i, 0);
    dist[begin.x][begin.y][begin.dir] = 0;

    work.push(begin);
    while(!work.empty())
    {
        Node now = work.front();
        work.pop();
        if(now.x == ex && now.y == ey)
        {
            print_ans(now, bx, by, enter);
            return;
        }
        for(int i = 0; i < 3; ++i)
        {
            Node n = walk(now, i);
            if(path[now.x][now.y][now.dir][i] && dist[n.x][n.y][n.dir] < 0 && inside(n.x, n.y))
            {
                pre[n.x][n.y][n.dir] = now;
                dist[n.x][n.y][n.dir] = dist[now.x][now.y][now.dir] + 1;
                work.push(n);
            }
        }

    }
    printf("  No Solution Possible\n");
}

void print_ans(Node now, int bx, int by, int enter)
{
    vector<Node> ans;
    while(true)
    {
        ans.push_back(now);
        if(!dist[now.x][now.y][now.dir])
            break;
        now = pre[now.x][now.y][now.dir];
    }
    ans.push_back(Node(bx, by, enter));

    int cnt = 0;
    for(int i = ans.size() - 1; i >= 0; --i)
    {
        if(!(cnt%10))
            printf(" ");
        printf(" (%d,%d)", ans[i].x, ans[i].y);
        if(!(++cnt%10))
            printf("\n");
    }
    if(ans.size()%10)
        printf("\n");
}
