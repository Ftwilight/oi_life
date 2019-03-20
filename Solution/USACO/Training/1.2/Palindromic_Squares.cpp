#include <cstdio>
#include <iostream>
const int MAX = 200;

int b;

void output(int n)
{
    if(n < 10)
        printf("%d", n);
    else
        putchar('A'+n-10);
}

void check(int n)
{
    // check
    int ori = n * n, len1 = 0, len2 = 0;
    int t1[MAX], t2[MAX];
    while(ori)
    {
        t2[len2++] = ori % b;
        ori /= b;
    }
    for(int i = 0; i <= len2 / 2; ++i)
        if(t2[i] != t2[len2-i-1])
            return;
    // transform
    ori = n;
    while(ori)
    {
        t1[len1++] = ori % b;
        ori /= b;
    }
    // print
    for(int i = len1-1; i >= 0; --i)
        output(t1[i]);
    putchar(' ');
    for(int i = len2-1; i >= 0; --i)
        output(t2[i]);
    printf("\n");
 
}

int main()
{
    // freopen("data.in", "r", stdin);
    scanf("%d", &b);
    for(int i = 1; i <= 300; ++i)
        check(i);
    return 0;
}
