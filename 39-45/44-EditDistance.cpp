// 编辑距离
class EditDistance {
public:
    int minCost(string s1, string s2, int del, int add, int rep) {
        int n = s1.size();
        int m = s2.size();
        // dp[i][j]: s1的前i个字符，编辑出s2的前j个字符，最少代价是多少
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[0][i] = i * add;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i * del;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + rep;
                }
                dp[i][j] = min(dp[i][j - 1] + add, dp[i - 1][j] + del);
            }
        }
        return dp[n][m];
    }
};
