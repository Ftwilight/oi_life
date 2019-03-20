#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 1e6+2;
const int INF = 0x3f3f3f3f;

int plan[MAX];

int main()
{
    // freopen("data.in", "r", stdin);
    int n;
    int bottom = INF, top = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        bottom = min(a, bottom);
        top = max(top, b);
        ++plan[a];
        --plan[b];
    }
    int ans_have = 0, ans_no = 0;
    int have_man = 0, no_man = 0;
    int working = 0;
    for(int i = bottom; i <= top; ++i)
    {
        working += plan[i];
        if(working)
        {
            ans_no = max(ans_no, no_man);
            no_man = 0;
            ++have_man;
        }
        else
        {
            ans_have = max(ans_have, have_man);
            have_man = 0;
            ++no_man;
        }
    }
    printf("%d %d", ans_have, ans_no);
    return 0;
}
