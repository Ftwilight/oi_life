#include <iostream>
#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;

const int MAX = 100;
const int MAX_E = 1000000;

int find_origin();
void hierholzer(int now);
inline int id(char a);

bool g[MAX][MAX];
int in_degree[MAX], cnt;
char ans[MAX_E];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    char buf[3];
    cin >>n;
    for(int i = 0; i < n; ++i)
    {
        cin >>buf;
        int a = id(buf[0]), b = id(buf[1]);
        g[a][b] = g[b][a] = true;
        ++in_degree[a];
        ++in_degree[b];
    }
    //work && output
    int ori = find_origin();
    if(ori != -1)
    {
        hierholzer(ori);
        for(int i = cnt-1; i >= 0; --i)
            cout <<ans[i];
    }
    else
        cout <<"No Solution\n";
    //end
    return 0;
}

inline int id(char a)
{
    return a-26;
}

int find_origin()
{
    int p = 0;
    for(int i = 0; i < MAX; ++i)
        if(in_degree[i] && in_degree[i] % 2)
            ++p;
    if(!p)
    {
        int cnt = 0;
        while(!in_degree[cnt])
            ++cnt;
        return cnt;
    }
    else if(p == 2)
    {
        int cnt = 0;
        while(!in_degree[cnt] || !(in_degree[cnt] % 2))
            ++cnt;
        return cnt;
    }
    else
        return -1;
}

void hierholzer(int now)
{
    for(int i = 0; i < MAX; ++i)
        if(g[now][i])
        {
            g[now][i] = false;
            g[i][now] = false;
            hierholzer(i);
        }
    ans[cnt++] = now+26;
}
