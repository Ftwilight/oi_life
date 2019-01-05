#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 205;

struct Rubbish
{
    int t, h, f;
    Rubbish():t(0), h(0), f(0)
    {} 
    bool operator<(const Rubbish &other) const
    {
        return t < other.t;
    }
};

Rubbish r[MAX];
int dp[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int d, g;
    scanf("%d %d", &d, &g);
    for(int i = 1; i <= g; ++i)
        scanf("%d %d %d", &r[i].t, &r[i].f, &r[i].h);
    //work
    sort(r+1, r+g+1);
    dp[0] = 10;
    for(int i = 1; i <= g; ++i)
        for(int j = d; j >= 0; --j)
            if(dp[j] >= r[i].t)
            {
                if(j + r[i].h >= d)
                {
                    printf("%d\n", r[i].t);
                    return 0;
                }
                dp[j+r[i].h] = max(dp[j+r[i].h], dp[j]);
                dp[j] += r[i].f;
            }
    //output
    printf("%d\n", dp[0]);
    //end
    return 0;
}
