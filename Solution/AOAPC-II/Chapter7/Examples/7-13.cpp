#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 30;

int que[MAX];

bool dfs(int depth, int aim, int limit);
bool is_inside(int num, int top);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    que[0] = 1;
    int aim;
    while(cin >>aim && aim)
    {
        //work
        for(int lim=0; lim<MAX; ++lim)
            if(dfs(0, aim, lim))
            {
                //output
                printf("%d\n", lim);
                break;
            }
    } 
    //end
    return 0;
}

bool dfs(int depth, int aim, int limit)
{
    if(que[depth] == aim)
        return true;
    if(depth == limit)
        return false;
    int large = 0;
    for(int i = 0; i <= depth; ++i)
        large = max(large, que[i]);
    if((large << (limit-depth)) < aim)
        return false;
        
    for(int i = depth; i >= 0; --i)
    {
        que[depth+1] = que[depth]+que[i];
        if(dfs(depth+1, aim, limit))
            return true;
        que[depth+1] = que[depth]-que[i];
        if(dfs(depth+1, aim, limit))
            return true;
    } 
    return false;
}
