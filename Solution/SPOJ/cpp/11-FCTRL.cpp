#include <cstdio>
#include <iostream>

int main()
{
    //freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        while(n)
        {
            n /= 5;
            ans += n;
        }
        printf("%d\n", ans);
    }
    return 0;
}
