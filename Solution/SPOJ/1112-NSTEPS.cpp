#include <cstdio>

int main()
{
    //freopen("data.in", "r", stdin);
    int t, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &x, &y);
        int ans = -1;
        if(x == y)
        {
            if(x & 1)
                ans = (x-1)*2+1;
            else
                ans = x * 2;
        }
        else if(x - y == 2 && x >= 2)
        {
            if(x & 1)
                ans = (x-2)*2+1;
            else
                ans = (x-1)*2;
        }
        if(ans == -1)
            printf("No Number\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
