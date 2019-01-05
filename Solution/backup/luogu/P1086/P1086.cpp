#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct peanut{
    int num;
    int x;
    int y;
    int back;
    bool operator<(peanut &other)
    {
        return num < other.num;
    }
};
peanut peanuts[21][21];
vector<peanut> need;
int m, n, time;

int get_dis(peanut &a, peanut &b);

int main()
{
    //input
    cin >>m >>n >>time;
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        {
            //input and process the data
            peanut &aim = peanuts[i][j];
            cin >>aim.num;
            aim.x = i;
            aim.y = j;
            if(aim.num)
            {
                aim.back = aim.x;
                need.push_back(aim);
            }
        }
    sort(need.rbegin(), need.rend());
    //work
    int result = 0;
    if(need[0].back * 2 + 1 <= time)
    {
        time -= need[0].back+1;
        result += need[0].num;
        for(int i=1; i<need.size(); ++i)
        {
            peanut &now = need[i-1];
            peanut &pick = need[i];
            int dis = get_dis(now, pick);
            int back = now.back;
            int next = dis + pick.back + 1;
            if(time >= next)
            {
                result += pick.num;
                time -= dis+1;
            }
            else
                break;
        }
    }
    cout <<result;
    return 0;
}

int get_dis(peanut &a, peanut &b)
{
    int x_dis = abs(a.x - b.x);
    int y_dis = abs(a.y - b.y);
    return (x_dis + y_dis);
}
