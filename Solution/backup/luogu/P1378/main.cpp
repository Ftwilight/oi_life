#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 7;
const double PI = 3.1415926;
const int INF = 0x3f3f3f3f;

int n;
double ans;
double limx[2], limy[2];
double x[MAX], y[MAX];
double r[MAX], sqare;
bool visit[MAX];

void dfs(int cnt, double s);
inline double base_dist(int i);
inline double dist(int a, int b);
inline double circle(int t);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    cin >>n;
    cin >>limx[0] >>limy[0] >>limx[1] >>limy[1];
    sqare = double(abs((limx[0]-limx[1]) * (limy[0]-limy[1])));
    for(int i = 0; i < n; ++i)
        cin >>x[i] >>y[i];
    //work
    dfs(0, 0);
    //output
    cout <<int(sqare-ans+0.5);
}

void dfs(int cnt, double s)
{
    if(cnt == n)
    {
        ans = max(ans, s);
        return;
    }
    for(int i = 0; i < n; ++i)
        if(!visit[i])
        {
            double len = base_dist(i);
            for(int j = 0; j < n; ++j)
                if(visit[j] && r[j])
                    len = min(len, dist(i, j)-r[j]);
            if(len < 0)
                len = 0;
            
            visit[i] = true;
            r[i] = len;
            dfs(cnt+1, s+circle(i));
            
            visit[i] = false;
        }
}

inline double base_dist(int i)
{
    double res = 0;
    res = min(abs(x[i]-limx[0]), abs(x[i]-limx[1]));
    double t = min(abs(y[i]-limy[0]), abs(y[i]-limy[1]));
    
    res = min(res, t);
    return double(res);
}

inline double dist(int a, int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

inline double circle(int t)
{
    return PI * r[t] * r[t];
}
