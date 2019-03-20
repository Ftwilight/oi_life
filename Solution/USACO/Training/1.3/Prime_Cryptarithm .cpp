#include <cstdio>
#include <iostream>

bool isok[10];

bool GoodNum(int n)
{
    while(n)
    {
        if(!isok[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

bool GoodChoice(int i, int j)
{
    if(i * j >= 10000 || i * j < 1000 || i*(j/10) >= 1000 || i*(j%10) >= 1000)
        return false;
    if(!GoodNum(i) || !GoodNum(j))
        return false;
    if(!GoodNum(i * (j%10)) || !GoodNum(i * (j / 10)) || !GoodNum(i*j))
        return false;
    return true;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        isok[t] = true;
    }
    int ans = 0;
    for(int i = 111; i < 1000; ++i)
        for(int j = 11; j < 100; ++j)
            if(GoodChoice(i, j))
                ++ans;
    printf("%d", ans);
    return 0;
}
