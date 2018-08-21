#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MAX = 205;

vector<int> sons[MAX];
int n, d[MAX][2];
bool only[MAX][2];
map<string, int> dict;
int cnt;

inline int id(string &name);
inline void init();
int dp(int k, int s);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(cin >>n && n)
    {
        init();
        string staff, boss;
        cin >>boss;
        id(boss);
        for(int i = 1; i < n; ++i)
        {
            cin >>staff >>boss;
            sons[id(boss)].push_back(id(staff));
        }
        //work && output
        printf("%d ", max(dp(0, 0), dp(0, 1)));
        if((d[0][0] > d[0][1] && only[0][0]) || (d[0][1] > d[0][0] && only[0][1]))
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }
    //end
    return 0;
}

inline void init()
{
    cnt = 0;
    dict.clear();
    for(int i = 0; i < n; ++i)
        sons[i].clear();
}

inline int id(string &name)
{
    if(dict.count(name))
        return dict[name];
    else
        return dict[name] = cnt++;
}

int dp(int k, int s)
{
    d[k][s] = s;
    only[k][s] = true;
    
    for(int i = 0; i < sons[k].size(); ++i)
    {
        int v = sons[k][i];
        if(s)
        {
            d[k][1] += dp(v, 0);
            if(!only[v][0])
                only[k][1] = false;
        }
        else
        {
            d[k][0] += max(dp(v, 0), dp(v, 1));
            if(d[v][0] > d[v][1] && !only[v][0])
                only[k][0] = false;
            else if(d[v][1] > d[v][0] && !only[v][1])
                only[k][0] = false;
            else if(d[v][1] == d[v][0])
                only[k][0] = false;
        }
    }
    return d[k][s];
}
