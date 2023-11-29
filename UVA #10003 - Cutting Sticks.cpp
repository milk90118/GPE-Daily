#include <iostream>
using namespace std;

const int MAX = 55, INF = 0x3f3f3f3f;
int cut[MAX], dp[MAX][MAX];

int main() {

    int len;
    while (cin >> len && len) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) cin >> cut[i];

        cut[0] = 0; cut[n + 1] = len;

        for (int i = 0; i <= n; ++i) dp[i][i + 1] = 0;

        for (int slice = 2; slice <= n + 1; ++slice) {

            for (int start = 0, end = start + slice; end <= n + 1; ++start, ++end) {

                dp[start][end] = INF;

                for (int k = start + 1; k < end; ++k)

                    dp[start][end] = min(dp[start][end], dp[start][k] + dp[k][end] + cut[end] - cut[start]);
            }
        }

        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
    return 0;
}
