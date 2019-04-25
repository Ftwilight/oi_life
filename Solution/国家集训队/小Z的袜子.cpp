#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAX = 5e4 + 5;

class Read
{
private:
    char getc()
    {
        static char buf[1<<18], *fs, *fe;
        return (fs == fe && (fe = (fs = buf) + fread(buf, 1, 1<<18, stdin)), fs == fe)? EOF: *fs++;
    }
public:
    LL operator()()
    {
        LL x = 0;
        char c = getc();
        for( ; c < '0' || c > '9'; c = getc())
            ;
        for( ; c >= '0' && c <= '9'; c = getc())
            x = x * 10 + c - '0';
        return x;
    }
}readin;

LL data[MAX], colsum[MAX];
LL ans[MAX][2];// ans[k][0] / ans[k][1]
int sq;

struct Quest
{
    int l, r, i;
    bool operator<(const Quest &x) const
    {
        if((l-1)/sq+1 == (x.l-1)/sq+1)
            return r < x.r;
        return l < x.l;
    }
}que[MAX];

LL gcd(LL a, LL b)
{
    return b? gcd(b, a%b): a;
}

int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int n, m;
    n = readin();
    m = readin();
    sq = sqrt(n);
    for(int i = 1; i <= n; ++i)
        data[i] = readin();
    for(int i = 0; i < m; ++i)
    {
        que[i].i = i;
        que[i].l = readin();
        que[i].r = readin();
    }
    sort(que, que+m);

    int l, r;
    LL sub = 0;

    l = r = que[0].l;
    ++colsum[data[l]];
    for(int i = 0; i < m; ++i)
    {
        while(l < que[i].l)
        {
            // sub = sub - Cx2(colsum[data[l]]) + Cx2(colsum[data[l]] - 1);
            sub = sub - (colsum[data[l]] - 1);
            --colsum[data[l]];
            ++l;
        }
        while(l > que[i].l)
        {
            --l;
            ++colsum[data[l]];
            // sub = sub - Cx2(colsum[data[l]] - 1) + Cx2(colsum[data[l]]);
            sub = sub + (colsum[data[l]] - 1);
        }
        while(r > que[i].r)
        {
            // sub = sub - Cx2(colsum[data[r]]) + Cx2(colsum[data[r]] - 1);
            sub = sub - (colsum[data[r]] - 1);
            --colsum[data[r]];
            --r;
        }
        while(r < que[i].r)
        {
            ++r;
            ++colsum[data[r]];
            // sub = sub - Cx2(colsum[data[r]] - 1) + Cx2(colsum[data[r]]);
            sub = sub + (colsum[data[r]] - 1);
        }
        int index = que[i].i;
        if(!sub)
        {
            ans[index][0] = 0;
            ans[index][1] = 1;
        }
        else
        {
            LL ans_sub = sub;
            // LL ans_mot = (que[i].r - que[i].l + 1) * (que[i].r - que[i].l) >> 1;
            LL ans_mot = (LL)(que[i].r - que[i].l + 1) * (que[i].r - que[i].l) >> 1;
            LL g = gcd(ans_sub, ans_mot);
            ans[index][0] = ans_sub / g;
            ans[index][1] = ans_mot / g;
        }
    }
    for(int i = 0; i < m; ++i)
        printf("%lld/%lld\n", ans[i][0], ans[i][1]);
    return 0;
}
