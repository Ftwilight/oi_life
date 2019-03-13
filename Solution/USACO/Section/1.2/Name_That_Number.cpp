#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dict[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9, -1, 0, 0};

int main()
{
    // freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    string num, t;
    vector<string> ans;
    cin >>num;
    while(cin >>t)
        if(t.length() == num.length())
        {
            bool is_ans = true;
            for(int i = 0; i < num.length(); ++i)
                if(dict[t[i]-'A'] != num[i]-'0')
                {
                    is_ans = false;
                    break;
                }
            if(is_ans)
                ans.push_back(t);
        }
    if(ans.size())
    {
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)
            cout <<ans[i] <<"\n";
    }
    else
    {
        cout <<"NONE";
    }
    return 0;
}
