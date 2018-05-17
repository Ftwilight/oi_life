#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

map<string, int> cnt;
vector<string> word;

string norm(const string aim);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    string t;
    while(cin >>t && t != "#")
    {
        word.push_back(t);
        string a = norm(t);
        if(!cnt.count(a))
            cnt[a] = 0;
        ++cnt[a];
    }
    //work
    vector<string> ans;
    for(int i = 0; i < word.size(); ++i)
        if(cnt[norm(word[i])] == 1)
            ans.push_back(word[i]);
    sort(ans.begin(), ans.end());
    //output
    for(int i = 0; i < ans.size(); ++i)
        cout <<ans[i] <<"\n";
    //end
    return 0;
}

string norm(string aim)
{
    for(int i = 0; i < aim.length(); ++i)
        aim[i] = tolower(aim[i]);
    sort(aim.begin(), aim.end());
    return aim;
}
