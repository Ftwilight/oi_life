#include <cstdio>

const int MAX = 15;
const int INF = 0x3f3f3f3f;

int n, book[MAX], ans;

bool dfs(int now[], int depth, int limit);
inline int pred(int b[]);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        ans = INF;
        for(int i = 1; i <= n; ++i)
            scanf("%d", book+i);
        //work
        for(int limit = 0; limit < 9; ++limit)
            if(dfs(book, 0, limit))
            {
                //output
                printf("Case %d: %d\n", ++cnt, limit);
                break;
            }
    }
    //end
    return 0;
}

bool dfs(int now[], int depth, int limit)
{
    if(3*depth + pred(now) > 3*limit)
        return false;
    else if(depth == limit && !pred(now))
        return true;
    
    int edit[MAX];
    for(int i = 1; i < n; ++i)
        for(int j = i; j <= n; ++j)
            for(int k = 0; k <= n; ++k)//i-j -> k_right
                if(k < i-1 || k > j)
                {
                    int cur = 0;
                    for(int t = 1; t <= k; ++t)
                        if(t < i || t > j)
                            edit[++cur] = now[t];
                    for(int t = i; t <= j; ++t)
                        edit[++cur] = now[t];
                    for(int t = k+1; t <= n; ++t)
                        if(t < i || t > j)
                            edit[++cur] = now[t];
                    if(dfs(edit, depth+1, limit))
                        return true;
                }
    return false;
}

inline int pred(int b[])
{
    int cnt = 0;
    for(int i = 2; i <= n; ++i)
        if(b[i] != b[i-1]+1)
            ++cnt;
    return cnt;
}
