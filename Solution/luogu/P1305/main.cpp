#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 100;

int lc[MAX], rc[MAX], fa[MAX];

void in_order(int now);
inline int id(char c);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    char buf[4];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", buf);
        lc[id(buf[0])] = id(buf[1]);
        rc[id(buf[0])] = id(buf[2]);
        fa[id(buf[1])] = fa[id(buf[2])] = id(buf[0]);
    }
    //work && output
    int root = 1;
    while(!(fa[root] == 0 && (lc[root] || rc[root])))
        ++root;
    in_order(root);
    //end
    return 0;
}

inline int id(char c)
{
    if(c == '*')
        return 0;
    else
        return c-'a'+1;
}

void in_order(int now)
{
    printf("%c", now+'a'-1);
    if(lc[now])
        in_order(lc[now]);
    if(rc[now])
        in_order(rc[now]);
}
