#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 100005;

vector<int> sons[MAX];
int n, t;

int dp(int now);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(cin >>n >>t && n && t)
    {
        for(int i = 0; i <= n; ++i)
            sons[i].clear();
        int temp;
        for(int i = 1; i <= n; ++i)
        {
            cin >>temp;
            sons[temp].push_back(i);
        }
        //work && output
        cout <<dp(0) <<"\n";
    }
    //end
    return 0;
}

int dp(int now)
{
    if(sons[now].empty())
        return 1;
    int k = sons[now].size();
    vector<int> d;
    for(int i = 0; i < k; ++i)
        d.push_back(dp(sons[now][i]));
    sort(d.begin(), d.end());
    int all = (k*t-1)/100 + 1;
    int ans = 0;
    for(int i = 0; i < all; ++i)
        ans += d[i];
    return ans;
}
