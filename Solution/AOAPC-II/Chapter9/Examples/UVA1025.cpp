#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_T = 210;
const int MAX_N = 55;

bool have_train[MAX_T][MAX_N][2];
int cost[MAX_N];
int f[MAX_T][MAX_N];//dp

void init(int t, int n);


int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input && pre
    int cnt = 0;
    int t, n;
    while(scanf("%d", &n) == 1 && n)
    {
        scanf("%d", &t);
        init(t, n);
        for(int i = 1; i < n; ++i)
            scanf("%d", cost+i);

        int m1, m2;
        //from the first
        scanf("%d", &m1);
        for(int i = 0; i < m1; ++i)
        {
            int begin;
            scanf("%d", &begin);
            for(int j = 0; j <= n && begin+cost[j] <= t; ++j)
            {
                begin += cost[j];
                have_train[begin][j+1][0] = true;
            }
        }
        //from the last
        scanf("%d", &m2);
        for(int i = 0; i < m2; ++i)
        {
            int begin;
            scanf("%d", &begin);
            for(int j = 0; j < n && begin+cost[n-j] <= t; ++j)
            {
                begin += cost[n-j];
                have_train[begin][n-j][1] = true;
            }
        }
        //work
        for(int i = t-1; i >= 0; --i)
            for(int j = 1; j <= n; ++j)
            {
                f[i][j] = f[i+1][j]+1;
                if(have_train[i][j][0] && j < n && i+cost[j] <= t)
                    f[i][j] = min(f[i][j], f[i+cost[j]][j+1]);
                if(have_train[i][j][1] && j > 1 && i+cost[j-1] <= t)
                    f[i][j] = min(f[i][j], f[i+cost[j-1]][j-1]);
            }
        //output
        printf("Case Number %d: ", ++cnt);
        if(f[0][1] >= INF)
            printf("impossible");
        else
            printf("%d", f[0][1]);
        printf("\n");
    }
    //end
    return 0;
} 

void init(int t, int n)
{
    cost[n] = 0;
    memset(have_train, 0, sizeof(have_train));
    for(int i = 0; i < n; ++i)
        f[t][i] = INF;
    f[t][n] = 0;
}
