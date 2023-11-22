#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int N = 305;
long long dp[N][N];

void DP()
{
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int k = 1; k <= 300; ++k) // value of the coin
    {
        for(int i = k; i <= 300; ++i) // total amount of money
        {
            for(int j = 1; j <= 300; ++j) // number of coins

                dp[i][j] += dp[i - k][j - 1];
        }
    }
}

int main()
{
    DP();

    int n, a, b;
    char str[N];

    while(gets(str))
    {
        int ca = sscanf(str, "%d%d%d", &n, &a, &b);

        long long ans = 0;

        if(a > 300) a = 300;
        if(b > 300) b = 300;

        if(ca == 1)
        {
            for(int i = 0; i <= n; ++i) ans += dp[n][i];
        }

        else if(ca == 2)
        {
            for(int i = 0; i <= a; ++i) ans += dp[n][i];
        }

        else if(ca == 3)
        {
            for(int i = a; i <= b; ++i) ans += dp[n][i];
        }

        printf("%lld\n", ans);
    }
    return 0;
}