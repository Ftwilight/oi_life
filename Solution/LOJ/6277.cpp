#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAX = 5e4 + 5;

class Read
{
private:
    char getc()
    {
        static char buf[1<<18], *fs, *fe;
        return (fs == fe && (fe = (fs = buf)+fread(buf, 1, 1<<18, stdin)), fs == fe)? EOF: *fs++;
    }
public:
    int operator()()
    {
        int x = 0, flag = 1;
        char c;
        for(c = getc(); c < '0' || c > '9'; c = getc())
            if(c == '-')
                flag = -1;
        for( ; c >= '0' && c <= '9'; c = getc())
            x = x * 10 + c - '0';
        return x * flag;
    }
}readin;

int a[MAX], mark[MAX];
int bsize, n;

inline int belong(int x)
{
    return x / bsize;
}

void modify(int l, int r, int k)
{
    int lb = belong(l), rb = belong(r);
    if(lb == rb)
    {
        for(int i = l; i <= r; ++i)
            a[i] += k;
        return ;
    }
    for(int i = lb + 1; i < rb; ++i)
        mark[i] += k;
    for(int i = l; i < (lb+1)*bsize; ++i)
        a[i] += k;
    for(int i = rb*bsize; i <= r; ++i)
        a[i] += k;
}

int main()
{
    // freopen("data.in", "r", stdin);
    n = readin();
    bsize = sqrt(n);
    for(int i = 0; i < n; ++i)
        a[i] = readin();
    for(int i = 0; i < n; ++i)
    {
        int op=readin(), l=readin(), r=readin(), c=readin();
        --l;
        --r;
        switch(op)
        {
            case 0:
                modify(l, r, c);
                break;
            case 1:
                printf("%d\n", a[r] + mark[belong(r)]);
                break;
        }
    }
    return 0;
}
