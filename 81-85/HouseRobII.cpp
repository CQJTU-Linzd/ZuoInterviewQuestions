class HouseRobII {
public:
    int maxValue(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int n = nums.size();
        // 分别在[0...n-2]，[1...n-1]范围上做决策
        vector<int>dp(n);
        int ans = 0;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i <= n - 2; i++) {
            dp[i] = max({ nums[i], dp[i - 1], nums[i] + dp[i - 2] });
        }
        ans = max(ans, dp[n - 2]);
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i <= n - 1; i++) {
            dp[i] = max({ nums[i], dp[i - 1], nums[i] + dp[i - 2] });
        }
        return max(ans, dp[n - 1]);
    }
};
