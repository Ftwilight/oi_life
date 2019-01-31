#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

const int MAX_N = 10005;
const int MAX_S = 15;

typedef priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

vector<int> hook;

vector<pair<int, int> > graph[MAX_N];
int dist[MAX_N];

int dijkstra(int begin, int end)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[begin] = 0;
    heap h;
    h.push(make_pair(begin, 0));
    while(!h.empty())
    {
        int now = h.top().first;
        int d = h.top().second;
        h.pop();
        if(d != dist[now])
            continue;
        for(unsigned i = 0; i < graph[now].size(); ++i)
        {
            int to = graph[now][i].first;
            int w = graph[now][i].second;
            if(dist[to] > dist[now] + w)
            {
                dist[to] = dist[now] + w;
                h.push(make_pair(to, dist[to]));
            }
        }
    }
    return dist[end];
}

void solve()
{
    map<string, int> id;
    int n;
    //input
    cin >>n;
    for(int i = 1; i <= n; ++i)
    {
        string name;
        int t;
        cin >>name >>t;
        id.insert(make_pair(name, i));
        for(int j = 0; j < t; ++j)
        {
            int nr, cost;
            cin >>nr >>cost;
            graph[i].push_back(make_pair(nr, cost));
        }
    }
    //work
    int r;
    cin >>r;
    for(int i = 0; i < r; ++i)
    {
        string n1, n2;
        cin >>n1 >>n2;
        cout <<dijkstra(id[n1], id[n2]) <<"\n";
    }
    //clear
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
}

int main()
{
    //freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    int s;
    cin >>s;
    while(s--)
        solve();
    return 0;
}
