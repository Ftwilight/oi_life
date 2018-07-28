#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 105;

int mat[MAX][MAX];
int dp[MAX][MAX], Next[MAX][MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    int m, n;
    while(scanf("%d %d", &m, &n) == 2)
    {
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &mat[i][j]);
        //work
        int ans = INF, first;
        for(int j = n; j > 0; --j)
            for(int i = 1; i <= m; ++i)
            {
                if(j == n)
                    dp[i][j] = mat[i][j];
                else
                {
                    int row[3] = {i-1, i, i+1};
                    if(row[0] == 0)
                        row[0] = m;
                    if(row[2] > m)
                        row[2] = 1;
                    sort(row, row+3);
                
                    dp[i][j] = INF;
                    for(int k = 0; k < 3; ++k)
                    {
                        int t = mat[i][j] + dp[row[k]][j+1];
                        if(t < dp[i][j])
                        {
                            dp[i][j] = t;
                            Next[i][j] = row[k];
                        }
                    }
                }
                
                if(j == 1 && dp[i][j] < ans)
                {
                    ans = dp[i][j];
                    first = i;
                }
            }
        //find_ans && output
        printf("%d", first);
        int i = Next[first][1];
        for(int j = 1; j < n; ++j, i = Next[i][j])
            printf(" %d", i);
        printf("\n%d\n", ans);
    }
    //end
    return 0;
}
