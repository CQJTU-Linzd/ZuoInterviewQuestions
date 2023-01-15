// 执行m步操作后返回最大分数
class MaxScore {
public:
    int maxScore(vector<int>& nums, vector<int>& multiple, int m) {
        return process(nums, multiple, 0, nums.size() - 1, 0);
    }
    // 在nums[left...right]选nums[left]或nums[right]，乘以multiple[i]
    // multiple数组消耗完之前，nums不会消耗完
    // 直到把multiple数组消耗完，返回最大分数
    int process(vector<int>& nums, vector<int>& multiple, int left, int right, int i) {
        if (i == multiple.size()) {
            return 0;
        }
        // 没消耗完
        if (left == right) {
            return nums[left] * multiple[i];
        }
        int p1 = nums[left] * multiple[i] + process(nums, multiple, left + 1, right, i + 1);
        int p2 = nums[right] * multiple[i] + process(nums, multiple, left, right - 1, i + 1);
        return max(p1, p2);
    }
    // 优化 降到二维
    int process(vector<int>& nums, vector<int>& multiple, int left, int right) {
        // 根据nums左边消耗掉的数量和右边消耗掉的数量，可以推出multiple此时的下标，可以省去形参i
        int leftAlready = left;
        int rightAlready = nums.size() - right - 1;
        int i = leftAlready + rightAlready; 
        if (i == multiple.size()) {
            return 0;
        }
        // 没消耗完
        if (left == right) {
            return nums[left] * multiple[i];
        }
        int p1 = nums[left] * multiple[i] + process(nums, multiple, left + 1, right);
        int p2 = nums[right] * multiple[i] + process(nums, multiple, left, right - 1);
        return max(p1, p2);
    }
    // 三维dp
    int maxScore2(vector<int>& nums, vector<int>& multiple) {
        int n = nums.size();
        int m = multiple.size();
        vector<vector<int>>s(n, vector<int>(n)); // 一个面
        vector<vector<vector<int>>>dp(multiple.size() + 1, s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][m] = 0;
            }
        }
        for (int h = 0; h <= m; h++) {
            for (int i = 0; i < n; i++) {
                dp[i][i][h] = nums[i] * multiple[h];
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int left = n - 2; left >= 0; left--) {
                for (int right = left + 1; right < n; right++) {
                    int p1 = nums[left] * multiple[i] + dp[left + 1][right][i + 1];
                    int p2 = nums[right] * multiple[i] + dp[left][right - 1][i + 1];
                    dp[left][right][i] = max(p1, p2);
                }
            }
        }
        return dp[0][n - 1][0];
    }
};
