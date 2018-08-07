#include <iostream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 10010;

int inorder[MAX], postorder[MAX];
int lc[MAX], rc[MAX];
int ans, all;
int n;

bool input(int *aim);
int build(int i_l, int i_r, int p_l, int p_r);
void dfs(int now, int sum);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(input(inorder))
    {
        input(postorder);
        all = INF;
        ans = INF;
        //work
        build(0, n - 1, 0, n - 1);
        dfs(postorder[n - 1], 0);
        //output
        cout <<ans <<"\n";
    }
    //end
    return 0;
}

bool input(int *aim)
{
    n = 0;
    string buf;
    if(!getline(cin, buf))
        return false;
    stringstream s(buf);
    int v;
    while(s >> v)
        aim[n++] = v;
    return true;
}

int build(int i_l, int i_r, int p_l, int p_r)
{
    if(i_l > i_r)
        return 0;
    int root = postorder[p_r];
    int left_num = 0;
    int point = i_l;
    while(inorder[point] != root)
        ++point;
    left_num = point - i_l;
    lc[root] = build(i_l, point-1, p_l, p_l+left_num-1);
    rc[root] = build(point+1, i_r, p_l+left_num, p_r-1);
    return root;
}

void dfs(int now, int sum)
{
    sum += now;
    if(!lc[now] && !rc[now])
        if((sum < all) || (sum == all && now < ans))
        {
            ans = now;
            all = sum;
        }
    if(lc[now])
        dfs(lc[now], sum);
    if(rc[now])
        dfs(rc[now], sum);
}
