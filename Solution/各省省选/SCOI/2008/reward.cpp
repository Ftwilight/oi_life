#include <cstdio>
#include <iostream>

const int MAXK = 105;
const int MAXN = 15;

double f[MAXK][1 << MAXN];
int val[MAXN];
int own[MAXN];

inline char getc()
{
    static char buf[1<<18], *fs, *fe;
    return (fs == fe && (fe = (fs=buf)+fread(buf, 1, 1<<18, stdin)), fs == fe)? EOF: *fs++;
}

inline int readin()
{
    int x = 0, flag = 1;
    char c = getc();
    for( ; c < '0' || c > '9'; c = getc())
        if(c == '-')
            flag = -1;
    for( ; c >= '0' && c <= '9'; c = getc())
        x = x*10+c-'0';
    return x*flag;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n, k;
    k = readin();
    n = readin();
    for(int i = 1; i <= n; ++i)
    {
        val[i] = readin();
        for(int j = readin(); j; j = readin())
            own[i] = own[i] | (1 << (j - 1));
    }
    for(int i = k; i >= 1; --i)
    {
        for(int s = 0; s < (1 << n); ++s)
        {
            for(int me = 1; me <= n; ++me)
                if((s & own[me]) == own[me])
                    f[i][s] += std::max(f[i+1][(s | (1 << (me-1)))] + val[me], f[i+1][s]);
                else
                    f[i][s] += f[i+1][s];
            f[i][s] /= n;
        }
    }
    printf("%.6lf", f[1][0]);
    return 0;
}
