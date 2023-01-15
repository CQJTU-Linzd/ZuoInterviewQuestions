// 交换元素使数组有序
class ExchangetoSorted {
public:
    bool canSorted(vector<int>& A, vector<int>& B) {
        return process(A, B, 0, INT_MIN);
    }
    // 下标来到index位置，保证A[0...index - 1]有序
    // A[index...]能否保证有序
    // pre: index的前一个数是啥
    bool process(vector<int>& A, vector<int>& B, int index, int pre) {
        if (index == A.size()) {
            return true;
        }
        // 不交换 A[index]
        bool p1 = pre > A[index] ? false : process(A, B, index + 1, A[index]);
        // 交换 B[index]
        bool p2 = pre > B[index] ? false : process(A, B, index + 1, B[index]);
        return p1 || p2;
    }
    // 优化
    bool canSorted2(vector<int>& A, vector<int>& B) {
        if (A.size() <= 1) return true;
        return process2(A, B, 1, true) || process2(A, B, 1, false);
    }
    bool process2(vector<int>& A, vector<int>& B, int index, bool swaped) {
        if (index == A.size()) {
            return true;
        }
        int pre = swaped ? B[index - 1] : A[index - 1];
        // 不交换 A[index]
        bool p1 = pre > A[index] ? false : process2(A, B, index + 1, false);
        // 交换 B[index]
        bool p2 = pre > B[index] ? false : process2(A, B, index + 1, true);
        return p1 || p2;
    }
    // dp
    bool canSorted2dp(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(2));
        dp[0][0] = true;
        dp[0][1] = true;
        dp[n][0] = true;
        dp[n][1] = true;
        for (int index = n - 1; index >= 1; index--) {
            for (int swaped = 0; swaped < 2; swaped++) {
                int pre = swaped ? B[index - 1] : A[index - 1];
                bool p1 = pre > A[index] ? false : dp[index + 1][0];
                bool p2 = pre > B[index] ? false : dp[index + 1][1];
                dp[index][swaped] = p1 || p2;
            }
        }
        return dp[1][0] || dp[1][1];
    }
};
