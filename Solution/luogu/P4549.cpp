#include <cstdio>

int gcd(int x, int y)
{
    return y? gcd(y, x%y): x;
}

int main()
{
    //freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int ans = 0, x;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        if(x < 0)
            x = -x;
        ans = gcd(ans, x);
    }
    printf("%d", ans);
    return 0;
}
