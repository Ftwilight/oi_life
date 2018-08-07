#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 210;
const int INF = 0x3f3f3f3f;

struct state
{
    int cap[3];
    int dist;
    state(int x=0, int y=0, int z=0, int d=0):dist(d)
    {
        cap[0] = x;
        cap[1] = y;
        cap[2] = z;
    }
    bool operator<(const state &other) const
    {
        return dist > other.dist;
    }
};

int dist[MAX][MAX];
bool visit[MAX][MAX];
int ans[MAX];
int cap[3], d;

void init();
void bfs();
void output();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d %d %d", &cap[0], &cap[1], &cap[2], &d);
        //work
        init();
        bfs();
        //output
        output();
    }
    //end
    return 0;
}

void bfs()
{
    priority_queue<state> work;
    state begin(0, 0, cap[2], 0);

    visit[0][0] = true;
    work.push(begin);
    while(!work.empty())
    {
        state now = work.top();
        work.pop();
        //printf("[%d %d %d]\n", now.cap[0], now.cap[1], now.cap[2]);
        for(int i = 0; i < 3; ++i)
            if(now.dist < ans[now.cap[i]])
                ans[now.cap[i]] = now.dist;

        //i -> j
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                if(i != j)
                {
                    state t = now;

                    int &ta = t.cap[0], &tb = t.cap[1];
                    int &ti = t.cap[i], &tj = t.cap[j];

                    int move = min(ti, cap[j]-tj);
                    tj += move;
                    ti -= move;
                    t.dist += move;
                    if(!visit[ta][tb])
                    {
                        visit[ta][tb] = true;
                        work.push(t);
                    }
                }
    }
}

void output()
{
    for(; d >= 0; --d)
    {
        if(ans[d] != INF)
        {
            printf("%d %d\n", ans[d], d);
            return;
        }
    }
}

void init()
{
    memset(ans, INF, sizeof(ans));
    memset(visit, 0, sizeof(visit));
}
