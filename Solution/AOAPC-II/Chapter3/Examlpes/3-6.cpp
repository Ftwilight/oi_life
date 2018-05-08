#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 105;
char seq[MAX];
int len;

bool less_(int a, int b);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //work
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", seq);
        len = strlen(seq);
        int ans = 0;
        for(int j = 0; j < len; ++j)
            if(less_(j, ans))
                ans = j;
        for(int j = 0; j < len; ++j)
            putchar(seq[(ans + j) % len]);
        putchar('\n');
    }

    return 0;
}

bool less_(int a, int b)
{
    for(int i = 0; i < len; ++i)
        if(seq[(a + i) % len]!= seq[(b + i) % len])
            return seq[(a+i)%len] < seq[(b+i)%len];
    return false;
}
