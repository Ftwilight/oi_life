#include <cstdio>
using namespace std;

const int MAX = 100005;

int right[MAX], left[MAX];

inline void init(int n);
inline void link(int l, int r);
void debug();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n, m;
    int cnt = 0;
    while(scanf("%d %d", &n, &m) == 2)
    {
        init(n);
        int op, x, y;
        bool rev = false;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", &op);
            if(op == 4)
                rev = !rev;
            //else if(op == 5)
            //   debug();
            else
            {
                scanf("%d %d", &x ,&y);
                if(rev && op != 3)
                    op = 3 - op;
                if(op == 1 && left[y] == x)
                    continue;
                else if(op == 2 && right[y] == x)
                    continue;

                int lx = left[x], rx = right[x];
                int ly = left[y], ry = right[y];
                if(op == 1)
                {
                    link(ly, x);
                    link(x, y);
                    link(lx, rx);
                }
                else if(op == 2)
                {
                    link(y, x);
                    link(x, ry);
                    link(lx, rx);
                }
                else if(op == 3)
                {
                    if(right[x] == y)
                    {
                        link(lx, y);
                        link(y, x);
                        link(x, ry);
                    }
                    else if(left[x] == y)
                    {
                        link(ly, x);
                        link(x, y);
                        link(y, rx);
                    }
                    else
                    {
                        link(lx, y);
                        link(y, rx);
                        link(ly, x);
                        link(x, ry);
                    }
                }
            }
        }
        //output
        int b = 0;
        long long ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            b = right[b];
            if(i % 2 == 1)
                ans += b;
        }
        if(rev && n % 2 == 0)
            ans = (long long)n*(n+1)/2 - ans;
        printf("Case %d: %lld\n", ++cnt, ans);
        //debug();
    }
    //end
    return 0;
}

inline void init(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        right[i] = i + 1;
        left[i] = i - 1;
    }
    right[n] = 0;
    left[0] = n;
    right[0] = 1;
}

inline void link(int l, int r)
{
    right[l] = r;
    left[r] = l;
}

void debug()
{
    int b = 0;
    while(b = right[b])
        printf("%d ", b);
    printf("\n");
}
