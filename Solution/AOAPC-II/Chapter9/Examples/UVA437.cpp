#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 35;

struct Sty//storey
{
    int max_e, min_e, h;
    Sty(int a, int b, int c):max_e(a), min_e(b), h(c)
    {}
};

int n;
int cub[MAX][3];
int record[MAX][3];

int solve(int rank, int mask);
inline Sty get_sty(int rank, int mask);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 3; ++j)
                scanf("%d", &cub[i][j]);
        //work
        memset(record, 0, sizeof(record));
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int m = 0; m < 3; ++m)
                ans = max(ans, solve(i, m));
        //output
        printf("Case %d: maximum height = %d\n", ++cnt, ans);
    }
    //end
    return 0;
}

int solve(int rank, int mask)
{
    Sty now = get_sty(rank, mask);
    int &ans = record[rank][mask];
    if(ans)
        return ans;
    ans = now.h;
    for(int i = 0; i < n; ++i)
        for(int m = 0; m < 3; ++m)
        {
            Sty t = get_sty(i, m);
            if(t.max_e < now.max_e && t.min_e < now.min_e)
                ans = max(ans, solve(i, m)+now.h);
        }
    return ans;
}

inline Sty get_sty(int rank, int mask)
{
    int ta = cub[rank][(mask-1<0)? 2: mask-1];
    int tb = cub[rank][(mask+1>2)? 0: mask+1];
    int max_e = max(ta, tb);
    int min_e = min(ta, tb);
    return Sty(max_e, min_e, cub[rank][mask]);
}
