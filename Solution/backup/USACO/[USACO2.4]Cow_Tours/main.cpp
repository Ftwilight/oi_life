#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAX = 155;
const int INF = 0x7f7f7f7f;
int graph[MAX][MAX];
double dis[MAX][MAX], max_dis[MAX];
double x[MAX], y[MAX];

double getdis(int a, int b)
{
    return sqrt(pow(x[a] - x[b], 2)+pow(y[a] - y[b], 2));
}

int main()
{
    int n;
    //input
    cin >>n;
    for(int i=0; i<n; ++i)
        cin >>x[i] >>y[i];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            int t;
            scanf("%1d", &t);
            if(t)
                dis[i][j] = getdis(i, j);
            else if(i != j)
                dis[i][j] = INF;
        }
    //floyd
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    //work
    double ans1=0, ans2=INF;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(dis[i][j] != INF)
            {
                max_dis[i] = max(max_dis[i], dis[i][j]);
                ans1 = max(ans1, max_dis[i]);
            }

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(dis[i][j] == INF)
                ans2 = min(ans2, max_dis[i]+max_dis[j]+getdis(i, j));
    //output
    printf("%.6f", max(ans1, ans2));
    return 0;
}
