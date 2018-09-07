#include <cstdio>
#include <iostream>

const int MAX = 8;

int num[MAX];
int n, k, ans;

void dfs(int cnt);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%d %d", &n, &k);
    //work
    num[0] = 1;
    dfs(1);
    //output
    printf("%d", ans);
    //end
    return 0;
}

void dfs(int cnt)
{
    if(n == 0)
        return;
    else if(cnt == k)
    {
        if(n >= num[cnt-1])
            ++ans;
        return;
    }
    else
    {
        for(int i = num[cnt-1]; i <= n/(k-cnt+1); ++i)
        {
            num[cnt] = i;
            n -= i;
            dfs(cnt + 1);
            n += i;
        }
    }
}
