#include <iostream>
using namespace std;

const int N = 105;
long long dp[N][2];

int main() {
    int n, k = 0;
    while (cin >> n) {
        long long ans = -1e18;
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            dp[i][0] = min(dp[i - 1][0] * a, min(dp[i - 1][1] * a, a));
            dp[i][1] = max(dp[i - 1][0] * a, max(dp[i - 1][1] * a, a));
            ans = max(ans, dp[i][1]);
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++k, (ans > 0 ? ans : 0));
    }
    return 0;
}