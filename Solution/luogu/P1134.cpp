#include <cstdio>
#include <iostream>

int cnt2;

int extract(int x)
{
    while(!(x % 2))
    {
        x /= 2;
        ++cnt2;
    }
    while(!(x % 5))
    {
        x /= 5;
        --cnt2;
    }
    return x;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int last = 1;
    for(int i = 1; i <= n; ++i)
        (last *= extract(i)) %= 10;
    for(int i = 0; i < cnt2; ++i)
        (last *= 2) %= 10;
    printf("%d", last);
    return 0;
}
