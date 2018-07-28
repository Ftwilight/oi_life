#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX = 1050;
const int INF = 0x3f3f3f3f;

double dp[MAX][MAX];
int p[MAX][2];

inline void init();
inline double dist(int a, int b);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d %d", &p[i][0], &p[i][1]);
        //work
        init();
        for(int i = 3; i <= n; ++i)
        {
            dp[i][i-1] = INF;
            for(int j = 1; j < i-1; ++j)
            {
                dp[i][i-1] = std::min(dp[i][i-1], dp[i-1][j] + dist(i, j));
                dp[i][j] = dp[i-1][j] + dist(i-1, i);
            }
        }
        double ans = INF;
        for(int i = 1; i < n; ++i)
            ans = std::min(ans, dp[n][i] + dist(i, n));
        //output
        printf("%.2f\n", ans);
    }
    //end
    return 0;
}

inline double dist(int a, int b)
{
    return sqrt(pow(p[a][0]-p[b][0], 2) + pow(p[a][1]-p[b][1], 2));
}

inline void init()
{
    memset(dp, 0, sizeof(dp));
    dp[2][1] = dist(2, 1);
}
