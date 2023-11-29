#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    while(cin >> n)
    {
        int m;
        cin >> m;

        vector<int> take(m);

        for(int i = 0; i < m; ++i) cin >> take[i];

        vector<bool> dp(n + 1);

        for(int coin = 1; coin <= n; ++coin)
        {
            for(auto& num : take)
            {
                if(coin - num >= 0 && !dp[coin - num])
                {
                    dp[coin] = true;
                    break;
                }
            }
        }

        if(dp[n]) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
    return 0;
}