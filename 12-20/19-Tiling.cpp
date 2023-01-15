// 铺砖
class Tiling {
public:
    // dp[i]: 一行的长度为i时，有几种摆法
    vector<int> OneRowWays(int n) {
        // 物品：1 2 3 4 拼出n
        vector<int>dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= 4; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }
        return dp;
    }
    int ways(int n, int m) {
        // len[i]: 只有一行的情况下，该行的长度为i时，有几种摆法
        vector<int>len = OneRowWays(m);
        // any[i]: 有n行的情况下，每一行的长度为i时，该n * i的区域有几种摆法
        vector<int>any(m + 1);
        for (int i = 1; i <= m; i++) {
            any[i] = pow(len[i], n);
        }
        // solid[i]: 有n行的情况下，每一行的长度为i时，该n * i的区域有几种合法的摆法
        vector<int>solid(m + 1);
        solid[1] = 1;
        for (int i = 2; i <= m; i++) {
            int inValid = 0;
            for (int j = 1; j < i; j++) { // 枚举贯穿线
                inValid += solid[j] * any[i - j];
            }
            solid[i] = any[i] - inValid;
        }
        return solid[m];
    }
};
