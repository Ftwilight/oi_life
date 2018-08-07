#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 55;
const int LAST = 678;

int dp[MAX*180+LAST];
int w[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt;
    scanf("%d", &cnt);
    for(int c = 1; c <= cnt; ++c)
    {
        int n, t;
        scanf("%d %d", &n, &t);
        for(int i = 1; i <= n; ++i)
            scanf("%d", w+i);
        //work
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = t-1; j >= w[i]; --j)
                if(j == w[i] || dp[j-w[i]] > 0)
                {
                    dp[j] = max(dp[j], dp[j-w[i]]+1);
                    ans = max(ans, dp[j]);
                }
        //output
        int all = LAST;
        if(ans)
        {
            int end;
            for(end = t-1; dp[end] != ans; --end)
            ;
            all += end;
        }
        printf("Case %d: %d %d\n", c, ans+1, all);
    }
    //end
    return 0;
}
