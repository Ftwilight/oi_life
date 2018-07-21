#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int MAX = 1000000;
int que[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt;
    scanf("%d", &cnt);
    while(cnt--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", que+i);
        //work
        int l = 0, r = 0, ans = 0;
        set<int> dict;
        while(r < n)
        {
            while(r < n && !dict.count(que[r]))
                dict.insert(que[r++]);
            ans = max(ans, r-l);
            dict.erase(que[l++]);
        }
        //output
        printf("%d\n", ans);
    }
    //end
    return 0;
}
