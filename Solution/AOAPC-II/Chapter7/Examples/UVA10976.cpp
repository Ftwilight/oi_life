#include <cstdio>
#include <vector>
using namespace std;

struct Ans
{
    int x, y;
    Ans(int a, int b):x(a), y(b)
    {}
};

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int k;
    while(scanf("%d", &k) == 1)
    {
        //work
        vector<Ans> ans;
        for(int y = k+1; y <= k*2; ++y)
        {
            if((k*y) % (y - k) == 0)
            {
                int x = (k*y)/(y-k);
                ans.push_back(Ans(x, y));
            }
        }
        //output
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("1/%d = 1/%d + 1/%d\n", k, ans[i].x, ans[i].y);
    }
    //end
    return 0;
}
