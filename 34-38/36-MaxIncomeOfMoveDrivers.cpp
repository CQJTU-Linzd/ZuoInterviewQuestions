//  36. 将所有司机调到A，B两个区域使总收入最高的方案是多少钱
class MoveDriversToAB {
public:
    // 司机人数为2*n，A和B各需要n名司机
    int maxIncome(int n, vector<vector<int>>& income) {
        return process(income, 0, n);
    }
    // A区域还有rest个名额
    int process(vector<vector<int>>& income, int index, int rest) {
        if (index == income.size()) {
            return 0;
        }
        if (rest == 0) {
            return income[index][1] + process(income, index + 1, rest);
        } else if (income.size() - index == rest) {
            return income[index][0] + process(income, index + 1, rest - 1);
        }
        // 司机可以去A，也可以去B
        int p1 = income[index][0] + process(income, index + 1, rest - 1);
        int p2 = income[index][1] + process(income, index + 1, rest);
        return max(p1, p2);
    }
    // dp
    int maxIncomedp(int n, vector<vector<int>>& income) {
        vector<vector<int>>dp(income.size() + 1, vector<int>(n + 1));
        for (int j = 0; j < dp[0].size(); j++) {
            dp[income.size()][j] = 0;
        }
        for (int index = income.size() - 1; index >= 0; index--) {
            for (int rest = 0; rest <= n; rest++) {
                if (rest == 0) {
                    dp[index][rest] = income[index][1] + dp[index + 1][rest];
                } else if (income.size() - index == rest) {
                    dp[index][rest] = income[index][0] + dp[index + 1][rest - 1];
                } else {
                    int p1 = income[index][0] + dp[index + 1][rest - 1];
                    int p2 = income[index][1] + dp[index + 1][rest];
                    dp[index][rest] = max(p1, p2);
                }
            }
        }
        return dp[0][n];
    }
};
