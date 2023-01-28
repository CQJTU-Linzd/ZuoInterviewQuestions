// 64 相邻K个石子最终合并成一堆的最小代价
class MinCostOfMergeStones {
public:
    int minCost(vector<int>& stones, int k) {
        vector<int>preSum(stones.size() + 1);
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + stones[i - 1];
        }
        return f(stones, k, preSum, 0, stones.size() - 1, 1);
    }
    // [L...R]范围上，整出P份，最小代价是多少
    int f(vector<int>& stones, int k, vector<int>& preSum, int L, int R, int p) {
        if (L == R) {
            return p == 1 ? 0 : -1;
        }
        if (p == 1) {
            int next = f(stones, k, preSum, L, R, k);
            if (next == -1) {
                return -1;
            } else {
                return next + preSum[R + 1] - preSum[L];
            }
        } else {
            int ans = INT_MAX;
            // [L...i]分成1份，[i + 1...R]生成P-1份
            for (int i = L; i < R; i++) {
                int left = f(stones, k, preSum, L, i, 1);
                int right = f(stones, k, preSum, i + 1, R, p - 1);
                if (left != -1 && right != -1) {
                    ans = min(ans, left + right);
                }
            }
            return ans;
        }
    }
};
