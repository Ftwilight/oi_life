#include <cstdio>
#include <iostream>

const int MAX = 50;

bool is_ok(int n, int b)
{
    int trans[MAX];
    int len = 0;
    while(n)
    {
        trans[len++] = n % b;
        n /= b;
    }
    for(int i = 0; i <= len/2; ++i)
        if(trans[i] != trans[len-i-1])
            return false;
    return true;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n, s;
    scanf("%d %d", &n, &s);
    int cnt = 0;
    while(cnt < n)
    {
        ++s;
        int t = 0;
        for(int i = 2; i <= 10; ++i)
            if(is_ok(s, i))
            {
                ++t;
                if(t > 2)
                    break;
            }
        if(t >= 2)
        {
            printf("%d\n", s);
            ++cnt;
        }
    }
    return 0;
}
