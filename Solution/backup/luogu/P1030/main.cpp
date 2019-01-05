#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 10;

void build(int i_l, int i_r, int p_l, int p_r);

char in_order[MAX], post_order[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    scanf("%s\n%s", in_order, post_order);
    //work
    build(0, strlen(in_order)-1, 0, strlen(post_order)-1);
    //end
    return 0;
}

void build(int i_l, int i_r, int p_l, int p_r)
{
    if(i_l > i_r)
        return;
    char &root = post_order[p_r];
    printf("%c", root);
    int cur = i_l;
    while(in_order[cur] != root)
        ++cur;
    int left_num = cur-i_l;
    build(i_l, cur-1, p_l, p_l+left_num-1);
    build(cur+1, i_r, p_l+left_num, p_r-1);
}
