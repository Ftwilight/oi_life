#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
//const
const int MAX = 30;
const int INF = 0x3f3f3f3f;

//global
int n;
int ans, ans_que[MAX];
int que[MAX];
bool g[MAX][MAX], isnode[MAX];
bool visited[MAX];
int ind[MAX];

//work function
void work();
void dfs(int cur, int all);
inline void init();
inline int id(char c);
inline void add_node(int num);

//io function
inline bool input(int &buf);
inline void clear();

//main
int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    char buf[1000];
    while(scanf("%s", buf) == 1 && buf[0]!='#')
    {
        init();
        int cur = 0;
        while(cur < strlen(buf))
        {
            int head = id(buf[cur++]);
            add_node(head);
            while(isalpha(buf[++cur]))
            {
                int now = id(buf[cur]);
                g[head][now] = g[now][head] = true;
                add_node(now);
            }
            ++cur;
        }
        //work & output
        work();
    }
    //end
    return 0;
}

//definition

void work()
{
    dfs(0, 0);
    for(int i = 0; i < n; ++i)
        printf("%c ", ans_que[i]+'A');
    printf("-> %d\n", ans);
}

void dfs(int cur, int all)
{
    if(cur >= n && ans>all)
    {
        ans = all;
        for(int i = 0; i < MAX; ++i)
            ans_que[i] = que[i];
    }
    for(int i = 0; i < MAX; ++i)
        if(isnode[i] && !visited[i])
        {
            que[cur] = i;
            ind[i] = cur;
            visited[i] = true;

            bool ok = true;
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                if(g[i][j])
                {
                    if(!visited[j])
                        ++cnt;
                    else if(ind[i]-ind[j] > ans)
                    {
                        ok = false;
                        break;
                    }
                }
            if(cnt >= ans)
                ok = false;

            if(ok)
            {
                for(int k=0; k<cur; ++k)
                    if(g[i][que[k]])
                        all = max(all, ind[i]-ind[que[k]]);
                dfs(cur+1, all);
            }

            visited[i] = false;
        }
}

inline int id(char c)
{
    return c-'A';
}

inline void init()
{
    ans = INF;
    n = 0;
    memset(isnode, 0, sizeof(isnode));
    memset(g, 0, sizeof(g));
    memset(que, 0, sizeof(que));
    memset(visited, 0, sizeof(visited));
    memset(ind, 0, sizeof(ind));
}

inline void add_node(int num)
{
    if(!isnode[num])
    {
        isnode[num] = true;
        ++n;
    }
}
