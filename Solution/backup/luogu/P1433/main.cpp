#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 16;
const int INF = 0x3f3f3f3f;

int n;
bool visited[MAX];
double ans=INF, dist[MAX][MAX], x[MAX], y[MAX];

void dfs(int u, double d, int cnt);
inline double get_dis(int a, int b);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%d", &n);
    for(int i = 1 ; i <= n; ++i)
        scanf("%lf %lf", x+i, y+i);
    //work
    dfs(0, 0, 0);
    //output
    printf("%.2lf", ans);
    //end
    return 0;
}

void dfs(int u, double d, int cnt)
{
    if(d > ans)
        return;	
    if(cnt == n)
    {
        ans = min(ans, d);
        return;
    }
    visited[u] = true;
    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            dfs(i, d+get_dis(u, i), cnt+1);
    visited[u] = false;
    
}

inline double get_dis(int a, int b)
{
    if(dist[a][b])
        return dist[a][b];
    else
        return dist[a][b] = dist[b][a] = sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}
