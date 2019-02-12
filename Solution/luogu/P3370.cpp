#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int MAX_N = 10001;
const int MAX_M = 1501;
const int BASE = 257;
const int MOD = 1e9 + 7;

int hash(char num[])
{
    int len = strlen(num);
    int res = 0;
    for(int i = 0; i < len; ++i)
        res = res*BASE + (int)num[i];
    return res;
}

int main()
{
    //freopen("data.in", "r", stdin);
    char num[MAX_M];
    int n, table[MAX_N];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", num);
        table[i] = hash(num);
    }
    std::sort(table, table + n);
    int ans = 1;
    for(int i = 1; i < n; ++i)
        if(table[i] != table[i-1])
            ++ans;
    printf("%d", ans);
    return 0;
}
