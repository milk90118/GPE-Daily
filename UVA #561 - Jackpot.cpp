#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) return 0;

        vector<int> v(n);

        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        vector<int> dp(n + 1);

        dp[0]= v[0];

        int maxSum = dp[0];

        for(int i = 1; i < n; ++i)
        {
            dp[i] = max(dp[i - 1] + v[i], v[i]);
            maxSum = max(maxSum, dp[i]);
        }

        if(maxSum <= 0) cout << "Losing streak.\n";
        else cout << "The maximum winning streak is " << maxSum << "." << endl;

    }

    return 0;

}   