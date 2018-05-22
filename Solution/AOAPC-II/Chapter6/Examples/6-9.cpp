#include <iostream>
#include <cstdio>
using namespace std;

bool solve(int &w);

int main()
{
    //freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int w;
        if(solve(w))
            printf("YES\n");
        else
            printf("NO\n");
        if(n)
            printf("\n");
    }
    return 0;
}

bool solve(int &w)
{
    int lw, ld, rw, rd;
    scanf("%d %d %d %d", &lw, &ld, &rw, &rd);
    bool fl = true, fr = true;
    if(!lw)
        fl = solve(lw);
    if(!rw)
        fr = solve(rw);
    w = lw + rw;
    return fl && fr && (lw * ld == rw * rd);
}
