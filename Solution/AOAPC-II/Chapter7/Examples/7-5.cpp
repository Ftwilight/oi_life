#include <cstdio>
#include <cstring>

const int MAX = 100;

int cnt, n, l;
int str[MAX];

bool dfs(int now);
void init();
void output(int num);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(scanf("%d %d", &n, &l) == 2 && n && l)
    {
        //work
        init();
        dfs(0);
    }
    //end
    return 0;
}

bool dfs(int now)
{
    if(cnt++ == n)
    {
        output(now);
        return true;
    }
    for(int i = 0; i < l; ++i)
    {
        bool ok = true;
        str[now] = i;
        for(int j = 1; j*2 <= now+1; ++j)
        {
            bool equal = true;
            for(int k = 0; k < j; ++k)
                if(str[now-k] != str[now-j-k])
                {
                    equal = false;
                    break;
                }
            if(equal)
            {
                ok = false;
                break;
            }
        }
        if(ok && dfs(now+1))
            return true;
    }
    return false;
}

void init()
{
    memset(str, 0, sizeof(str));
    cnt = 0;
}

void output(int num)
{
    for(int i = 0; i < num; ++i)
    {
        if(i && !(i%64))
            printf("\n");
        else if(i && !(i%4))
            printf(" ");
        printf("%c", 'A'+str[i]);
    }
    printf("\n%d\n", num);
}















