// https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        
        int r = v.size();
        int c = v[0].size();

        if(r == 1 && c == 1) return v[0][0];

        vector<vector<int>> dp(r + 1, vector<int>(c + 1));

        dp[0][0] = v[0][0];

        for(int j = 1; j < c; ++j)
        {
            dp[0][j] = dp[0][j - 1] + v[0][j];
        }

        for(int i = 1; i < r; ++i)
        {
            dp[i][0] = dp[i - 1][0] + v[i][0];
        }

        for(int i = 1; i < r; ++i)
        {
            for(int j = 1; j < c; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
            }
        }
        return dp[r - 1][c - 1];
    }
};