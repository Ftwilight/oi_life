#include <cstdio>
#include <cmath>
#include <cstring>

const int MAX = 50;

int is_prime[100];
int que[MAX]; 
bool visit[MAX];

bool judge(int num);
void dfs(int now, int n);
void debug()
{
    printf("[");
    for(int i = 0; i < 10; ++i)
        printf("%d ", que[i]);
    printf("]\n");
    printf("{");
    for(int i = 1; i <= 10; ++i)
        printf("%d:%d ", i, (visit[i]?1:0));
    printf("}\n");
}

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //init
    is_prime[2] = 1;
    is_prime[3] = 1;
    //input
    int n, cnt = 0;
    while(scanf("%d", &n) == 1)
    {
        if(cnt)
            printf("\n");
        //work & output
        memset(que, 0, sizeof(que));
        memset(visit, 0, sizeof(visit));

        que[0] = 1;
        visit[1] = true;

        printf("Case %d:\n", ++cnt);
        dfs(1, n);
    }
    //end
    return 0;
}

void dfs(int now, int n)
{
    //debug();
    if(now == n && judge(que[0]+que[now-1]))
    {
        printf("%d", que[0]);
        for(int i = 1; i < n; ++i)
            printf(" %d", que[i]);
        printf("\n");
    }
    else
    {
        for(int i = 2; i <= n; ++i)
            if(!visit[i] && judge(que[now-1]+i))
            {
                visit[i] = true;
                que[now] = i;
                dfs(now+1, n);
                visit[i] = false;
            }
    }
}

bool judge(int num)
{
    if(is_prime[num] == 0)
    {
        is_prime[num] = 1;
        for(int i = 2; i < num; ++i)
            if(!(num % i))
            {
                is_prime[num] = -1;
                break;
            }
    }
    return is_prime[num] == 1;
}
