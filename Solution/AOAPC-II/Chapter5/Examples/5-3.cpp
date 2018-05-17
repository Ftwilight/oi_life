#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 5005;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    string ori;
    string t;
    while(cin >> t)
        ori += t + " ";
    //process
    for(int i = 0; i < ori.length(); ++i)
        if(isalpha(ori[i]))
            ori[i] = tolower(ori[i]);
        else
            ori[i] = ' ';
    //work
    set<string> dict;
    stringstream s(ori);
    while(s >> t)
        dict.insert(t);
    //output
    for(set<string>::iterator i = dict.begin(); i != dict.end(); ++i)
        cout <<*i <<"\n";
    //end
    return 0;
}
