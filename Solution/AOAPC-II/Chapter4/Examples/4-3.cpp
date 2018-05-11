#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 25;

int que[MAX], n;

int walk(int s, int steps, int dire);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int k, m;
    while(scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        for(int i = 1; i <= n; ++i)
            que[i] = i;
        //work
        int a_now = n, b_now = 1;
        int left = n;
        while(left)
        {
            a_now = walk(a_now, k, 1);
            b_now = walk(b_now, m, -1);
            --left;
            printf("%3d", a_now);
            if(a_now != b_now)
            {
                --left;
                printf("%3d", b_now);
            }
            que[a_now] = que[b_now] = 0;
            if(left)
                printf(",");
        }
        printf("\n");
    }
    //end
    return 0;
}

int walk(int s, int steps, int dire)
{
    while(steps--)
    {
        do
        {
            s = (s + dire + n - 1) % n + 1;
        }
        while(!que[s]);
    }
    return s;
}
