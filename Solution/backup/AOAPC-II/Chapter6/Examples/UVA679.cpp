#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    scanf("%d", &n);
    for(int t = 0; t < n; ++t)
    {
        int d, i;
        scanf("%d %d", &d, &i);
        //work
        int k = 1;
        for(int h = 0; h < d - 1; ++h)
            if(i % 2)
            {
                k *= 2;
                i = (i + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                i /= 2;
            }
        //output
        printf("%d\n", k);
    }
    //end
    return 0;
}
