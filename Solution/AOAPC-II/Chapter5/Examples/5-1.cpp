#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10005;

int num[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt = 0;
    int n, q;
    while(scanf("%d%d", &n, &q) && n != 0)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", num + i);
        //work
        sort(num, num + n);
        printf("CASE# %d:\n", ++cnt);
        for(int i = 0; i < q; ++i)
        {
            int oper;
            scanf("%d", &oper);
            int res = lower_bound(num, num + n, oper) - num;
            if(num[res] == oper)
                printf("%d found at %d\n", oper, res + 1);
            else
                printf("%d not found\n", oper);
        }
    }
    //end
    return 0;
}
