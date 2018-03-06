#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 2147483647;
const int MAX_E = 500005;
const int MAX_V = 10005;

struct Edge
{
    int index;
    int len;
};
vector<Edge> graph[MAX_V];
bool inside[MAX_V];

vector<int> spfa(int begin);
int n, m, s;

int main()
{
    //input
    cin >>n >>m >>s;
    for(int i=0; i<m; ++i)
    {
        int head, tail, len;
        cin >>head >>tail >>len;
        Edge temp;
        temp.index = tail;
        temp.len = len;
        graph[head].push_back(temp);
    }
    //work
    vector<int> result = spfa(s);
    //output
    for(int i=1; i<=n; ++i)
        cout <<result[i] <<" ";
    return 0;
}

vector<int> spfa(int begin)
{
    //init
    queue<int> process;
    vector<int> dist(n+5, INF);

    dist[begin] = 0;
    process.push(begin);
    inside[begin] = true;
    //work
    while(!process.empty())
    {
        int now = process.front();
        process.pop();
        inside[now] = false;
        for(int i=0; i<graph[now].size(); ++i)
        {
            Edge aim = graph[now][i];
            if(dist[aim.index] > dist[now]+aim.len)
            {
                if(!inside[aim.index])
                    process.push(aim.index);
                dist[aim.index] = dist[now]+aim.len;
            }
        }
    }

    //return
    return dist;
}
