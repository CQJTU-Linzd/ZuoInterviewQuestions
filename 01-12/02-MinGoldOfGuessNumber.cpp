// 猜数字 确保获胜的最少钱数
class MinGold {
public:
    // 正确答案在1~n之间
    int minGold(int n) {
        return process(1, n);
    }
    // 正确答案一定在L~R之间
    // 返回，永远最倒霉的情况下猜中这个数字所需要的最少钱数
    int process(int L, int R) {
        if (L == R) {
            return 0;
        }
        if (R - L == 1) {
            return L; // 猜L这个数，猜错了花费更少
        }
        int ans = INT_MAX;
        // 猜L，猜错
        int p1 = L + process(L + 1, R);
        // 猜R，猜错
        int p2 = R + process(L, R - 1);
        ans = min(p1, p2);
        // (L...R)之间猜，每一个都试
        for (int i = L + 1; i < R; i++) {
            int left = process(L, i - 1); // 往左边猜的最少代价
            int right = process(i + 1, R); // 往右边猜的最少代价
            int cur = i + max(left, right);
            ans = min(ans, cur);
        }
        return ans;
    }
    // 动态规划
    int minGoldDP(int n) {
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            dp[i - 1][i] = i - 1;
        }
        for (int L = n - 2; L >= 1; L--) {
            for (int R = L + 2; R <= n; R++) {
                int p1 = L + dp[L + 1][R];
                int p2 = R + dp[L][R - 1];
                dp[L][R] = min(p1, p2);
                for (int i = L + 1; i < R; i++) {
                    int cur = i + max(dp[L][i - 1], dp[i + 1][R]);
                    dp[L][R] = min(dp[L][R], cur);
                }
            }
        }
        return dp[1][n];
    }
};
