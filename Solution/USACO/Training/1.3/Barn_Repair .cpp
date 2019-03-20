#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAX = 205;

int dif[MAX], data[MAX];

int main()
{
    // freopen("data.in", "r", stdin);
    int m, s, c;
    scanf("%d %d %d", &m, &s, &c);
    for(int i = 0; i < c; ++i)
        scanf("%d", data+i);
    std::sort(data, data+c);
    for(int i = 1; i < c; ++i)
        dif[i] = data[i] - data[i-1] - 1;
    std::sort(dif+1, dif+c);
    int num = c, ans = c;
    for(int i = 1; i < c; ++i)
    {
        if(num > m)
        {
            --num;
            ans += dif[i];
        }
        else
            break;
    }
    printf("%d", ans);
    return 0;
}
