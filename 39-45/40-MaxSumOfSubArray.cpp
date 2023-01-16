// 40 子数组的最大累加和
class MaxSumOfSubArray {
public:
    int maxSum(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
