// m个苹果和n个盘子有多少种放置方法
class PutWays {
public:
    int ways(int apples, int plates) {
        return process(1, apples, plates);
    }
    // pre: 上一个盘子分到的苹果数量， 当前盘子分到的数量不能小于pre
    // apples: 剩余的苹果数量
    // plates: 剩余的盘子数量
    // 返回，在盘子够用的情况下，把苹果分完，有几种方法
    int process(int pre, int apples, int plates) {
        if (apples == 0) {
            return 1;
        }
        if (plates == 0) {
            return 0;
        }
        if (pre > apples) {
            return 0;
        }
        int ways = 0;
        for (int cur = pre; cur <= apples; cur++) {
            ways += process(cur, apples - cur, plates - 1);
        }
        return ways;
    }
    int ways2(int apples, int plates) {
        return process2(apples, plates);
    }
    // 样本对应模型
    int process2(int apples, int plates) {
        if (apples == 0) {
            return 1;
        }
        if (plates == 0) {
            return 0;
        }
        if (plates > apples) {
            return process2(apples, apples);
        } else { // apples >= plates
            int p1 = process2(apples - plates, plates); // 所有盘子全用
            int p2 = process2(apples, plates - 1); // 盘子不全用
            return p1 + p2;
        }
    }
    // 动态规划
    int way3(int apples, int plates) {
        vector<vector<int>>dp(apples + 1, vector<int>(plates + 1));
        for (int j = 0; j < dp[0].size(); j++) {
            dp[0][j] = 1;
        }
        for (int apples = 1; apples < dp.size(); apples++) {
            for (int plates = 1; plates < dp[apples].size(); plates++) {
                if (plates > apples) {
                    dp[apples][plates] = dp[apples][apples];
                } else {
                    dp[apples][plates] = dp[apples - plates][plates] + dp[apples][plates - 1];
                }
            }
        }
        return dp[apples][plates];
    }
};
