#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 55;

struct Lamp
{
    int p, pos;
    Lamp():p(0), pos(0)
    {}
};

Lamp l[MAX];
int dp[MAX][MAX][2];
int sum[MAX];

int n, c;
inline int get_cost(int i, int j, int p, int aim);

int main()
{
    //file
    freopen("data.in", "r", stdin);
    //input
    scanf("%d %d", &n, &c);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &l[i].pos, &l[i].p);
        sum[i] = sum[i-1] + l[i].p;
    }
    //work
    for(int i = c+1; i <= n; ++i)
    {
        dp[c][i][1] = dp[c][i-1][1] + get_cost(c, i-1, i-1, i);
        dp[c][i][0] = dp[c][i][1] + get_cost(c, i, i, c);
    }
    for(int i = c-1; i > 0; --i)
    {
        dp[i][c][0] = dp[i+1][c][0] + get_cost(i+1, c, i+1, i);
        dp[i][c][1] = dp[i][c][0] + get_cost(i, c, i, c);
    }
    
    for(int i = c-1; i > 0; --i)
        for(int j = c+1; j <= n; ++j)
        {
            int v1 = dp[i+1][j][0] + get_cost(i+1, j, i+1, i);
            int v2 = dp[i+1][j][1] + get_cost(i+1, j, j, i);
            dp[i][j][0] = min(v1, v2);
            
            int v3 = dp[i][j-1][1] + get_cost(i, j-1, j-1, j);
            int v4 = dp[i][j-1][0] + get_cost(i, j-1, i, j);
            dp[i][j][1] = min(v3, v4);
        }
    //output
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
    //end
    return 0;
}

inline int get_cost(int i, int j, int p, int aim)
{
    return (sum[i-1]+sum[n]-sum[j]) * abs(l[p].pos - l[aim].pos);
}
