#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);

        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
            v[i] = abs(v[i] % k);
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[0][0] = 1;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                if(dp[i][j])
                {
                    dp[i + 1][(j + k + v[i]) % k] = 1;
                    dp[i + 1][(j + k - v[i]) % k] = 1; 
                }
            }
        }

        if(dp[n][0]) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
    return 0;
}