#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 21;

int result = 0;
int n;
string words[MAX], head;
int flag[MAX];

void dfs(string now);
int judge(string now, string next);

int main()
{
    //input
    cin >>n;
    for(int i=0; i<n; ++i)
        cin >>words[i];
    cin >>head;
    //work
    dfs("_"+head);
    //output
    cout <<result-1;
    return 0;
}

void dfs(string now)
{
    cout <<now <<"\n";
    for(int i=0; i<n; ++i)
        if(flag[i] < 2)
        {
            string next = words[i];
            int same = judge(now, next);
            if(same)
            {
                ++flag[i];
                string add = next.substr(same, string::npos);
                string new_str = now + add;
                result = max(result, static_cast<int>(new_str.size()));
                dfs(new_str);
                --flag[i];
            }
        }
}

int judge(string now, string next)
{
    for(int i=0; i<min(static_cast<int>(now.size())-1, static_cast<int>(next.size())-1 ); ++i)
    {
        string now_cutter = now.substr(now.size()-1-i, string::npos);
        string next_cutter = next.substr(0, i+1);
        if(now_cutter == next_cutter)
            return i+1;
    }
    return 0;
}
