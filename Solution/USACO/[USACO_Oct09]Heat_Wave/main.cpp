#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 2510;

int graph[MAX][MAX];
int dist[MAX];
bool visit[MAX];
int t, c, ts, te;

int spfa();

int main()
{
    //file
    freopen("heatwvx.in", "r", stdin);
    freopen("heatwvx.out", "w", stdout);
    //input
    cin >>t >>c >>ts >>te;
    for(int i = 0; i < c; ++i)
    {
        int rs, re, ci;
        cin >>rs >>re >>ci;
        graph[rs][re] = ci;
        graph[re][rs] = ci;
    }
    //work
    int ans = spfa();
    //output
    cout <<ans;
    return 0;
}

int spfa()
{
    int ans = INF;
    //init
    queue<int> work;
    memset(dist, 0x7f, sizeof(dist));
    dist[ts] = 0;
    work.push(ts);
    visit[ts] = true;
    //work
    while(!work.empty())
    {
        int now = work.front();
        work.pop();
        for(int i = 1; i <= t; ++i)
            if(graph[now][i] && dist[i] > dist[now] + graph[now][i])
            {
                dist[i] = dist[now] + graph[now][i];
                if(!visit[i])
                {
                    work.push(i);
                    visit[i] = true;
                }
            }
        visit[now] = false;
    }
    //ruturn
    return dist[te];
}
