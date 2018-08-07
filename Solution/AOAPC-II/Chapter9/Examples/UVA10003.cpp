#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1005;

int cut[MAX], dp[MAX][MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int l, n;
    while(cin >>l && l)
    {
        cin >>n;
        for(int i = 1; i <= n; ++i)
            cin >>cut[i];
        cut[n+1] = l;
        //work
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i >= 0; --i)
            for(int j = i+2; j <= n+1; ++j)
            {
                int v = INF;
                for(int k = i+1; k < j; ++k)
                    v = min(v, dp[i][k]+dp[k][j]+cut[j]-cut[i]);
                dp[i][j] = v;
            }
        //output
        cout <<"The minimum cutting is " <<dp[0][n+1] <<".\n";
    }
    //end
    return 0;
}
