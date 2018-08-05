#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 5050;

char p[MAX], q[MAX];
int lp, lq;
int dp[MAX][MAX], w[MAX][MAX];
int sp[26], sq[26], ep[26], eq[26];

void input();
void work();
void init();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt;
    scanf("%d", &cnt);
    while(cnt--)
    {
        input();
        //work
        init();
        work();
        //output
        printf("%d\n", dp[lp][lq]);
    }
    //end
    return 0;
}

void work()
{
    for(int i = 0; i <= lp; ++i)
        for(int j = 0; j <= lq; ++j)
        {
            if(!i && !j)
                continue;
            int v1 = INF, v2 = INF;
            if(i)
                v1 = dp[i-1][j] + w[i-1][j];
            if(j)
                v2 = dp[i][j-1] + w[i][j-1];
            dp[i][j] = min(v1, v2);
            
            if(i)
            {
                w[i][j] = w[i-1][j];
                if(sp[p[i]] == i && sq[p[i]] > j)
                    ++w[i][j];
                if(ep[p[i]] == i && eq[p[i]] <= j)
                    --w[i][j];
            }
            else if(j)
            {
                w[i][j] = w[i][j-1];
                if(sq[q[j]] == j && sp[q[j]] > i)
                    ++w[i][j];
                if(eq[q[j]] == j && ep[q[j]] <= i)
                    --w[i][j];
            }
        }
}

void input()
{
    scanf("%s %s", p+1, q+1);
    lp = strlen(p+1);
    lq = strlen(q+1);
    
    for(int i = 1; i <= lp; ++i)
        p[i] -= 'A';

    for(int i = 1; i <= lq; ++i)
        q[i] -= 'A';
}

void init()
{
    //memset(dp, 0, sizeof(dp));
    //memset(w, 0, sizeof(w));
    for(int i = 0; i < 26; ++i)
    {
        sq[i] = sp[i] = INF;
        eq[i] = ep[i] = 0;
    }
    for(int i = 1; i <= lp; ++i)
    {
        sp[p[i]] = min(sp[p[i]], i);
        ep[p[i]] = i;
    }
    for(int i = 1; i <= lq; ++i)
    {
        sq[q[i]] = min(sq[q[i]], i);
        eq[q[i]] = i;
    }
}
