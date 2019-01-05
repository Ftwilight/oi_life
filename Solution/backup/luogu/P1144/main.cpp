#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N_MAX = 1000005;
const int MOD = 100003;

int n, m;
vector<int> graph[N_MAX];
int dis[N_MAX], ans[N_MAX];
bool visit[N_MAX];

void bfs();

int main()
{
    //init
    memset(dis, sizeof(dis), 0x7f);
    //input
    cin >>n >>m;
    for(int i=0; i<m; ++i)
    {
        int x, y;
        cin >>x >>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //work
    bfs();
    //output
    for(int i=1; i<=n; ++i)
        cout <<ans[i] <<"\n";
    return 0;
}

void bfs()
{
    //init
    ans[1] = 1;
    dis[1] = 0;
    queue<int> process;

    process.push(1);
    visit[1] = true;
    //work
    while(!process.empty())
    {
        int now = process.front();
        process.pop();

        for(int i=0; i<graph[now].size(); ++i)
        {
            int tail = graph[now][i];

            if(!visit[tail])
            {
                visit[tail] = true;
                dis[tail] = dis[now] + 1;
                ans[tail] = ans[now];
                process.push(tail);
            }
            else if(dis[tail] == dis[now]+1)
            {
                ans[tail] = (ans[tail] + ans[now]) % MOD;
            }
        }

    }
}
