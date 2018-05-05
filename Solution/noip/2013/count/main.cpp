#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main
{
    stringstream num;
    int n;
    char x;
    cin >>n >>x;
    for(int i = 1; i <= n; ++i)
        num <<i;
    string temp = num.str();
    cout <<count(temp.begin(), temp.end(), x);
    return 0;
}
